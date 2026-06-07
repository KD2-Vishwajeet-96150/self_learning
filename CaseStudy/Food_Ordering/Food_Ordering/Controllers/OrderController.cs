using Food_Ordering.DTOs;
using Food_Ordering.Models;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Cors;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace Food_Ordering.Controllers
{

    [Route("order")]
    [ApiController]
    [EnableCors]

    [Authorize]
    public class OrderController : Controller
    {
        private readonly AppDbContext _context;

        public OrderController(AppDbContext context)
        {
            _context = context;
        }
        [HttpPost]

        public async Task<IActionResult> PlaceOrder(
            [FromBody] CreateOrderDto request)
        {
            try
            {
                var uidCliam = User.FindFirst("uid");
                if (uidCliam == null)
                {
                    return Unauthorized(
                        ResultHelper.Error<string>(
                            "User cliam not found"));
                }
                int uid = Convert.ToInt32(uidCliam.Value);

                decimal totalAmount = 0;
                foreach (var item in request.CartItems)
                {
                    var food = await _context.Foods
                        .FirstOrDefaultAsync(f => f.Fid == item.Fid);

                    if (food == null)
                    {
                        return BadRequest(
                            ResultHelper.Error<string>(
                                $"Food Id {item.Fid} not found"));
                    }
                    totalAmount += (decimal)food.Price * item.Qty;
                }
                var order = new Order
                {
                    Uid = uid,
                    Odate = DateTime.Now,
                    TotalAmount = totalAmount
                };
                _context.Orders.Add(order);
                await _context.SaveChangesAsync();

                foreach (var item in request.CartItems)
                {
                    _context.OrderDetails.Add(
                        new OrderDetail
                        {
                            Oid = order.Oid,
                            Fid = item.Fid,
                            Quantity = item.Qty
                        });
                }
                await _context.SaveChangesAsync();

                return Ok(ResultHelper.Success(new
                {
                    order.Oid,
                    order.Odate,
                    order.TotalAmount
                }));
            }
            catch (Exception ex)
            {
                return BadRequest(ResultHelper.Error<string>(
                    ex.InnerException?.Message ?? ex.Message));
            }
                
        }
        [HttpGet]
        public async Task<IActionResult> GetOrders()
        {
            try
            {
                var uidCliam = User.FindFirst("uid");
                if (uidCliam == null)
                {
                    return Unauthorized(
                        ResultHelper.Error<string>(
                            "User Claim not found"));
                }
                var uid = Convert.ToInt32(uidCliam.Value);

                var orders = await _context.Orders
                    .Where(o => o.Uid == uid)
                    .Include(o => o.OrderDetails)
                    .ThenInclude(od => od.FidNavigation)
                    .OrderByDescending(o => o.Odate)
                    .ToListAsync();

                return Ok(ResultHelper.Success(orders));
            }
            catch (Exception ex)
            {
                return BadRequest(
                    ResultHelper.Error<string>(ex.Message));
            }
        }
    }
}
