#pragma once
#include <iostream>
#include <cmath>

#define pi 3.1415

class Vector2
{
public:
    double x, y;
    Vector2(double ax, double ay) : x(ax), y(ay) {}
};

class vector {
public:
    double magnitude;
    double direction; // Angle in radians

    vector(double magnitude, double direction) : magnitude(magnitude), direction(direction) {}
    vector() : magnitude(0), direction(0) {}


    // Get the magnitude of the vector
    double getMagnitude() const {
        return magnitude;
    }

    // Get the direction of the vector in radians
    double getDirection() const {
        return direction;
    }

    // Vector addition
    vector operator+(const vector& other) const {
        double x1 = magnitude * cosf(direction);
        double y1 = magnitude * sinf(direction);

        double x2 = other.magnitude * cosf(other.direction);
        double y2 = other.magnitude * sinf(other.direction);

        double xResult = x1 + x2;
        double yResult = y1 + y2;

        double magnitudeResult = std::sqrtf(xResult * xResult + yResult * yResult);
        double directionResult = std::atan2f(yResult, xResult);

        return vector(magnitudeResult, directionResult);
    }

    // Print the vector
    void print() const {
        std::cout << "Magnitude: " << magnitude << ", Direction: " << direction << " radians" << std::endl;
    }
};