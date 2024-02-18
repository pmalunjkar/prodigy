#include <iostream>
using namespace std;

// Function to convert temperature from Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

// Function to convert temperature from Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

// Function to convert temperature from Celsius to Kelvin
double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

// Function to convert temperature from Kelvin to Celsius
double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

int main() {
    double temperature;
    char originalUnit;

    cout << "Enter the temperature value: ";
    cin >> temperature;

    cout << "Enter the original unit of measurement (C, F, or K): ";
    cin >> originalUnit;

    switch (originalUnit) {
        case 'C':
        case 'c':
            cout << "Temperature in Fahrenheit: " << celsiusToFahrenheit(temperature) << " F" << endl;
            cout << "Temperature in Kelvin: " << celsiusToKelvin(temperature) << " K" << endl;
            break;
        case 'F':
        case 'f':
            cout << "Temperature in Celsius: " << fahrenheitToCelsius(temperature) << " C" << endl;
            cout << "Temperature in Kelvin: " << celsiusToKelvin(fahrenheitToCelsius(temperature)) << " K" << endl;
            break;
        case 'K':
        case 'k':
            cout << "Temperature in Celsius: " << kelvinToCelsius(temperature) << " C" << endl;
            cout << "Temperature in Fahrenheit: " << celsiusToFahrenheit(kelvinToCelsius(temperature)) << " F" << endl;
            break;
        default:
            cout << "Invalid unit of measurement entered!" << endl;
            break;
    }

    return 0;
}
