#include "unit.h"
#include <iomanip>
#include <string>
#include <string_view>
#include <iostream>

std::string getDestinationUnit(std::string_view fromUnit) {
    std::string destinationUnit {};

    if (fromUnit == "km") {
        do {
            std::cout << "Enter a valid unit to convert to (mi): ";
            std::cin >> destinationUnit;
        } while (destinationUnit != "mi");
    } else if (fromUnit == "mi") {
        do {
            std::cout << "Enter a valid unit to convert to (km): ";
            std::cin >> destinationUnit;
        } while (destinationUnit != "km");
    } else if (fromUnit == "F") {
        do {
            std::cout << "Enter a valid unit to convert to (C): ";
            std::cin >> destinationUnit;
        } while (destinationUnit != "C");
    } else if (fromUnit == "C") {
        do {
            std::cout << "Enter a valid unit to convert to (F): ";
            std::cin >> destinationUnit;
        } while (destinationUnit != "F");
    } else {
        std::cout << "Unknown destination unit" << "\n";
    }

    return destinationUnit;
}

double calculateConversion(double value, std::string_view fromUnit, std::string_view destinationUnit) {
    double output {};
    if(fromUnit == "km" && destinationUnit == "mi") {
        output = Unit::convertKilometersToMiles(value);
    } else if (fromUnit == "mi" && destinationUnit == "km") {
        output = Unit::convertMilesToKilometers(value);
    } else if (fromUnit == "F" && destinationUnit == "C") {
        output = Unit::convertFahrenheitToCelsius(value);
    } else if (fromUnit == "C" && destinationUnit == "F") {
        output = Unit::convertCelsiusToFahrenheit(value);
    }

    return output;
}

double getValue() {
    std::cout << "Enter value: ";
    double x {};
    std::cin >> x;
    
    return x;
}

int main() {
    std::cout << "Enter a unit to convert from (km, mi, F, C): ";
    std::string fromUnit {};
    std::cin >> fromUnit;

    std::string destinationUnit { getDestinationUnit(fromUnit) };
    
    const double value { getValue() };
    
    const double output { calculateConversion(value, fromUnit, destinationUnit) };
    
    std::cout << value << fromUnit << " > " << std::fixed << std::setprecision(2) << output << destinationUnit << "\n";

    return 0;
}
