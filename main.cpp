#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol772;

/*
"1 + 1" = 2
*/

tuple<string, int>
testFixture1()
{
  return make_tuple("1 + 1", 2);
}

/*
" 6-4 / 2 " = 4
*/

tuple<string, int>
testFixture2()
{
  return make_tuple(" 6-4 / 2 ", 4);
}

/*
"2*(5+5*2)/3+(6/2+8)" = 21
*/

tuple<string, int>
testFixture3()
{
  return make_tuple("2*(5+5*2)/3+(6/2+8)", 21);
}

/*
"(2+6* 3+5- (3*14/7+2)*5)+3"=-12
*/

tuple<string, int>
testFixture4()
{
  return make_tuple("(2+6* 3+5- (3*14/7+2)*5)+3", -12);
}

/*
"-2+(3*(-2))"=-12
*/

tuple<string, int>
testFixture5()
{
  return make_tuple("-2+(3*(-2))", -8);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see " << to_string(get<1>(f)) << endl;
  Solution sol;
  cout << sol.calculate(get<0>(f)) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Expect to see " << to_string(get<1>(f)) << endl;
  Solution sol;
  cout << sol.calculate(get<0>(f)) << endl;
}

void test3()
{
  auto f = testFixture3();
  cout << "Expect to see " << to_string(get<1>(f)) << endl;
  Solution sol;
  cout << sol.calculate(get<0>(f)) << endl;
}

void test4()
{
  auto f = testFixture4();
  cout << "Expect to see " << to_string(get<1>(f)) << endl;
  Solution sol;
  cout << sol.calculate(get<0>(f)) << endl;
}

void test5()
{
  auto f = testFixture5();
  cout << "Expect to see " << to_string(get<1>(f)) << endl;
  Solution sol;
  cout << sol.calculate(get<0>(f)) << endl;
}

main()
{
  test1();
  test2();
  test3();
  test4();
  test5();
  return 0;
}