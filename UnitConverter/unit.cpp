#include "unit.h"

namespace Unit {
    double convertFahrenheitToCelsius(double value) {
        return (value - 32) / 1.8;
    }

    double convertCelsiusToFahrenheit(double value) {
        return (value * 1.8) + 32;
    }

    double convertKilometersToMiles(double value) {
        return (value / 1.609);
    }

    double convertMilesToKilometers(double value) {
        return (value * 1.609);
    }
}
