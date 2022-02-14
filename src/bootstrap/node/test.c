#include "test.h"

#include "node/node.h"

// 3 * 2 + 4 (=10)
//
//     +
//  4     *
//      3   2
NODE* nd_ex00() {
  NODE* root = nodemk(
    ND_ADD,
    "+",
    nodemk(ND_INT, "4", NULL, NULL),
    nodemk(
      ND_MUL,
      "*",
      nodemk(ND_INT, "3", NULL, NULL),
      nodemk(ND_INT, "2", NULL, NULL)
    )
  );

  return root;
}

// 2 + 10 - 9 * 3 (=-15)
//
//     +
// 2      -
//    10     *
//         9   3 
NODE* nd_ex01() {
  NODE* root =
  nodemk(
    ND_ADD,
    "+",
    nodemk(ND_INT, "2", NULL, NULL),
    nodemk(
      ND_SUB,
      "-",
      nodemk(ND_INT, "10", NULL, NULL),
      nodemk(
        ND_MUL,
        "*",
        nodemk(ND_INT, "9", NULL, NULL),
        nodemk(ND_INT, "3", NULL, NULL)
      )
    )  
  );

  return root;
}

// 10 * 10 - 4 + 3 * 2 / 2 (=99)
//
//              +
//        -           /
//    *      4     *     2
// 10   10       3   2
NODE* nd_ex02() {
  NODE* root =
  nodemk(
    ND_ADD,
    "+",
    nodemk(
      ND_SUB,
      "-",
      nodemk(
        ND_MUL,
        "*",
        nodemk(ND_INT, "10", NULL, NULL),
        nodemk(ND_INT, "10", NULL, NULL)
      ),
      nodemk(ND_INT, "4", NULL, NULL)
    ),
    nodemk(
      ND_DIV,
      "/",
      nodemk(
        ND_MUL,
        "*",
        nodemk(ND_INT, "3", NULL, NULL),
        nodemk(ND_INT, "2", NULL, NULL)
      ),
      nodemk(ND_INT, "2", NULL, NULL)
    )
  );

  return root;
}
