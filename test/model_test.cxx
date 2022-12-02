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


}
// go forward/back add/subtract score
// can't go off sides of screen
// when hit top, go to bottom
// hits car, game over
// game over == accurate score