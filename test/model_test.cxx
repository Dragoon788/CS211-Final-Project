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


// go forward/back add/subtract score
// can't go off sides of screen
// when hit top, go to bottom
// hits car, game over
// game over == accurate score