# OnlineShoppingManagementSystem

Il carrello della spesa- The shopping cart

## Project Overview

This project is an online shopping cart application that allows users with the ability to browse products, manage a shopping cart, place orders, and simulate a payment system. The system also includes an admin panel that enables inventory management, sales tracking, and customer support functionality.

## Key Features

### Core Features

- **User Authentication**: Supports sign-up, login, logout, and profile management for users.
  
- **Product Catalog**: Allows users to view, search, and sort through available products.
- 
- **Shopping Cart**: Users can add products to their cart, update quantities, and proceed to checkout.
- 
- **Order Management**: Users can view order history, track order status, and admins can view all orders.
- 
- **Payment Integration**: Simulates payment processing with options for different payment methods.
- 
- **Admin Panel**: Admins can manage products, view detailed sales reports, and handle customer queries.

### Innovative Features

The Online Shopping Cart System includes several innovative features that enhance functionality and user experience.

1. **Dynamic Recommendations Engine**
   - **Description**: Provides product recommendations to users based on items in their cart or purchase history.
   - **How it Works**: The system suggests related products or items commonly bought together, encouraging users to explore more products and increase cart size.
   - **Benefits**: Increases user engagement and drives additional sales through personalized recommendations.

2. **Real-Time Inventory Notifications**
   - **Description**: Notifies users when products they are interested in are back in stock or running low.
   - **How it Works**: Users can subscribe to stock alerts for specific products, and the system sends notifications when those items are available or in limited stock.
   - **Benefits**: Helps customers secure desired items and reduces the chance of abandoned purchases due to stock issues.

3. **Advanced Sales Analytics in Admin Panel**
   - **Description**: Provides detailed analytics for the admin, including popular products, sales trends, and customer behavior.
   - **How it Works**: The admin panel includes dashboards showing total sales, most popular items, low stock alerts, and revenue metrics.
   - **Benefits**: Empowers admins with insights into sales patterns and stock requirements, improving inventory management and decision-making.

4. **AI-Driven Search and Filter Options**
   - **Description**: Enhances the product search function by allowing flexible searches that interpret synonyms and related terms.
   - **How it Works**: Uses a simple search algorithm that recognizes related keywords and common product terms, returning relevant results even for partial matches or misspellings.
   - **Benefits**: Helps users find products quickly and efficiently, enhancing the overall shopping experience.

5. **Abandoned Cart Recovery Feature**
   - **Description**: Detects when users leave items in their cart without checking out and sends reminders or discount offers.
   - **How it Works**: Tracks inactive carts and prompts users via email or notification to complete their purchase, sometimes with limited-time discount offers.
   - **Benefits**: Increases conversion rates by reminding users about items they were interested in, reducing the number of abandoned carts.

6. **Admin-Controlled Flash Sales and Discounts**
   - **Description**: Allows admins to create time-limited sales on specific products, visible only during the sale period.
   - **How it Works**: Admins can set up discounts with start and end times, and discounted prices are displayed to users during the flash sale period.
   - **Benefits**: Drives immediate purchases and helps clear out excess inventory.
  
-File Initialization
The system initializes with data from three files:

- products.csv :Contains product inventory data.

- users.csv   : Contains user account information.

Compilation Instructions

1. Ensure you have a C++ compiler(such as g++) installed.
2. 
3. To compile the project, run the following command in the terminal:
4. 
   g++ -o shopping_cart main.cpp Product.cpp Inventory.cpp User.cpp Cart.cpp Order.cpp Payment.cpp -std=c++11

Execution Instructions

To run the project:

1. Place products.csv, users.csv, and orders.csv in same directory as the executable.
2. 
3. Execute the program with the following command:
4. 
   ./shopping_cart
5. Follow on-screen prompts to interact with the application.

Project Status

-Current State: The project is complete with core functionality.

-Known Bugs: None at this time.

-Incomplete Features: None

User Manual

1. Customer Features:

- Login to view the product catalog and add items to cart.
- Product catalog: add, update, delete, and search for products.
- Shopping Cart: Add to cart, remove from cart, and view cart.
- Order Management: Place an order, view order history, and track order status.
- Payment Integration: Simulate a payment system.

For Admins
-Manage Inventory: Add, update, or delete products in the cart.
-View Analytics: Access sale trends, most popular items, and low stock alerts.
-Flash Sales: Set-up time limited discounts on selected products.

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

UML Diagrams

The following UML Diagrams illustrate the structure and relationships between classes.

classDiagram
    class User {
        +string username
        +string password
        +displayRole()
        #authenticate()
        (abstract)
    }
    User <|-- Customer
    User <|-- Admin

    class Customer {
        +addToCart(Product product)
        +checkout()
    }

    class Admin {
        +manageInventory()
        +generateReport()
    }

    class Product {
        +int id
        +string name
        +double price
        +bool isAvailable
    }

    class Cart {
        +addProduct(Product product)
        +removeProduct(Product product)
        +viewCart()
    }

    class Order {
        +int orderId
        +User user
        +Product product
        +int quantity
        +string status
    }

    class Inventory {
        +addProduct(Product product)
        +deleteProduct(int id)
        +listProducts()
    }

    User <-- Cart : owns
    User <-- Order : places
    Product <-- Inventory : contains
    Cart "1" -- "0..*" Product : contains
    Order "1" -- "1" Product : contains
