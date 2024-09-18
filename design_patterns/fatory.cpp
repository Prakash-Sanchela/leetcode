
#include <iostream>
#include <memory> // For std::unique_ptr

// Step 1: Create an enumeration to identify the derived classes
enum class ObjectType {
    ITM1DFacet,
    ITM2DFacet
};

// Step 2: Create the base class
class Base {
public:
    // A virtual function to be overridden by derived classes
    virtual void display() const = 0;
    
    // Step 3: Static factory method to create instances
    static std::unique_ptr<Base> CreateFactory(ObjectType type) {
        switch (type) {
            case ObjectType::TypeA:
                return std::make_unique<DerivedA>();
            case ObjectType::TypeB:
                return std::make_unique<DerivedB>();
            default:
                return nullptr;
        }
    }

    // Virtual destructor to ensure proper cleanup of derived objects
    virtual ~Base() = default;
};

// Step 4: Create the first derived class
class DerivedA : public Base {
public:
    void display() const override {
        std::cout << "This is DerivedA" << std::endl;
    }
};

// Step 5: Create the second derived class
class DerivedB : public Base {
public:
    void display() const override {
        std::cout << "This is DerivedB" << std::endl;
    }
};

// Step 6: Use the factory method to create objects
int main() {
    // Create an instance of DerivedA using the factory
    std::unique_ptr<Base> objA = Base::CreateFactory(ObjectType::TypeA);
    if (objA) {
        objA->display();
    }

    // Create an instance of DerivedB using the factory
    std::unique_ptr<Base> objB = Base::CreateFactory(ObjectType::TypeB);
    if (objB) {
        objB->display();
    }

    return 0;
}
