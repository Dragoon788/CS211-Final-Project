#include "controller.hxx"

Controller::Controller()
        : view_(model_)
{ }

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}

void Controller::on_key(ge211::Key key){
    if (key == ge211::Key::up() or key == ge211::Key::code('w')){
        model_.set_key('w');
    }
    if (key == ge211::Key::down() or key == ge211::Key::code('s')){
        model_.set_key('s');
    }
    if (key == ge211::Key::left() or key == ge211::Key::code('a')){
        model_.set_key('a');
    }
    if (key == ge211::Key::right() or key == ge211::Key::code('d')){
        model_.set_key('d');
    }
}

View::Dimensions
Controller::initial_window_dimensions() const{
    return view_.initial_window_dimensions();
};

std::string
Controller::initial_window_title() const
{
    return view_.initial_window_title();
}