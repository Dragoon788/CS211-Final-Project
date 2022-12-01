#pragma once

#include "model.hxx"
#include "view.hxx"

#include <ge211.hxx>

class Controller : public ge211::Abstract_game
{
public:
    Controller();
    void on_key(ge211::Key key) override;
    void on_frame(double dt) override;

protected:
    void draw(ge211::Sprite_set& set) override;
    std::string initial_window_title() const;
    View::Dimensions initial_window_dimensions() const;

private:
    Model model_;
    View view_;

};
