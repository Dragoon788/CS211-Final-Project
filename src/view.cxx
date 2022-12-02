#include "view.hxx"

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
        grass_sprite_({grid_size, grid_size}, grass_green),
        road_sprite_({grid_size, grid_size}, road_gray),
        finish_sprite_({grid_size, grid_size}, car_red),
        frog_sprite_({grid_size-10, grid_size-3}, frog_green),
        frog_sprite_2_("frog_sprite_.png"),
        grass_sprite_2_("grass_sprite_.png"),
        car_sprite_2_("car_sprite_.png"),
        sans72_("sans.ttf", 72),
        sans16_("sans.ttf", 16),
        videogame72_("VideoGame.ttf", 32),
        game_over_sprite_("GAME OVER", videogame72_),
        score_sprite_(std::to_string(model_.get_score()), videogame72_),
        score_words_sprite_("Score: ", videogame72_)
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
    /// Basically checks if game is over and then executes game over sequence
    if(!model_.frog_.get_frog_life()){
        set.add_sprite(game_over_sprite_, {initial_window_dimensions().width/3-30,initial_window_dimensions().height/2-100});
        ge211::Text_sprite::Builder score_builder(videogame72_);
        int final_score = model_.get_score();
        score_builder.add_message(std::to_string(final_score));
        score_sprite_.reconfigure(score_builder);
        set.add_sprite(score_sprite_, {initial_window_dimensions().width/3 + 70,initial_window_dimensions().height/2 + 100});
    }
    else{
        /// Initializes the builder to change the score sprite
        ge211::Text_sprite::Builder score_builder(videogame72_);
        score_builder.add_message(std::to_string(model_.get_score()));
        score_sprite_.reconfigure(score_builder);
        /// Draws score counter
        set.add_sprite(score_words_sprite_, board_to_screen({8, 1}), 4);
        set.add_sprite(score_sprite_, board_to_screen({12,1}), 4);

        ///Draws all the road
        for (auto p: model_.all_positions()) {
            for(auto road_pos: model_.get_car_positions()){

                if (road_pos.y == p.y){
                    set.add_sprite(road_sprite_, board_to_screen(p), 1);
                }
                if(p.y == 2){
                    set.add_sprite(finish_sprite_,board_to_screen(p), 1);
                }
                else{
                    set.add_sprite(grass_sprite_, board_to_screen(p), 0);
                }
            }
        }
        for(auto car : model_.get_cars()){
            set.add_sprite(car_sprite_2_,
                           board_to_screen(car.get_car_position()), 3);
        }
        set.add_sprite(frog_sprite_2_, board_to_screen(model_.frog_
                                                           .get_frog_position()), 2);
        set.add_sprite(score_sprite_, board_to_screen({12,1}));
        ge211::Text_sprite::Builder builder(videogame72_);
    }
}

View::Dimensions
View::initial_window_dimensions() const
{
    // You can change this if you want:
    Dimensions game_board_dims =  grid_size * model_.get_board_size();
    return {game_board_dims.width, game_board_dims.width+(grid_size*2)};
}

std::string
View::initial_window_title() const
{
    // You can change this if you want:
    return "Frogger";
}

