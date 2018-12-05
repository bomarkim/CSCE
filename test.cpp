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

//Temporaryly holds a grid so we can read vector<int> objects and not worry
vector<int> tempGrid;
//Holds our objects
vector<int> objects; 

//general input string
string inputStr;

//Name of input file
string filename;


//numberOfObjects in vector<int> objects
int numberOfObjects;
//tempNumberOfObjects for vector<int> tempGrid
int tempNumberOfObjects;
//Side length of all of grid
int sideLength;


//Reads in the grid into inputGrid
void readInGrid(string inputFileName);

//print the vector<string> and vector<int> grids
void printGrid(vector<string> inputGrid);
void printGrid(vector<int> inputGrid);

//Turns a vector<string> grid into a vector<int> grid
void convertStringGridToIntGrid(vector<string> inputGrid);

//Turns a vector<int> grid into a vector<int> objects grid
void convertGridToObjects(vector<int> inputGrid);

int main()
{
    //Get the file name
    cout<<"Hello world";
    cout<<"Please input file name"<<endl;

    cin>>filename;

    readInGrid(filename);
    
    cout<<"Print string Grid"<<endl;
    printGrid(grid);
    
    convertStringGridToIntGrid(grid);

    cout<<"print Temp Grid"<<endl;
    printGrid(tempGrid);

    cout<<"Print objects grid"<<endl;
    printGrid(objects);

    cout<<"Hit anykey to close the program"<<endl;
    cin>>inputStr;
}


void readInGrid(string inputFileName){
//open the stream to the file 
    ifstream inputFile(filename);

    //Check if the file is available to open and okay to do so 
    if(inputFile.is_open()&& inputFile.good())
    {
        //Keep reading lines until we hit the end of the file
        while(!inputFile.eof())
        {
            //for each line, add one to the side Length
           
            getline(inputFile,inputStr);
            istringstream ss(inputStr);
            string segment;

            while(getline(ss,segment,','))
            {
                cout<<segment<<endl;
                grid.push_back(segment);
            }
            cout<<endl;
            sideLength++;
        }
        //to correct for an extra loop of sideLength
        sideLength--;
    }
    else
    {
        cout<<"File could not be opened or is corrupt. "<<endl;
    }
}

//Prints the vector<string> grid 
void printGrid(vector<string> inputGrid)
{
    cout<<"Side Length is "<<sideLength<<endl;
    for(int i = 0; i < inputGrid.size(); i++)
    {
       //If not first loop, print an enter after every side Length
        if(i!=0&&i%sideLength==0)
        {
            cout<<endl;
        }
        cout<<inputGrid.at(i)<<" ";
    }
    cout<<endl;
}
//prints the vector<int> grid
void printGrid(vector<int> inputGrid)
{
    cout<<"Side Length is "<<sideLength<<endl;
    for(int i = 0; i < inputGrid.size(); i++)
    {
       //If not first loop, print an enter after every side Length
        if(i!=0&&i%sideLength==0)
        {
            cout<<endl;
        }
        cout<<inputGrid.at(i)<<" ";
    }
    cout<<endl;
}

//Turns a vector<string> grid into a vector<int> grid
void convertStringGridToIntGrid(vector<string> inputGrid)
{
    for(const auto& val : inputGrid)
    {
        tempGrid.push_back(stoi(val));
    }
    objects=tempGrid;
}

//Turns a vector<int> grid into a vector<int> objects grid
void convertGridToObjects(vector<int> inputGrid)
{

  
  for(int i = 0; i < inputGrid.size(); i++)
  {
      if(i==0)
      
  }
  
    
}