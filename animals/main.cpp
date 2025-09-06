/******************************************************************************
 * File Name: main.cpp
 * Author: J. Fababier
 * Creation Date: [September 06, 2025]
 * Description:
 *      This file is used for practicing inheritence in C++.
 *      The "Dog" class is derived from the "Animals" class.
 *****************************************************************************/

#include "Animal.h"
#include "Dog.h"

#include <iostream>
#include <iomanip>

int main() {
    /*
    Expected output on console:
        Spot is wide awake and wagging its tail.
        Spot barks: 'Woof! Woof!'
        Spot happily eats kibble.
        Spot fetches the tennis ball.
        Spot is sleeping on its bed.
    */
   
    Dog dog("Spot", 3.0, 50.0, "English Bull Terrier", true);

    dog.awaken();
    dog.makeSound();
    dog.eat("kibble");
    dog.fetch("tennis ball");
    dog.sleep();

    return 0;
}