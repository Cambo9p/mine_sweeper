#include <cstdlib>
#include <time.h>
#include <iostream>
#include <vector>

#define COUTWIDTH std::cout.width(2);std::cout 

const int ROWS = 16;
const int COLS = 16;
char TABLE[ROWS][COLS];

int NUM_MINES = 40;

typedef struct {
    int x;
    int y;
} point_t;

// vector of mine posisitions 
std::vector<point_t> MINES;

// initializes an table that is filled with x's
void initialize_table()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            TABLE[i][j] = 'x';
        }
    }
}

// prints the current table that the user can view 
void print_table() 
{
    std::cout << std::endl;

    // print the x axis on top 
    std::cout << "   "; // double space to match 
    for (int i = 0; i < ROWS; i++)
    {
        COUTWIDTH << i << "|";
    }
    std::cout << std::endl;

    // print table
    for (int i = 0; i < ROWS; i++) 
    {
        // std::cout.width(2);
        COUTWIDTH << i;
        for (int j = 0; j < COLS; j++)
        {
            std::cout << '|';
            COUTWIDTH << TABLE[i][j];
        }
        std::cout << '|' << std::endl;
    }
}

// chooses the areas that contains the mines 
void initialize_mines() 
{
    srand(time(0));
    for (int i = 0; i < NUM_MINES; i++) 
    {
        int x_cord = rand() % ROWS;
        int y_cord = rand() % COLS;
       point_t point = {.x=x_cord,.y=y_cord};
       MINES.push_back(point);
    }
}

// returns true if there is a mine on the point 
bool cord_is_mine(point_t point)
{

    for (auto mine: MINES) 
    {
        if ((mine.x == point.x) && (mine.y == point.y)) 
        {
            return true;
        }
    }
    return false;
}

// view mines on the table 
void view_mines() 
{
    std::cout << std::endl;
    // print the x axis on top 
    std::cout << "   "; // double space to match 
    for (int i = 0; i < ROWS; i++)
    {
        COUTWIDTH << i << "|";
    }
    std::cout << std::endl;
    // print table 
    for (int i = 0; i < ROWS; i++)
    {
        std::cout.width(2);
        std::cout << i;
        for (int j = 0; j < COLS; j++)
        {
            point_t cord = {.x=i,.y=j};
            if (cord_is_mine(cord))
            {
                std::cout << '|';
                COUTWIDTH << 'O';
            }
            else 
            {
                std::cout << '|';
                COUTWIDTH << TABLE[i][j];
            }
        }
        std::cout << '|' << std::endl;
    }
}

int main() 
{
    initialize_table();
    print_table();
    initialize_mines();
    view_mines();
    std::string spot;
    std::cout << "choose a spot" << std::endl;
    std::cin >> spot;
    std::cout << " you chose " << spot << std::endl;


    return 0;
}