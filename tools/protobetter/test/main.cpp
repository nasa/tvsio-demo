#include <gtest/gtest.h>

// TODO: don't use arbitrary names for grouping tests anymore - give meaningful names / groupings to tests at some point

#include "test_a.h"
#include "test_b.h"
#include "test_c.h"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
