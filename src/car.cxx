#include "car.hxx"

/// Convenient type aliases:
using Dimensions = ge211::Dims<int>;
using Position = ge211::Posn<int>;
using Rectangle = ge211::Rect<int>;

Car::Car(Position car_position_):
        car_position_(car_position_)
{}
Position Car::get_car_position() const
{
    return car_position_;
}

void Car::next(double dt){
    if (car_position_.x >= 15) {
        car_position_.x -= 18;
    }
    car_position_.x += 60 * dt;
}

