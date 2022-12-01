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
        Position frog_pos = model_.frog_.get_frog_position();
        if(frog_pos.y != 0){
            model_.frog_.set_frog_position({frog_pos.x, frog_pos.y-1});
        }
    }
    if (key == ge211::Key::down() or key == ge211::Key::code('s')){
        Position frog_pos = model_.frog_.get_frog_position();
        if (frog_pos.y != (model_.get_board_size().height)-1){
            model_.frog_.set_frog_position({frog_pos.x, frog_pos.y+1});
        }
    }
    if (key == ge211::Key::left() or key == ge211::Key::code('a')){
        Position frog_pos = model_.frog_.get_frog_position();
        if(frog_pos.x != 0){
            model_.frog_.set_frog_position({frog_pos.x-1, frog_pos.y});
        }
    }
    if (key == ge211::Key::right() or key == ge211::Key::code('d')){
        Position frog_pos = model_.frog_.get_frog_position();
        if(frog_pos.x != (model_.get_board_size().width-1)){
            model_.frog_.set_frog_position({frog_pos.x+1, frog_pos.y});
        }
    }
}

void Controller::on_frame(double dt)
{
    model_.on_frame(dt);
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