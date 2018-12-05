/*
Bobby Kim
Nick Tindle
CSCE 2100 - Project 3 - Picture Object Count*/


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;


//Vector of ints of the import 
vector<string> grid;
vector<string> objects; 

string inputStr;

string filename;

int numberOfObjects;
int sideLength;


//Reads in the grid into inputGrid
void readInGrid(vector<string> inputGrid);

//print the vector 
void printGrid(vector<string> inputGrid);

int main()
{
    //Get the file name
    cout<<"Hello world";
    cout<<"Please input file name"<<endl;

    cin>>filename;


    //open the stream to the file 
    ifstream inputFile(filename);

    //Check if the file is available to open and okay to do so 
    if(inputFile.is_open()&& inputFile.good())
    {
        //Keep reading lines until we hit the end of the file
        while(!inputFile.eof())
        {
            //for each line, add one to the side Length
            sideLength++;
            getline(inputFile,inputStr);
            istringstream ss(inputStr);
            string segment;

            while(getline(ss,segment,','))
            {
                cout<<segment<<endl;
                grid.push_back(segment);
            }
        }
    }
    else
    {
        cout<<"File could not be opened or is corrupt. "<<endl;
    }

    
    printGrid(grid);
    
    cout<<"Hit enter to close the program"<<endl;
    cin>>inputStr;
}


void printGrid(vector<string> inputGrid)
{
    
    for(int i = 0; i < inputGrid.size(); i++)
    {
       //If not first loop, print an enter after every side Length
        if(i!=0&&i%sideLength==0)
        {
            cout<<endl;
        }
        cout<<inputGrid.at(i)<<" ";
    }
    
}