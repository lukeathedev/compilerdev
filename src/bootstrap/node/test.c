#include "test.h"

#include "node/node.h"

// 3 * 2 + 4
//
//     +
//  4     *
//      3   2
NODE* nd_ex00() {
  NODE* root = nodemk(
    "+",
    nodemk("4", NULL, NULL),
    nodemk(
      "*",
      nodemk("3", NULL, NULL),
      nodemk("2", NULL, NULL)
    )
  );

  return root;
}

// 2 + 10 - 9 * 3
//
//     +
// 2      -
//    10     *
//         9   3 
NODE* nd_ex01() {
  NODE* root =
  nodemk("+",
    nodemk("2", NULL, NULL),
    nodemk("-",
      nodemk("10", NULL, NULL),
      nodemk("*",
        nodemk("9", NULL, NULL),
        nodemk("3", NULL, NULL)
      )
    )  
  );

  return root;
}

// 10 * 10 - 4 + 3 * 2 / 2 (=99)
//
//               +
//          -          /
//      *      4    *     2
//   10   10      3   2
NODE* nd_ex02() {
  NODE* root =
  nodemk(
    "+",
    nodemk(
      "-",
      nodemk(
        "*",
        nodemk("10", NULL, NULL),
        nodemk("10", NULL, NULL)
      ),
      nodemk("4", NULL, NULL)
    ),
    nodemk(
      "/",
      nodemk(
        "*",
        nodemk("3", NULL, NULL),
        nodemk("2", NULL, NULL)
      ),
      nodemk("2", NULL, NULL)
    )
  );

  return root;
}
