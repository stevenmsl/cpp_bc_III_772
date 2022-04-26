#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <stack>
#include <cstring>
using namespace sol772;
using namespace std;

/*takeaways
  - main difference between this and question 227
    is that we need to support the parenthesis ()
  - '(' has the highest priority meaning every
    incoming operator has to wait in the stack until
    we see a ')' that will kick off the evaluation
    between the most inner pair of (...)

  - we don't need to support the following expression
    -2+3. But if we do just think of it as 0-2 + 3
    and treat the negative sign as yet another
    subtraction opeator
    - check test5

*/

int Solution::calculate(string s)
{
  auto operands = stack<int>();
  auto ops = stack<char>();
  /* to support the expression -2+3
     - not part of the requirement
     - we treat the negative -2 same
       as the expression (0-2)
  */
  auto hasLeft = false;

  for (auto i = 0; i < s.size(); i++)
  {
    auto c = s[i];
    if (isdigit(c))
    {
      auto operand = string(1, c);
      /* retrieve the operand
         - make sure the i is pointing
           at the last digit char to
           avoid skip an extra char
           as we also make advance to
           the next char in the outer
           for loop
      */
      while (i + 1 < s.size() && isdigit(s[i + 1]))
        i++, operand.push_back(s[i]);
      operands.push(stoi(operand));
      hasLeft = true;
    }
    else if (c == '(')
      /* every encounter of '(' is like starting to look
         at a new, smaller expression. We reset
         the hasleft to false we need to start from
         fresh again
      */
      ops.push(c), hasLeft = false;
    else if (c == ')')
    {
      while (ops.top() != '(')
        /*C++ notes
          - the second pop(operands) will be evaluated first
          - so since the right operand is on top of left
            operand in the stack so we are fine here
        */
        operands.push(calc(pop(ops), pop(operands), pop(operands)));
      /* remove '(' */
      ops.pop();
    }
    else if (c == '+' || c == '-' || c == '*' || c == '/')
    {
      /* this will only happen for '-' when we allow
         to have negative numbers in the expression like
         -2+(3*(-2))
         - we supply an additional left operand to
           turn the expression into a new one
           0-2+(3*(0-2))
      */
      if (!hasLeft)
        operands.push(0);

      /* incoming operator has a lower priority
         than the one sitting on the op of the
         stack - it's time to calculate the part
         of the expression concerning the operator
         sitting on top of the stack
      */
      if (!ops.empty() && higherPripority(ops.top(), c))
        /* it's a stack so operand 2 is on top of
           operand 1
         */
        operands.push(calc(pop(ops), pop(operands), pop(operands)));

      ops.push(c);
    }
  }

  while (!ops.empty())
    operands.push(calc(pop(ops), pop(operands), pop(operands)));

  return operands.top();
}

int Solution::calc(char op, int left, int right)
{

  switch (op)
  {
  case '+':
    return left + right;
  case '-':
    return left - right;
  case '*':
    return left * right;
  case '/':
    return left / right;
  }

  throw;
}
int Solution::pop(stack<int> &s)
{
  auto result = s.top();
  s.pop();
  return result;
}
char Solution::pop(stack<char> &s)
{
  auto result = s.top();
  s.pop();
  return result;
}
bool Solution::higherPripority(char op1, char op2)
{
  /* '(' has the highest priority */
  if (op1 == '(')
    return false;
  return op1 == '*' || op1 == '/' || op2 == '+' || op2 == '-';
}
