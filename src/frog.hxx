#pragma once

#include <ge211.hxx>
#include "car.hxx"

/// Convenient type aliases:
using Dimensions = ge211::Dims<int>;
using Position = ge211::Posn<int>;
//using Rectangle = ge211::Rect<int>;

class Frog
{
public:

    /// Constructor for the Frog Class
    /// Takes in frog alive state and frog position
    Frog(bool frog_life_, Position frog_position_);

    ///    Getter function for Frog Life
    ///    Returns whether frog is alive or dead
    bool get_frog_life() const;

    /// Getter Function that returns the position of the frog
    Position get_frog_position() const;

    /// Setter function for Frog Life
    void set_frog_life(bool b);

    /// Setter function for frog position
    void set_frog_position(Position p);

    bool hits_car(Frog f, Car c);


private:
    Position frog_position_;
    bool frog_life_;
};
