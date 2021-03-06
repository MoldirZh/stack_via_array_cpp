#include "stack.h"

using namespace std;

int main()
{
  stack a{100,99,99};

  for(size_t i = 0; i < 40; ++i)
    a.push(i);


  cout << a << endl << endl;

  stack b = a;

  cout << b << endl << endl;


  for(int i = 0; i < 20; ++i)
    b.pop();

  cout << b << endl << endl;
  cout << a << endl << endl;


  a = b;

  cout << a << endl << endl;
  cout << b << endl << endl;


  a.clear();
  cout << a << endl << endl;

  b.reset(10);
  cout << b << endl << endl;


  return 0;
}
