#include "coordinate.h"
#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;

int list_length(Coordinate* list_beginning)
{
    int length =0;
    Coordinate* temp = list_beginning;
    while(temp)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

void add_coordinate(Coordinate*& list_end, float x, float y)
{
    static int coord_counter =1;
    Coordinate* new_coord = new Coordinate{x, y, coord_counter++, nullptr, list_end};
    if(list_end)
    {
        list_end->next = new_coord;
    }
    list_end = new_coord;
}

void forward_display(Coordinate* list_beginning)
{
    Coordinate* temp= list_beginning;
    while (temp)
    {
        cout << "ID: " << temp->coord_id << " ( " << temp->x << ", " << temp->y << " )\n";
        temp = temp->next;
    }
}

void backward_display(Coordinate* list_end)
{
    Coordinate* temp = list_end;
    while(temp)
    {
        cout << "ID: " << temp->coord_id << " ( " << temp->x << ", " << temp->y << " )\n";
        temp = temp->previous;
    }
}

void delete_coordinate(Coordinate*& list_beginning, int coord_id_to_delete)
{
    while(temp)
    {
        if(temp->coord_id == coord_id_to_delete)
        {
            if(temp->previous) temp->previous->next = temp->next;
            if(temp->next) temp->next->previous = temp->previous;
            if(temp == list_beginning) list_beginning = temp->next;
            delete temp;
            return;
        }
        temp = temp->next;
    }
    cout << "Coordinate with ID " << coord_id_to_delete << " not found.\n";
}

void closest_to(Coordinate* list_beginning, float x, float y)
{
    if(!list_beginning) return;
    Coordinate* closest = nullptr;
    float min_distance = numeric_limits<float>::max();
    Coordinate* temp = list_beginning;
    while(temp)
    {
        float dist = sqrt(pow(temp->x - x, 2) + pow(temp->y - y, 2));
        if(dist < min_distance)
        {
            min_distance = dist;
            closest = temp;
        }
        temp = temp->next;
    }
    if(closest)
    {
        cout << "Closest coordinate to (" << x << ", " << y << ") is ID " 
             << closest->coord_id << " (" << closest->x << ", " << closest->y 
             << ") with distance: " << min_distance << endl;
    }
}
