
Il carrello della spesa- The shopping cart


# Online Shopping Cart System

## **Overview**
This project is an Online Shopping Cart System designed to manage user interactions with products, carts, and orders. It implements core features such as user authentication, product management, order processing, and more.

The system is implemented in C++ and includes Object-Oriented Programming (OOP) principles such as inheritance, polymorphism, and dynamic memory management.

---

## **Features**
1. **User Authentication**: Sign-up, login, logout, and profile management.
2. **Product Management**: Add, update, delete, and search for products.
3. **Shopping Cart**: Add products to the cart, remove them, view the cart, and calculate totals.
4. **Order Management**: Place orders, view order history, and track order status.
5. **Payment System**: Simulate payment methods (e.g., credit card and Apple Pay).
6. **Admin Panel**: Manage products, view sales reports, and handle customer queries.
7. **Recommendations**: Dynamic product recommendations based on cart content.
8. **Notifications**: Users and admins receive system notifications for actions.

---

## **File Initialization**
The system loads its data from three key files:
1. **`data/products.csv`**: Contains product information (ID, name, category, price, quantity).
2. **`data/orders.csv`**: Stores order data (order ID, user ID, product ID, quantity, total).
3. **`data/users.csv`**: Manages user data (user ID, username, password).

---

## **Compilation Instructions**
### Prerequisites
Ensure the following tools are installed:
- **C++ Compiler** (e.g., `g++`)
- **CMake** (for project building)
- **Make**

### Steps to Build
1. Clone the repository:
   ```bash
   git clone https://github.com/your-repo/OnlineShoppingCart.git
   cd OnlineShoppingCart


**Build  Instructions**

**Prerequisites

- C++ Compiler: GCC or Clang

- CMake: Version 3.10 or higher.

- Git: for version control.

- Clone the repository:
 -- git clone https://github.com/your-repo/OnlineShoppingSystem.git
cd OnlineShoppingSystem

**Create a build directory and run CMake:

mkdir build
cd build
cmake ..
make

Run the program:
./OnlineShoppingSystem

-UML Diagram:

**The following diagram represents the class structure and relationships within the Online Shopping System
classDiagram
    class User {
        +int id
        +string username
        +string password
        +authenticate(password: string): bool
    }

    class Customer {
        +ShoppingCart cart
        +addToCart(product: Product, quantity: int)
        +viewCart()
        +checkout()
    }

    class Admin {
        +addProduct()
        +updateProduct()
        +deleteProduct()
        +generateSalesReport()
    }

    class Product {
        +int id
        +string name
        +string category
        +double price
        +int quantity
        +getId(): int
        +getName(): string
        +getPrice(): double
    }

    class ShoppingCart {
        +addProduct(product: Product, quantity: int)
        +removeProduct(productId: int)
        +viewCart()
        +calculateTotal(): double
        +clearCart()
    }

    class Order {
        +int orderId
        +int userId
        +int productId
        +int quantity
        +double total
    }

    class DatabaseConnection {
        -static DatabaseConnection instance
        +addOrder(order: Order)
        +getOrders(): vector<Order>
        +saveOrdersToFile(filePath: string)
        +loadOrdersFromFile(filePath: string)
    }

    User <|-- Customer
    User <|-- Admin
    Customer --> ShoppingCart
    ShoppingCart --> Product
    Order --> Product
    DatabaseConnection --> Order





Project Status

-Current State: The project is complete with core functionality.

-Known Bugs: None at this time.

-Known Issues:

Recommendation engine lacks dynamic updates.


User Manual

 Customer Operations

-Browse products and add them to the cart.
-View and remove items from the cart.
-Checkout and place orders.


Admin Operations

-Add, update, or delete products.
-Generate and view sales reports
-Handle customer queries






Concepts Covered
-Inheritance
-Polymorphism
-File handling
-Exception handling
-STD (Standard Template Library)

Code Design
The project is structured with classes like User, Product, Inventory, Cart, and Order. It follows object-oriented best practices and uses inheritance, polymorphism to handle different user roles and payment methods.
Here are the design elements:

-Product Class: Represents individual products with details like ID, name, price, and availability.
-Inventory Class: Manages the product cart/catalog and allows adding, updating, deleting and searching for products.
-User Class: A base class for Customer and Admin, supporting role-specific functionalities.
-Payment Class: Uses polymorphism to allow different payment methods.

License

This project is licensed under the MIT License. See the LICENSE file for details.
 
