#include "SalesAnalytics.h"
#include <algorithm>
#include <iostream>
#include <iomanip>

// Constructor
SalesAnalytics::SalesAnalytics() : totalRevenue(0.0) {}

// Record a completed sale
void SalesAnalytics::recordSale(const Order& order) {
    salesData.push_back(order);
    totalRevenue += order.getTotalAmount();

    for (const std::pair<Product, int>& item : order.getItems()) {  // Assuming `Order` has a method `getItems()`
        productSalesCount[item.first.getId()] += item.second;
    }
}

// Get total orders
int SalesAnalytics::getTotalOrders() const {
    return salesData.size();
}

// Get total revenue
double SalesAnalytics::getTotalRevenue() const {
    return totalRevenue;
}

// Calculate average order value
double SalesAnalytics::calculateAverageOrderValue() const {
    if (salesData.empty()) return 0.0;
    return totalRevenue / salesData.size();
}

// Get top N selling products
std::vector<int> SalesAnalytics::getTopSellingProducts(int topN) const {
    std::vector<std::pair<int, int>> sortedProducts(productSalesCount.begin(), productSalesCount.end());
    std::sort(sortedProducts.begin(), sortedProducts.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;  // Sort by quantity sold in descending order
    });

    std::vector<int> topProducts;
    for (int i = 0; i < topN && i < sortedProducts.size(); ++i) {
        topProducts.push_back(sortedProducts[i].first);
    }
    return topProducts;
}

// Display sales summary
void SalesAnalytics::displaySalesSummary() const {
    std::cout << "Total Orders: " << getTotalOrders() << "\n"
              << "Total Revenue: $" << std::fixed << std::setprecision(2) << totalRevenue << "\n"
              << "Average Order Value: $" << calculateAverageOrderValue() << "\n";
}

// Display product sales report
void SalesAnalytics::displayProductSalesReport() const {
    std::cout << "Product Sales Report:\n";
    for (const auto& entry : productSalesCount) {
        std::cout << "Product ID: " << entry.first
                  << " | Total Quantity Sold: " << entry.second << "\n";
    }
}

// Destructor
SalesAnalytics::~SalesAnalytics() {}