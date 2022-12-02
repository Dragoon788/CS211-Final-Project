#include "model.hxx"
#include "frog.hxx"
#include "car.hxx"


/// Convenient type aliases:
using Dimensions = ge211::Dims<int>;
using Position = ge211::Posn<int>;
using Rectangle = ge211::Rect<int>;


Model::Model():
    frog_(true, initial_frog_pos_)
{
    for(int i = 0; i<11; i++){
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
    while(frog_.get_frog_life() != false){
        time_counter ++;
        if (time_counter<30) {
            return;
        }
        else{
            time_counter=0;
            for (auto& car : cars_){
                car.next(dt);
                if (frog_.hits_car(frog_, car)){
                    frog_.set_frog_life(false);
                }
            }
        }
    }
}

Rectangle Model::all_positions() const
{
    return Rectangle::from_bottom_left({0,17}, {board_size_, board_size_});
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

Position Model::get_initial_frog_pos() const
{
    return initial_frog_pos_;
}