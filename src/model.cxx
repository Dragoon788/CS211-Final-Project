#include "model.hxx"

/// Convenient type aliases:
using Dimensions = ge211::Dims<int>;
using Position = ge211::Posn<int>;
using Rectangle = ge211::Rect<int>;

Model::Model():
        frog_life_(true),
        frog_position_(board_size_/2, board_size_/2)
{
}

bool Model::get_frog_life()
{
    return frog_life_;
}

Position Model::get_frog_position()
{
    return frog_position_;
}

Dimensions Model::get_board_size() const
{
    return {board_size_, board_size_};
}

void Model::on_frame(double dt)
{
    if (key_pressed_ == 'w'){
        frog_position_.y + 1;
    }
    if (key_pressed_ == 's'){
        frog_position_.y - 1;
    }
    if (key_pressed_ == 'a'){
        frog_position_.x - 1;
    }
    if (key_pressed_ == 'd'){
        frog_position_.x + 1;
    }
}
Rectangle Model::all_positions() const
{
    return Rectangle::from_top_left({0,0}, {board_size_, board_size_});
}