#pragma once

#include <ge211.hxx>
#include "frog.hxx"
#include "car.hxx"
//#include "controller.hxx"

class Model
{
public:
    /// Convenient type aliases:
    using Dimensions = ge211::Dims<int>;
    using Position = ge211::Posn<int>;
    using Rectangle = ge211::Rect<int>;


///    Constructs the model with given "size" as both its width and height
///
/// ## Errors
///
///  - Throws `ge211::Client_logic_error` if `size` is input
    explicit Model();

/// Returns all the positions of the tiles
    Rectangle all_positions() const;

/// Returns the board dimensions
    Dimensions get_board_size() const;

/// Update the state of the game by 1/60 of a second
    void on_frame(double dt);


// Getter function for a vector of positions where cars will spawn
    std::vector<Position> get_car_positions() const;

// Getter function for all the cars
    std::vector<Car> get_cars() const;

//  Getter function the starting frog position
    Position get_initial_frog_pos() const;

// Getter function for the score
    int get_score() const;

// Add score to counter
    void set_score();

// Subtract fake_score
    void subtract_score();

/// Move frog position forward
    void move_frog_forward();

/// Move frog position back
    void move_frog_back();


/// Move frog left
    void move_frog_left();

/// Move frog right
    void move_frog_right();

private:

    int const board_size_ = 15;
    std::vector<Position> car_positions_ = {{10, 4}, {5,4}, {3, 5}, {-3,6},
                                             {3,7}, {11,7}, {-5,10}, {10, 11},
                                             {-3, 11},{5,12}, {8,13}};
    std::vector<Car> cars_;
    Position initial_frog_pos_ = {board_size_ / 2, board_size_ + 1};
    int time_counter = 15;
    int score_counter = 0;
    int fake_score_ = 0;

public:
    /// Constructs the frog class
    Frog frog_;
};
