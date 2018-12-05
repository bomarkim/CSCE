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
//int tempNumberOfObjects;

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


    convertGridToObjects(tempGrid);

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

  //Go down the rows and if i is less than sideLength then dont check row above
  //if I is greater than sideLength then check if i-sideLength is not 0
    //if so set equal to i-sideLength (i = i-sideLength)
  //if i is first on row (i %sideLength==0) then dont check the previous cell (i-1)
    //else check if previous cell (i-1) is equal to 0
      //if so continue
      //else i=i-1
    
    //if inputGrid.at(i)!=0
    //if i>sideLength continue else check if (i-sideLength =! 0) then i= i-sideLength
    //if i%sideLength!=0 continue

 string test;

    /**
     * if val[i]!=0
     *  if i>sideLength (if i isnt in first row)
     *    if val[i-sideLength]!=0 (if the cell above it isnt blank)
     *       val[i]= val[i-sideLength] (set it equal to the cell above)
     *  //else  (if i is in first row)
     *   if i % sideLength !=0 (if i isnt in the first column)
     *     if val[i-1]!=0 (if the previous cell has a value)
     *       val[i]=val[i-1]
     *     else (if the previous cell is blank)
     *       val[i]=++numberOfObjects
     *   else (i is in the first column)
     *    val[i]=++numberOfObjects
     * else (cell is blank)
     *   continue
    **/

   /**
    * Need to check left before above
    * 
    **/
  for(int i = 0; i < inputGrid.size(); i++)
  {
      //if the cell is not blank
      if(objects.at(i)!=0)
      {
          //if the cell can have a cell above it
          if(i>sideLength)
          {
              //if the cell above it isn't empty
              if(objects.at(i-sideLength)!=0)
              { 
                  //set the cell to the cell above it
                  objects.at(i)=objects.at(i-sideLength);
              }
          }

          
      }
      //The cell is blank. Move on
      else
      {
          continue;
      }
  }
  
    
}