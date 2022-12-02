#include "model.hxx"
#include <catch.hxx>
#include <ge211.hxx>

TEST_CASE("example test (TODO: replace this)")
{
    CHECK(1 + 1 == 2);
}

//
// TODO: Write preliminary model tests.
//
// These tests should demonstrate your functional requirements.
//

TEST_CASE("going forward add score") // DONE
{
    Model model;

    model.frog_.set_frog_position(model.get_initial_frog_pos());

    CHECK(model.get_score() == 0);
    CHECK(model.frog_.get_frog_life());

    // need to implement going forward adding score DONE
    model.move_forward();
    CHECK(model.get_score() == 1);
    model.move_forward();
    CHECK(model.frog_.get_frog_position().x == model.get_initial_frog_pos().x);
    CHECK(model.frog_.get_frog_position().y ==  model.get_initial_frog_pos().y - 2);
    CHECK(model.get_score() == 2);
}

TEST_CASE("when hit top, reset position") // DONE
{
    Model model;

    model.frog_.set_frog_position({2, 3});
    CHECK(model.frog_.get_frog_life());

    CHECK(model.frog_.get_frog_position(). y == 3);
    model.move_forward();
    model.move_forward();
    CHECK(model.frog_.get_frog_position() == model.get_initial_frog_pos());
    model.move_forward();
    CHECK(model.frog_.get_frog_position().y == model.get_initial_frog_pos().y - 1);
}

TEST_CASE("hit car, end game")
{
    Model model;

    Car c({3, 3});
    model.frog_.set_frog_position({3, 4});
    model.move_forward();
    CHECK(model.frog_.hits_car(model.frog_, c));
    CHECK(model.frog_.get_frog_life());
    CHECK(model.get_score() == 1);
}

TEST_CASE("accurate score") {
    Model model;

    model.frog_.set_frog_position(model.get_initial_frog_pos());
    CHECK(model.frog_.get_frog_life());
    model.move_forward();
    model.move_forward();

    CHECK(model.get_score() == 2);
    model.move_forward();
    model.move_forward();
    model.move_forward();

    model.frog_.set_frog_life(false);
    
    CHECK(!model.frog_.get_frog_life());
    CHECK(model.get_score() == 5);
}
// go forward/back add/subtract score DONE
// can't go off sides of screen
// when hit top, go to bottom
// hits car, game over
// game over == accurate score DONE