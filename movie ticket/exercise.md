### Exercise: Movie Ticket Management System

Create a program that manages different types of movie tickets. There are two types of tickets: Regular and VIP. Each ticket has a movie name, a base price, and specific attributes depending on the ticket type.

1. **Regular Ticket**:
   - Has an additional attribute for the seat number.
   - If the seat number is in the first 10 rows, the price is increased by 20%.
   - Otherwise, the base price is used.

2. **VIP Ticket**:
   - Has an additional attribute for the lounge access (boolean: true or false).
   - If lounge access is true, the price is increased by 50%.
   - Otherwise, the base price is used.

### Requirements:
1. Create a `Ticket` base class with the necessary attributes and methods.
2. Create derived classes `RegularTicket` and `VIPTicket`.
3. Implement a `TicketManager` class to manage the collection of tickets.
4. Implement methods to add tickets, display tickets, and calculate total sales.

### Sample Output:
```
Enter the number of tickets to add: 2
Enter details for ticket 1
Enter movie name: Avengers
Enter base price: 10
Enter ticket type (1 for Regular, 2 for VIP): 1
Enter seat number: 5
Enter details for ticket 2
Enter movie name: Inception
Enter base price: 20
Enter ticket type (1 for Regular, 2 for VIP): 2
Enter lounge access (1 for Yes, 0 for No): 1

Ticket: Avengers | Base price: 10 | Seat number: 5 | Final price: 12
Ticket: Inception | Base price: 20 | Lounge access: Yes | Final price: 30
Total Sales: 42
```
