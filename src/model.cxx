#include "model.hxx"
#include "frog.hxx"
#include "car.hxx"

/// Convenient type aliases:
using Dimensions = ge211::Dims<int>;
using Position = ge211::Posn<int>;
using Rectangle = ge211::Rect<int>;


Model::Model():
    frog_(true, {board_size_/2, board_size_-1})
{
    for(int i = 0; i<8; i++){
        Car new_car = Car(car_positions_[i], car_velocities_[i]);
        cars_.push_back(new_car);
    }
}

Dimensions Model::get_board_size() const
{
    return {board_size_, board_size_};
}

void Model::on_frame(double dt)
{
    for (auto& car : cars_){
        int car_x_pos = car.get_car_position().x+ (30 * dt);
        car.set_car_position({car_x_pos, car.get_car_position().y});
        // car.next(dt);
    }
}

Rectangle Model::all_positions() const
{
    return Rectangle::from_top_left({0,0}, {board_size_, board_size_});
}

std::vector<Position> Model::get_car_positions() const
{
    return car_positions_;
}

std::vector<Dimensions> Model::get_car_velocities() const
{
    return car_velocities_;
}

std::vector<Car> Model::get_cars() const
{
    return cars_;
}