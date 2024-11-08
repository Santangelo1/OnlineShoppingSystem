#ifndef RECOMMENDATION_ENGINE_H
#define RECOMMENDATION_ENGINE_H

#include "Product.h"
#include "Inventory.h"
#include <vector>
#include <map>

class RecommendationEngine
{
public:
    // Constructor
    RecommendationEngine(const Inventory &inventory);

    // Method to get recommendations based on current cart items
    std::vector<Product> getRecommendations(const std::vector<int> &cartProductIds) const;

private:
    const Inventory &inventory;
    std::map<int, std::vector<int> > relatedProductsMap; // Product ID -> Related Product IDs

    // Internal method to initialize related products
    void initializeRecommendations();
};

#endif // RECOMMENDATION_ENGINE_H