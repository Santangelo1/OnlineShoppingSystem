#ifndef SALES_ANALYTICS_H
#define SALES_ANALYTICS_H

#include "Order.h"
#include <vector>
#include <map>
#include <string>

class SalesAnalytics {
private:
    std::vector<Order> salesData;   // Stores all completed orders
    std::map<int, int> productSalesCount; // Tracks the number of sales per product (product_id -> quantity sold)
    double totalRevenue;            // Total revenue from all sales

public:
    // Constructor
    SalesAnalytics();

    // Record a completed sale (adds order to salesData and updates analytics)
    void recordSale(const Order& order);

    // Sales Reporting
    int getTotalOrders() const;                      // Get the total number of orders
    double getTotalRevenue() const;                  // Get the total revenue
    std::vector<int> getTopSellingProducts(int topN) const; // Get top N selling products
    double calculateAverageOrderValue() const;       // Calculate the average value of an order

    // Time-Based Analytics (assumes order dates are strings in "YYYY-MM-DD" format)
    int getMonthlySales(const std::string& month);   // Get sales for a specific month (e.g., "2023-11")
    int getYearlySales(const std::string& year);     // Get sales for a specific year (e.g., "2023")

    // Display Reports
    void displaySalesSummary() const;                // Display a summary of sales data
    void displayProductSalesReport() const;          // Display report for each product's sales

    // Destructor
    ~SalesAnalytics();
};

#endif // SALES_ANALYTICS_H