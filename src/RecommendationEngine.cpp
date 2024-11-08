#include "RecommendationsEngine.h"
#include <vector>


// Constructor
RecommendationEngine::RecommendationEngine(const Inventory &inventory) : inventory(inventory)
{
    initializeRecommendations(); // Initialize the recommendation relationships
}

// Initialize the recommendations for related products
void RecommendationEngine::initializeRecommendations()
{
    // Example: manually setting related products
    relatedProductsMap[1] = {2, 3}; // Product ID 1 is related to products 2 and 3
    relatedProductsMap[2] = {1, 4}; // Product ID 2 is related to products 1 and 4
    // Add more relationships as needed
}

// Get recommendations based on cart product IDs
std::vector<Product> RecommendationEngine::getRecommendations(const std::vector<int> &cartProductIds) const
{
    std::vector<Product> recommendations;

    // Iterate over each product ID in the cart
    for (size_t i = 0; i < cartProductIds.size(); ++i)
    {
        int productId = cartProductIds[i];
        auto it = relatedProductsMap.find(productId);

        // If related products are found
        if (it != relatedProductsMap.end())
        {
            // Iterate over related product IDs
            for (int relatedId : it->second)
            {
                auto product = inventory.findProductById(relatedId);

                if (product)
                {                                        // Assuming findProductById returns a pointer or reference
                    recommendations.push_back(*product); // Dereference if it's a pointer
                }
            }
        }
    }

    return recommendations;
}