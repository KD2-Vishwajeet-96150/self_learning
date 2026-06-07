namespace Food_Ordering.DTOs
{
    public class CreateOrderDto
    {
        public decimal TotalAmount { get; set; }
        public List<CartItemDto> CartItems { get; set; }
    }
}
