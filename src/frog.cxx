#include "frog.hxx"

/// Convenient type aliases:
using Dimensions = ge211::Dims<int>;
using Position = ge211::Posn<int>;
using Rectangle = ge211::Rect<int>;

Frog::Frog(bool frog_life_, Position frog_position_):
        frog_position_(frog_position_),
        frog_life_(frog_life_)
{}
bool Frog::get_frog_life() const
{
    return frog_life_;
}

Position Frog::get_frog_position() const
{
    return frog_position_;
}

void Frog::set_frog_life(bool b)
{
    frog_life_ = b;
}

void Frog::set_frog_position(Position p)
{
    frog_position_ = p;
}

bool Frog::hits_car(Frog f, Car c){
    return f.get_frog_position().y == c.get_car_position().y
           && f.get_frog_position().x <= c.get_car_position().x + 1
           && f.get_frog_position().x >= c.get_car_position().x - 1;
}


