#include "view.hxx"
#include "frog.hxx"

// Convenient type aliases:
using Color = ge211::Color;
using Sprite_set = ge211::Sprite_set;

// You can change this or even determine it some other way:
static int const grid_size = 50;
static int const radius = grid_size/2;
static ge211::Color const grass_green {1,68,33};
static ge211::Color const road_gray {100,100,100};
static ge211::Color const car_red {202,0,42};
static ge211::Color const frog_green {124,252,0};

View::View(Model const& model)
        : model_(model),
        grass_sprite_({grid_size-3, grid_size-3}, grass_green),
        road_sprite_({grid_size, grid_size}, road_gray),
        car_sprite_({grid_size, grid_size}, car_red),
        frog_sprite_({grid_size, grid_size}, frog_green)
{
}

View::Position
View::board_to_screen(Model::Position pos) const
{
    return {grid_size * pos.x, grid_size * pos.y};
}

Model::Position
View::screen_to_board(View::Position pos) const
{
    return {pos.x / grid_size, pos.y / grid_size};
}

void
View::draw(ge211::Sprite_set& set)
{
    // This needs to do something!
    for (auto p: model_.all_positions()) {
        for(auto road_pos: model_.get_car_positions()){
            if (road_pos.y == p.y){
                set.add_sprite(road_sprite_, board_to_screen(p), 1);
            }
            else{
                set.add_sprite(grass_sprite_, board_to_screen(p), 0);
            }
        }
        // if(p.y == 2 or p.y == 3 or p.y == 4 or p.y == 5 or p.y ==8  or p.y ==
        // 9 or p.y == 10 or p.y == 11){
        //     set.add_sprite(road_sprite_, board_to_screen(p), 0);
        // }
        // else{
        //     set.add_sprite(grass_sprite_, board_to_screen(p), 0);
        // }
    }
    for(auto car : model_.get_cars()){
        set.add_sprite(car_sprite_, board_to_screen(car.get_car_position()), 3);
    }
    set.add_sprite(frog_sprite_, board_to_screen(model_.frog_
    .get_frog_position()), 2);
}


View::Dimensions
View::initial_window_dimensions() const
{
    // You can change this if you want:
    return grid_size * model_.get_board_size();
}

std::string
View::initial_window_title() const
{
    // You can change this if you want:
    return "Frogger";
}
