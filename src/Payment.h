#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>


class Payment {
private:
    double amount;                      // Amount to be paid
    std::string paymentMethod;          // Payment method (e.g., "Credit Card", "PayPal")
    bool paymentStatus;                 // Status of the payment (success or failure)

public:
    // Constructor
    Payment(double amount, const std::string& paymentMethod);

    // Getters
    double getAmount() const;
    std::string getPaymentMethod() const;
    bool isPaymentSuccessful() const;

    // Payment Processing
    bool validatePaymentDetails(const std::string& details);  // Validate payment details
    bool processPayment(const std::string& details);          // Process payment
    void displayPaymentStatus() const;

    // Destructor
    ~Payment();
};

#endif // PAYMENT_H