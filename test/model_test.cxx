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

TEST_CASE("going forward add score, back does not")
{
    Model model;

    CHECK(model.get_score() == 0);
    CHECK(model.frog_.get_frog_life());

    // need to implement going forward adding score
}

TEST_CASE("when hit top, reset position")
{
    Model model;

    model.frog_.set_frog_position({2, 1});
    CHECK(model.frog_.get_frog_life());

    CHECK(model.frog_.get_frog_position() == model.get_initial_frog_pos());
}

TEST_CASE("hit car, end game")
{
    Model model;

    model.frog_.set_frog_position({4, 4});
    model.frog_.set_frog_life(false);
    CHECK(!model.frog_.get_frog_life());
}

TEST_CASE("accurate score") {
    Model model;

    model.frog_.set_frog_position(model.get_initial_frog_pos());
    CHECK(model.frog_.get_frog_life());
    model.set_score();
    model.set_score();

    CHECK(model.get_score() == 2);
    model.set_score();
    model.set_score();

    model.set_score();

    model.frog_.set_frog_life(false);
    CHECK(!model.frog_.get_frog_life());
    CHECK(model.get_score() == 5);
}
// go forward/back add/subtract score DONE
// can't go off sides of screen
// when hit top, go to bottom
// hits car, game over
// game over == accurate score DONE