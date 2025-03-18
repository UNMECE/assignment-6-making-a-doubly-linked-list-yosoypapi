#include "coordinate.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        cout << "Usage" << argv[0] << "<number_of_coordinates\n";
        return 1;
    }
    int num_coords = atoi(argv[1]);
    if(num_coords <= 0)
    {
        cout << "Enter valid number of coordinates\n";
        return 1;
    }
    srand(time(0));
    Coordinate* list_beginning = nullptr;
    Coordinate* list_end = nullptr;
    for(int i=0; i<num_coords; i++)
    {
        float x= (rand() %100) / 10.0;
        float y= (rand() %100) /10.0; 
        add_coordinate(list_end, x, y);
        if(i==0) list_beginning = list_end;
    }
    cout << "Forward Display\n";
    forward_display(list_beginning);
    cout <<  "Backward Display\n";
    backward_display(list_end);
    cout << "Deleting coordinate ID 1\n";
    delete_coordinate(list_beginning, 1);
    forward_display(list_beginning);
    cout << "Finding the closest coordinate to (5.0,5.0)\n";
    closest_to(list_beginning, 5.0, 5.0);

    return 0;
}