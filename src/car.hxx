#pragma once

#include "../.cs211/lib/ge211/include/ge211_geometry.hxx"

/// Convenient type aliases:
using Dimensions = ge211::Dims<int>;
using Position = ge211::Posn<int>;
using Rectangle = ge211::Rect<int>;

class Car
{
public:

    /// Constructor for our Car class
    /// Takes in a position and velocity
    Car(Position car_position_, Dimensions car_velocity_);

    ///    Getter function for Frog Life
    ///    Returns whether frog is alive or dead
    Position get_car_position() const;

    /// Getter Function that returns the position of the frog
    Dimensions get_car_velocity() const;

    /// Setter function for Frog Life
    void set_car_position(Position p);

    /// Setter function for frog position
    void set_car_velocity(Dimensions d);

    /// Gets us the next car given dt
    Car next(double dt);

private:
    Position car_position_;
    Dimensions car_velocity_;

};
