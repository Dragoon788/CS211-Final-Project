#pragma once

#include <ge211.hxx>
#include "frog.hxx"
#include "car.hxx"

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

/// Sets the key pressed to whatever was pressed in controller
    void set_key (char k){
        key_pressed_ = k;
    }

/// Getter function for a vector of positions where cars will spawn
    std::vector<Position> get_car_positions() const;

///  Getter function for a vector of velocities for each car
    std::vector<Dimensions> get_car_velocities() const;

/// Getter function for all the cars
    std::vector<Car> get_cars() const;


private:

    int const board_size_ = 15;
    char key_pressed_;
    std::vector<Position> car_positions_ = {{10, 2}, {3, 3}, {-2,4},
                                             {-2,5},{-2,8}, {-2, 9}, {-2,10},
                                             {-2,11}};
    std::vector<Dimensions> car_velocities_ = {{3,0}, {2,0}, {3,0}, {5,0},
                                               {2,0},
                                              {7,0}, {3,0}, {4,0}};
    std::vector<Car> cars_;
public:
    /// Constructs the frog class
    Frog frog_;
};
