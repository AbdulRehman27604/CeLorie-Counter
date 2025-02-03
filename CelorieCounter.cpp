#include <iostream>
#include <vector>
#include <string>
#include <limits>


struct FoodItem {
    std::string name;
    int calories;
};

// Function declarations
void addFoodItem(std::vector<FoodItem>& items);
void listFoodItems(const std::vector<FoodItem>& items);
void showTotalCalories(const std::vector<FoodItem>& items);
void clearInputBuffer();

int main() {
    std::vector<FoodItem> foodItems;
    int choice = 0;

    do {
        // Display the menu
        std::cout << "\nCalorie Counter Menu:\n";
        std::cout << "1. Add Food Item\n";
        std::cout << "2. List Food Items\n";
        std::cout << "3. Show Total Calories\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        // Validate input
        if(std::cin.fail()){
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            clearInputBuffer();
            continue;
        }

        // Process user choice
        switch (choice) {
            case 1:
                addFoodItem(foodItems);
                break;
            case 2:
                listFoodItems(foodItems);
                break;
            case 3:
                showTotalCalories(foodItems);
                break;
            case 4:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

void addFoodItem(std::vector<FoodItem>& items) {
    FoodItem item;
    std::cout << "\nEnter the name of the food item: ";
    clearInputBuffer();
    std::getline(std::cin, item.name);
    
    std::cout << "Enter the number of calories: ";
    std::cin >> item.calories;

    
    if (std::cin.fail()) {
        std::cin.clear();
        clearInputBuffer();
        std::cout << "Invalid calorie count. Please try again.\n";
        return;
    }
    
    items.push_back(item);
    std::cout << "Food item added successfully!\n";
}

void listFoodItems(const std::vector<FoodItem>& items) {
    if (items.empty()) {
        std::cout << "\nNo food items recorded.\n";
        return;
    }
    std::cout << "\nFood Items:\n";
    for (const auto& item : items) {
        std::cout << "Name: " << item.name << ", Calories: " << item.calories << "\n";
    }
}

void showTotalCalories(const std::vector<FoodItem>& items) {
    int total = 0;
    for (const auto& item : items) {
        total += item.calories;
    }
    std::cout << "\nTotal Calories: " << total << "\n";
}

// Helper function to clear any leftover characters in the input buffer
void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
