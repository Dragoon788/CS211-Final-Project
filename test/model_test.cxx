#include "model.hxx"
//#include "controller.hxx"
#include <catch.hxx>
//#include <ge211.hxx>

TEST_CASE("example test (TODO: replace this)")
{
    CHECK(1 + 1 == 2);
}

//
// TODO: Write preliminary model tests.
//
// These tests should demonstrate your functional requirements.
//

TEST_CASE("going forward add score, back does not")
{
    Model model;

    CHECK(model.get_score() == 0);
    CHECK(model.frog_.get_frog_life());
}

TEST_CASE("when hit top, reset position")
{
    Model model; 
//    Controller controller;

    model.frog_.set_frog_position({2, 1});
    CHECK(model.frog_.get_frog_life());
    model.frog_.set_frog_position({1, 1});
//    controller.on_key_down(ge211::Key::up());
    CHECK(model.frog_.get_frog_position() == model.get_initial_frog_pos());
}
// go forward/back add/subtract score
// can't go off sides of screen
// when hit top, go to bottom
// hits car, game over
// game over == accurate score