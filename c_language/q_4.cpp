#include <iostream>
using namespace std;

class Rectangle {
private:
    int width;
    int height;

public:
    // Constructor to initialize both width and height
    Rectangle(int w, int h) {
        width = w;
        height = h;
    }

    // Constructor to initialize a square (width = height)
    Rectangle(int side) {
        width = side;
        height = side;
    }

    // Function to display the rectangle or square
    void display() {
        cout << width << "x" << height << endl;
    }
};

int main() {
    // Initialize a rectangle with width=5 and height=3
    Rectangle rect1(5, 3);
    rect1.display();  // Output: 5x3

    // Initialize a square with side=4
    Rectangle rect2(4);
    rect2.display();  // Output: 4x4

    return 0;
}

