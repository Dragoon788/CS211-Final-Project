#pragma once

#include "model.hxx"

class View
{
public:
/// View dimensions will use `int` coordinates.
    using Dimensions = ge211::Dims<int>;

/// View positions will use `int` coordinates.
    using Position = ge211::Posn<int>;

///  Constructs a view that knows about the given model.
    explicit View(Model const& model);

    void draw(ge211::Sprite_set& set);

    Dimensions initial_window_dimensions() const;

    std::string initial_window_title() const;

    View::Position board_to_screen(Model::Position pos) const;

private:
    Model const& model_;

/// sprites
    ge211::Rectangle_sprite const grass_sprite_;
    ge211::Rectangle_sprite const road_sprite_;
    ge211::Rectangle_sprite const finish_sprite_;
    ge211::Image_sprite const frog_sprite_2_;
    ge211::Image_sprite const grass_sprite_2_;
    ge211::Image_sprite const car_sprite_2_;
    ge211::Font const sans72_;
    ge211::Font const sans16_;
    ge211::Font const videogame72_;
    ge211::Text_sprite const game_over_sprite_;
    ge211::Text_sprite score_sprite_;
    ge211::Text_sprite score_words_sprite_;
};
