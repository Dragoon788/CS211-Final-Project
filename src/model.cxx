#include "model.hxx"
#include "car.hxx"
#include "frog.hxx"
#include "controller.hxx"
/// Convenient type aliases:
using Dimensions = ge211::Dims<int>;
using Position = ge211::Posn<int>;
using Rectangle = ge211::Rect<int>;


Model::Model():
    frog_(true, initial_frog_pos_)
{
    for (int i = 0; i < 11; i++) {
        Car new_car = Car(car_positions_[i]);
        cars_.push_back(new_car);
    }
}

Dimensions Model::get_board_size() const
{
    return {board_size_, board_size_};
}

void Model::on_frame(double dt)
{
    while(frog_.get_frog_life()){
        time_counter++;
        if (time_counter < 15) {
            return;
        }
        else{
            time_counter = 0;
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

std::vector<Car> Model::get_cars() const
{
    return cars_;
}

Position Model::get_initial_frog_pos() const
{
    return initial_frog_pos_;
}

int Model::get_score() const
{
    return score_counter;
}

void Model::set_score()
{
    if (fake_score_ == score_counter) {
        score_counter++;
    }
    fake_score_++;
}

void Model::subtract_score()
{
    fake_score_--;
}

void Model::move_frog_forward()
{
    Position frog_pos = frog_.get_frog_position();
    if (frog_pos.y > 3) {
        frog_.set_frog_position({frog_pos.x, frog_pos.y - 1});
        set_score();
    } else {
        frog_.set_frog_position(get_initial_frog_pos());
    }
}

void Model::move_frog_back()
{
    Position frog_pos = frog_.get_frog_position();
    if (frog_pos.y != 16) {
        frog_.set_frog_position({frog_pos.x, frog_pos.y+1});
        subtract_score();
    }
}

void Model::move_frog_left()
{
    Position frog_pos = frog_.get_frog_position();
    if (frog_pos.x != 0) {
        frog_.set_frog_position({frog_pos.x - 1, frog_pos.y});
    }
}

void Model::move_frog_right()
{
    Position frog_pos = frog_.get_frog_position();
    if (frog_pos.x != (get_board_size().width - 1)) {
        frog_.set_frog_position({frog_pos.x + 1, frog_pos.y});
    }
}
