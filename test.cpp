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
#include <limits>


using namespace std;


//Int.MaxValue
int MaxValue=numeric_limits<int>::max();

//Vector of ints of the import 
vector<string> grid;

//Temporaryly holds a grid so we can read vector<int> objects and not worry
vector<int> tempGrid;
//Holds our objects
vector<int> objects; 

//Holds the objects in the final image
vector<int> objectsInFinalImage;

//general input string
string inputStr;

//Name of input file
string filename;


//numberOfObjects in vector<int> objects
int numberOfObjects=0;
//tempNumberOfObjects for vector<int> tempGrid
int tempNumberOfObjects=1;

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

//Checks the vector<int> grid for any connected pieces and fixes them
void checkGridForConnectingObjects(vector<int> inputGrid);

//Counts the number of objects in the grid
void countNumberOfObjectsInGrid(vector<int> inputGrid);

int main()
{
    //Get the file name
    cout<<"Please input file name"<<endl;

    cin>>filename;

    readInGrid(filename);
    
    convertStringGridToIntGrid(grid);

    convertGridToObjects(tempGrid);
    
    
    for(int i = 0; i < 100; i++)
    {
        checkGridForConnectingObjects(objects);
    }
    
   
    printGrid(objects);
    cout<<endl;

    countNumberOfObjectsInGrid(objects);
    cout<<"Number of objects: "<<numberOfObjects<<endl;    


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
                grid.push_back(segment);
            }
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

    /**For each i
     * if val[i]!=0 (cell is not blank)
     *  if i>=sideLength (if i isnt in first row)
     *    if val[i-sideLength]!=0 (if the cell above it isnt blank)
     *       if i%sideLength!=0 (if the cell isnt the first in the column )
     *          if(val[i-1]!=0) (if the previous cell is elegible)
     *            if(val[i-1]<val[i-sideLength]) (if previous cell is lower num than cell above)
     *              val[i]=val[i-1] (set it equal to cell previous)
     *            else (if previous cell is higher)
     *              val[i]= val[i-sideLength] (set it equal to the cell above)
     *          else (the previous cell is inelegible)
     *            val[i]= val[i-sideLength] (set it equal to the cell above)
     *       else (the cell is in the first row and thus previous is inelegible)
     *        val[i]= val[i-sideLength] (set it equal to the cell above)
     *  - else (the cell in the row above it is blank) 
     *     if i%sideLength!=0 (if its not the first in the column)
     *       if val[i-1]!=0 (if previous cell isnt blank)
     *         val[i]=val[i-1] (value of cell is equal to the one before it because the one above is inelegible)
     *       else (previous cell is blank)
     *         val[i]=++numberOfObjects
     *     else (it is the first in the column)
     *       val[i]=++numberOfObjects
     * else  (if i is in first row)
     *   if i % sideLength !=0 (if i isnt in the first column)
     *     if val[i-1]!=0 (if the previous cell has a value)
     *       val[i]=val[i-1]
     *     else (if the previous cell is blank)
     *       val[i]=++numberOfObjects
     *   else (i is in the first column)
     *    val[i]=++numberOfObjects
     * else (cell is blank)
     *   continue
     * 
     * 
    **/

  for(int i = 0; i < inputGrid.size(); i++)
  {
      //if val[i]!=0 (cell is not blank)
      if(objects.at(i)!=0)
      {
        //if i>=sideLength (if i isnt in first row)
        if(i>=sideLength)
        {
            //if val[i-sideLength]!=0 (if the cell above it isnt blank)
            if(objects.at(i-sideLength)!=0)
            { 
               //if i%sideLength!=0 (if the cell isnt the first in the column )
               if(i%sideLength!=0)
               {
                    if(objects.at(i-1)!=0)
                    {
                        // if(val[i-1]<val[i-sideLength]) (if previous cell is lower num than cell above)
                        if(objects.at(i-1)<objects.at(i-sideLength))
                        {
                            //val[i]=val[i-1] (set it equal to cell previous)
                            objects.at(i)=objects.at(i-1);
                        }
                        //else (if previous cell higher)
                        else
                        {
                            //val[i]= val[i-sideLength] (set it equal to the cell above)
                            objects.at(i)=objects.at(i-sideLength);
                        }
                    }
                    //else (the previous cell is inelegible)
                    else
                    {
                        //val[i]= val[i-sideLength] (set it equal to the cell above)
                        objects.at(i)=objects.at(i-sideLength);
                    }
               }
               //else (the cell is in the first row and thus previous is inelegible)
               else
               {
                    //val[i]= val[i-sideLength] (set it equal to the cell above)
                    objects.at(i)=objects.at(i-sideLength);
               }
            }
            //else (the cell in the row above it is blank) 
            else
            {
                //if i%sideLength!=0 (if its not the first in the column)
                if(i%sideLength!=0)
                {
                    //if val[i-1]!=0 (if previous cell isnt blank)
                    if(objects.at(i-1)!=0)
                    {
                        //val[i]=val[i-1] (value of cell is equal to the one before it because the one above is inelegible)
                        objects.at(i)=objects.at(i-1);
                    }
                    //else (previous cell is blank)
                    else
                    {
                        //val[i]=++numberOfObjects
                        objects.at(i)=++numberOfObjects;
                    }
                }
                //else (it is the first in the column)
                else
                {
                    //val[i]=++numberOfObjects
                    objects.at(i)=++numberOfObjects;
                }
            }
        }
        // else  (if i is in first row)
        else
        {
            //if i % sideLength !=0 (if i isnt in the first column)
            if(i%sideLength!=0)
            {
                //if val[i-1]!=0 (if the previous cell has a value)
                if(objects.at(i-1)!=0)
                {
                    //val[i]=val[i-1]
                    objects.at(i)=objects.at(i-1);
                }
                //else (if the previous cell is blank)
                else
                {
                    // val[i]=++numberOfObjects
                    objects.at(i)=++numberOfObjects;
                }
            }
            //else (i is in the first column)
            else
            {
                // val[i]=++numberOfObjects
                objects.at(i)=++numberOfObjects;
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

//Checks a vector<int> grid for touching objects and fixes them
void checkGridForConnectingObjects(vector<int> inputGrid)
{
    /**
     * Start in top left
     * if the cell is not zero continue
     * go through each side and find out which one is smallest. Set self to smallest if that side is not 0
     * if (i>=side length)    (its not in top  row so check i-sizeLength (above))
     *  if its not zero and its less than smallest set to smallest
     * if(i +sideLength<size) (its not in last row so check i+sizeLength (below))
     *  if its not zero and its less than smallest set to smallest
     * if(i%sideLength!=0)    (its not in left coloumn so check i-1      (left))
     *  if its not zero and its less than smallest set to smallest
     * if(i+1%sideLength==0)  (its not in right coloumn so check i+1     (right))
     *  if its not zero and its less than smallest set to smallest
     * 
     * if smallest has gotten any smaller than int.MaxVal and its less than what is currently there, replace it 
    **/
    for(int i = 0; i < inputGrid.size(); i++)
    {
        //if the cell is 0, go to next cell
        if(objects.at(i)==0)
        {
            continue;
        }

        //set smallest to int.MaxValue after checking to improve mem footprint
        int smallest=MaxValue;

        //if (i>=side length)    (its not in top  row so check i-sizeLength (above))  
        if(i>=sideLength)
        {
            if(objects.at(i-sideLength)!=0)
            {
                if(objects.at(i-sideLength)<smallest)
                {
                    smallest=objects.at(i-sideLength);
                }
            }
        }
        //if(i +sideLength<size) (its not in last row so check i+sizeLength (below))
        if(i+sideLength<inputGrid.size())
        {
            if(objects.at(i+sideLength)!=0)
            {
                if(objects.at(i+sideLength)<smallest)
                {
                    smallest=objects.at(i+sideLength);
                }
            }
        }
        //if(i%sideLength!=0)    (its not in left coloumn so check i-1      (left))
        if(i%sideLength!=0)
        {
            if(objects.at(i-1)!=0)
            {
                if(objects.at(i-1)<smallest)
                {
                    smallest=objects.at(i-1);
                }
            }
        }
        //if(i+1%sideLength!=0)  (its not in right coloumn so check i+1     (right))
        if((i+1)%sideLength!=0&&i+1<inputGrid.size())
        {
            if(objects.at(i+1)!=0)
            {
                if(objects.at(i+1)<smallest)
                {
                    smallest=objects.at(i+1);
                }
            }
        }

        //if smallest has gotten any smaller than int.MaxVal and its less than what is currently there, replace it 
        if(smallest<MaxValue&&smallest<objects.at(i))
        {
            objects.at(i)=smallest;
        }
    }

}

//Counts the number of objects in the grid
void countNumberOfObjectsInGrid(vector<int> inputGrid)
{

    /**
     *  Set num of objects to 0
     *  go through whole grid and if its not a zero 
     *      check if its in the objectsInFinalImage vector
     *          if not, add it
     *  repeat
     * 
     * count size of vector at the end
     **/
    numberOfObjects=0;
    for(int i = 0; i < inputGrid.size(); i++)
    {
        if(inputGrid.at(i)!=0)
        {
            if(find(objectsInFinalImage.begin(), objectsInFinalImage.end(), inputGrid.at(i)) == objectsInFinalImage.end())
            {
                objectsInFinalImage.push_back(inputGrid.at(i));
            }
        }
    }
    numberOfObjects=objectsInFinalImage.size();
}