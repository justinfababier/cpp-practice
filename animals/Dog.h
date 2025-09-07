#ifndef DOG_H
#define DOG_H

#include "Animal.h"

#include <iostream>
#include <string>

// Derived publicly inheriting from Base
class Dog : Animal {
    private:
        std::string breed;
        bool isTrained;

    public:     // Public members can be accessed outside the class
        Dog(const std::string &name_, int age_, double weight_, const std::string &breed_, bool isTrained_):
            Animal(name_, weight_, age_),
            breed(breed_),
            isTrained(isTrained)
        {}

    // Getters
    std::string getBreed() const {
        return breed;
    }

    bool getIsTrained() const {
        return isTrained;
    }

    // Setters
    void setBreed(const std::string &breed_) {
        breed = breed_;
    }

    void setIsTrained(bool isTrained_) {
        isTrained = isTrained_;
    }

    // Virtual functions
    void makeSound() const override {
        std::cout << getName() << " barks: 'Woof! Woof!'" << std::endl;
    }

    void eat(const std::string &food) override {
        std::cout << getName() << " happily eats " << food << "." << std::endl;
    }

    virtual void awaken() override {
        std::cout << getName() << " is wide awake and wagging its tail." << std::endl;
    }

    virtual void sleep() override {
        std::cout << getName() << " is sleeping on its bed." << std::endl;
    }

    // Dog-specific behavior
    void fetch(const std::string &item) {
        std::cout << getName() << " fetches the " << item << "." << std::endl;
    }
};

#endif