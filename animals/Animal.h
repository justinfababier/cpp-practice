#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal {  // Animals class
    private:    // Private members are only accessible within the class
        // Attributes of the animals
        std::string name;   // Name of animal
        int age;            // Age in years
        double weight;      // Weight in kilograms
        bool isAlive;       // Life status

    public:     // Public members can be accessed outside the class
        // Constructor to initalize the animal's properties
        Animal(const std::string& name_, int age_, double weight_):
            name(name_),
            age(age_),
            weight(weight_),
            isAlive(true)
        {}

    // Getters
    std::string getName() const {   
        return name; // Return name of animal
    }
    
    int getAge() const {
        return age; // Return age of animal
    }

    double getWeight() const {
        return weight; // Return weight of animal
    }

    bool getIsAlive() const {
        return isAlive; // Return life status of animal
    }

    // Setters
    void setName(const std::string& name_) {
        name = name_;   // Set name of animal
    }

    void setAge(int age_) {
        age = age_;     // Set age of animal
    }

    void setWeight(double weight_) {
        weight = weight_;
    }

    void setIsAlive(bool isAlive_) {
        isAlive = isAlive_;
    }

    // Virtual functions (overrideable)
    virtual void makeSound() const {
        std::cout << "Animal makes a sound." << std::endl;
    }

    virtual void eat(const std::string& food) {
        std::cout << name << " eats " << food << "." << std::endl;
    }

    virtual void awaken() {
        std:: cout << name << " is wide awake." << std::endl;
    }

    virtual void sleep() {
        std::cout << name << " is sleeping." << std::endl;
    }
};

#endif