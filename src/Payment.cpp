#include "Payment.h"
#include <iostream>

// Constructor
Payment::Payment(double amount, const std::string& paymentMethod)
    : amount(amount), paymentMethod(paymentMethod), paymentStatus(false) {}

// Getters
double Payment::getAmount() const {
    return amount;
}

std::string Payment::getPaymentMethod() const {
    return paymentMethod;
}

bool Payment::isPaymentSuccessful() const {
    return paymentStatus;
}

// Validate payment details
bool Payment::validatePaymentDetails(const std::string& details) {
    if (paymentMethod == "Credit Card") {
        // Example validation: Check if card details length is appropriate
        if (details.length() == 16) {
            std::cout << "Credit Card details validated." << std::endl;
            return true;
        } else {
            std::cout << "Invalid Credit Card details." << std::endl;
            return false;
        }
    } else if (paymentMethod == "PayPal") {
        // Example validation: Check if PayPal email format is simple (contains "@")
        if (details.find('@') != std::string::npos) {
            std::cout << "PayPal details validated." << std::endl;
            return true;
        } else {
            std::cout << "Invalid PayPal details." << std::endl;
            return false;
        }
    } else {
        std::cout << "Unsupported payment method." << std::endl;
        return false;
    }
}

// Process payment
bool Payment::processPayment(const std::string& details) {
    if (validatePaymentDetails(details)) {
        paymentStatus = true; // Simulating successful payment
        std::cout << "Payment processed successfully for $" << amount << " via " << paymentMethod << std::endl;
    } else {
        paymentStatus = false;
        std::cout << "Payment failed. Please check your payment details." << std::endl;
    }
    return paymentStatus;
}

// Display payment status
void Payment::displayPaymentStatus() const {
    if (paymentStatus) {
        std::cout << "Payment was successful." << std::endl;
    } else {
        std::cout << "Payment failed." << std::endl;
    }
}

// Destructor
Payment::~Payment() {}