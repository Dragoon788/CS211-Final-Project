#pragma once

#include <ge211.hxx>

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

///    Getter function for Frog Life
///    Returns whether frog is alive or dead
    bool get_frog_life();

/// Getter Function that returns the position of the frog
    Position get_frog_position();

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
// /// Updates game based on whether player has moved
//     void move (double dt);


private:
    //    Initialize State of the board
    // const int square_size = 10;
    // int board_width = 10;
    // ge211::Dims<int> window_dims = {square_size * board_width, square_size (
    //         board_width)}
    //
    //         char squares_[10][10];
    //    Initialize whether character is alive or dead (game over?)
    //    Initialize position
    // ge211::Posn<int> start_pos = {0,1};

    int const board_size_  = 14;
    bool frog_life_;
    Position frog_position_;
    char key_pressed_;
};
