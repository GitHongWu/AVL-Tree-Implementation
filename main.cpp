//
// HW #07: keeping track of heights
//

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "avl.h"

using namespace std;

int main()
{
    avltree<int, int> avl;
    int x;

    cout << "Enter a key to insert into tree (0 to stop)> ";
    cin >> x;

    while (x > 0)
    {
        avl.insert(x, x);
        cout << "Size: " << avl.size() << endl;
        cout << "Height: " << avl.height() << endl;
        avl.inorder();

        cout << endl;
        cout << "Enter a key to insert into tree (0 to stop)> ";
        cin >> x;
    }

    int d1, d2;
    cout << "Enter key to see the distance (0 to stop)> " << endl;
    cout << "Enter d1: ";
    cin >> d1;
    while(d1 > 0){
        cout << "Enter d2: ";
        cin >> d2;
        int d = avl.distance(d1, d2);
        if (d != -1)
        {
            cout << "distance: " << d << endl;
        }
        else
        {
            cout << "Invalid distance input" << endl;
        }
        cout << "Enter key to see the distance (0 to stop)> " << endl;
        cout << "Enter d1: ";
        cin >> d1;
    }

    return 0;
}
