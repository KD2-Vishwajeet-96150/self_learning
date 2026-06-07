using Food_Ordering.DTOs;
using Food_Ordering.Models;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Cors;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Microsoft.IdentityModel.Tokens;
using System.IdentityModel.Tokens.Jwt;
using System.Security.Claims;
using System.Text;

namespace FoodOrdering.Controllers
{
    [ApiController]
    [Route("user")]
    [EnableCors("ReactPolicy")]
    public class AuthController : ControllerBase
    {
        private readonly AppDbContext _context;
        private readonly IConfiguration _configuration;

        public AuthController(AppDbContext context, IConfiguration configuration)
        {
            _context = context;
            _configuration = configuration;
        }

        [AllowAnonymous]
        [HttpPost("signup")]

        public async Task<IActionResult> Signup(RegisterDto dto)
        {
            try
            {
                string hashedPassword = BCrypt.Net.BCrypt.HashPassword(dto.Password);

                var user = new User
                {
                    Name = dto.Name,
                    Email = dto.Email,
                    Password = hashedPassword,
                    Mobile = dto.Mobile,
                };

                _context.Users.Add(user);

                await _context.SaveChangesAsync();

                return Ok(ResultHelper.Success(user));
            }
            catch (Exception ex)
            {

                return BadRequest(
                    ResultHelper.Error<string>(ex.Message));
            }
        }

        [AllowAnonymous]
        [HttpPost("signin")]
        public async Task<IActionResult> Singin(LoginDto dto)
        {
            try
            {
                var dbUser = await _context.Users.FirstOrDefaultAsync(x => x.Email == dto.Email);

                if (dbUser == null)
                {

                    return BadRequest(
                        ResultHelper.Error<string>("Invalid Email"));
                }

                bool isPasswordCorrect = BCrypt.Net.BCrypt.Verify(dto.Password, dbUser.Password);

                if (!isPasswordCorrect)
                {
                    return BadRequest(

                        ResultHelper.Error<string>("Invalid Password"));
                }

                var token = GenerateToken(dbUser);

                var response = new
                {
                    Token = token,
                    Name = dbUser.Name
                };

                return Ok(ResultHelper.Success(response));
            }
            catch (Exception ex)
            {

                return BadRequest(ResultHelper.Error<string>(ex.Message));

            }
        }

        public string GenerateToken(User user)
        {
            var claims = new[]
            {
                new Claim("uid",user.Uid.ToString())
            };

            var key = new SymmetricSecurityKey(

                Encoding.UTF8.GetBytes(_configuration["Jwt:key"])
                );

            var credentials = new SigningCredentials(key, SecurityAlgorithms.HmacSha256);

            var token = new JwtSecurityToken(
                issuer: _configuration["Jwt:Issuer"],
                audience: _configuration["Jwt:Audience"],
                claims: claims,
                expires: DateTime.Now.AddDays(7),
                signingCredentials: credentials);

            return new JwtSecurityTokenHandler().WriteToken(token);
        }

        [Authorize]
        [HttpGet]
        public async Task<IActionResult> GetProfile()
        {
            try
            {
                int uid = Convert.ToInt32(
                    User.FindFirst("uid")?.Value);

                var user = await _context.Users.FirstOrDefaultAsync(x => x.Uid == uid);

                var result = new
                {
                    user.Name,
                    user.Email,
                    user.Mobile
                };

                return Ok(ResultHelper.Success(result));
            }
            catch (Exception ex)
            {
                return BadRequest(ResultHelper.Error<string>(ex.Message));
            }
        }

        [Authorize]
        [HttpPut]

        public async Task<IActionResult> UpdateMobile(UpdateMobileDto dto)
        {
            try
            {
                int uid = Convert.ToInt32(User.FindFirst("uid")?.Value);

                var user = await _context.Users
                    .FirstOrDefaultAsync(x => x.Uid == uid);

                user.Mobile = dto.Mobile;

                await _context.SaveChangesAsync();
                return Ok(ResultHelper.Success(user));
            }
            catch (Exception ex)
            {

                return BadRequest(ResultHelper.Error<string>(ex.Message));
            }
        }

        [Authorize]
        [HttpDelete]

        public async Task<IActionResult> DeleteAccount()
        {
            try
            {
                int uid = Convert.ToInt32(User.FindFirst("uid")?.Value);
                var user = await _context.Users
                           .FirstOrDefaultAsync(x => x.Uid == uid);

                _context.Users.Remove(user);

                await _context.SaveChangesAsync();

                return Ok(ResultHelper.Success("Account Deleted"));

            }
            catch (Exception ex)
            {
                return BadRequest(ResultHelper.Error<string>(ex.Message));
            }
        }

    }
}