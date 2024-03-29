
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <stack>

using namespace std;
namespace sol772
{

  class Solution
  {
  private:
    int calc(char op, int left, int right);
    int pop(stack<int> &s);
    char pop(stack<char> &s);
    bool higherPripority(char op1, char op2);

  public:
    int calculate(string s);
  };
}
#endif