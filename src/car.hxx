#pragma once

#include <ge211.hxx>

/// Convenient type aliases:
using Dimensions = ge211::Dims<int>;
using Position = ge211::Posn<int>;

class Car
{
public:

    /// Constructor for our Car class
    /// Takes in a position and velocity
    Car(Position car_position_);

    ///    Getter function for Frog Life
    ///    Returns whether frog is alive or dead
    Position get_car_position() const;

    /// Gets us the next car given dt
    void next(double dt);

private:
    Position car_position_;
};
