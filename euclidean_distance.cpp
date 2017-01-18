#include <iostream>
#include <cmath>

using namespace std;

main()
{
double x1,x2,y1,y2, distance; 
cout << "X1> " ;
cin >> x1;

cout << "X2> ";
cin >> x2;

cout << "Y1> ";
cin >> y1;

cout << "Y2> ";
cin >> y2;

distance = hypot(x1-y1,x2-y2);

cout << "Euclidean Distance = " << distance << endl;
return 0 ;
}
