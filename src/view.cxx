#include "view.hxx"

// Convenient type aliases:
using Color = ge211::Color;
using Sprite_set = ge211::Sprite_set;

// You can change this or even determine it some other way:
static int const grid_size = 20;
static int const radius = grid_size/2;
static ge211::Color const grass_green {1,68,33};
static ge211::Color const road_gray {100,100,100};
static ge211::Color const car_red {202,0,42};
static ge211::Color const frog_green {124,252,0};

View::View(Model const& model)
        : model_(model),
        grass_sprite_({grid_size, grid_size}, grass_green),
        road_sprite_({grid_size, grid_size}, road_gray),
        car_sprite_({grid_size, grid_size}, car_red),
        frog_sprite_({grid_size, grid_size}, frog_green)
{
}

void
View::draw(ge211::Sprite_set& set)
{
    // This needs to do something!
    for (auto p: model_.all_positions()) {
        set.add_sprite(grass_sprite_, p);
    }
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
