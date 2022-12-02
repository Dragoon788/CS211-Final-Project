#include "car.hxx"
#include "../.cs211/lib/ge211/include/ge211_geometry.hxx"

/// Convenient type aliases:
using Dimensions = ge211::Dims<int>;
using Position = ge211::Posn<int>;
using Rectangle = ge211::Rect<int>;

Car::Car(Position car_position_, Dimensions car_velocity_):
        car_position_(car_position_),
        car_velocity_(car_velocity_)
{}
Position Car::get_car_position() const
{
    return car_position_;
}

Dimensions Car::get_car_velocity() const
{
    return car_velocity_;
}

void Car::set_car_position(Position p)
{
    car_position_ = p;
}

void Car::set_car_velocity(Dimensions d)
{
    car_velocity_ = d;
}

Car Car::next(double dt){
    // Car result(*this);
    // result.car_position_ += car_velocity_ * dt *1000;
    // return result;
    // car_position_.x += car_velocity_.width *60 * dt;
    if (car_position_.x >= 15){
        car_position_.x -= 18;
    }
    car_position_.x += 60 * dt;
}

