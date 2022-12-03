#include "controller.hxx"

Controller::Controller()
        : view_(model_)
{ }

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}

void Controller::on_key_down(ge211::Key key)
{
    if (model_.frog_.get_frog_life()) {
        if (key == ge211::Key::up() or key == ge211::Key::code('w')) {
            model_.move_frog_forward();
        }
        if (key == ge211::Key::down() or key == ge211::Key::code('s')) {
            model_.move_frog_back();
        }
        if (key == ge211::Key::left() or key == ge211::Key::code('a')) {
            model_.move_frog_left();
        }
        if (key == ge211::Key::right() or key == ge211::Key::code('d')) {
            model_.move_frog_right();
        }
    }
}

void Controller::on_frame(double dt)
{
    model_.on_frame(dt);
}

View::Dimensions
Controller::initial_window_dimensions() const
{
    return view_.initial_window_dimensions();
}

std::string
Controller::initial_window_title() const
{
    return view_.initial_window_title();
}