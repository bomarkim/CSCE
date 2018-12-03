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

//global vector
vector<string> pic;

//create another global vector
vector<int> objects;

//global string for segmenting data input
string segment;

//keep track of object count
int objNum = 0;

//populate objects function
void populate(vector <string> pic)
{
    //rescan the original vector using a for loop
    for(int i=0; i<pic.size(); ++i)
    {
        //if elem is '0' then push a zero
        if(pic[i] == "0")
        {
            objects.push_back(0);
        }

        else if(pic[i] == "11")
        {
            objects.push_back(1);
        }

        else if(pic[i] == "00")
        {
            objects.push_back(0);
        } 
        //otherwise push back a '1'
        else
        {
            objects.push_back(1);
        }

        //if space is blank, then skip
        // if(pic[i] == " ")
        // {
        //     continue;
        // }
    }

    //find length/size of vector
    int j = pic.size();
    int k = objects.size();

    //find largest divisor(s) for even printing, and other calculations
    //maybe dont do this


    cout << endl << endl; //spaces

    //keep track of format
    int space = 0;
    //return the object vector
    for(int i=0; i<objects.size(); i++)
    {   
        cout << objects[i] << " "; //return the data.
        space += 1;                //how many objects was printed out?

        //if space = 8, newline
        if (space % 7 == 0)
        {
           cout << objects[i] << endl; //new line
        }
    }

    cout << endl << endl; //spaces
    cout << j << " " << k << endl;
    // cout << pic[7] << endl;
    // cout << objects[7] << endl;

}

int main(int argc, char* argv[])
{
    if(argc > 1){
        cout << "opening " << argv[1] << endl;
    }

    else{
        cout << "No file name entered" << endl;
        return 0;
    }

    ifstream infile(argv[1]);

    if(infile.is_open() && infile.good())
    {
        //scan file
        string input;
        //as long as the file is being read 
        while(infile.good())
        {   
            
            //split up text file input by ',' -> push to vector
            while(getline(infile, segment, ','))
            {
                pic.push_back(segment);
            }

        }
    }

    int num = 0;
    int temp;
    //print original vector 
    cout << endl << endl;

    for(int i=0; i<pic.size(); ++i) //for the length of the size of vector...
    {
        cout << pic[i] << " "; //return the data.

        //if zero, push zero
        if(pic[i] == "0"){
            objects.push_back(0);
            continue;
        }

        //if new label detected name it so.
        //if previous and top DNE, then name new label
        if(i<=7)
        {   
            //if current node is not 0 and last elem is 1 then it is an object
            if(i != 0 && pic[i-1] == "1"){
                num = num + 1;
            }

            if(i != 0 && pic[i] == "1" && pic[i - 1] != "0")
            {
                objects.push_back(0);
            } 
        }

        //check if on first line to avoid errors
        if(i>7){
            if(pic[i-1] == "" && pic[i-8] == ""){
                num = num + 1;
                objects.push_back(num);
            }
        
            //if previous neighbor (left) is 0, and above neighbor is 0
            //then node needs a new label
            if(pic[i-1] == "0" && pic[i-8] == "0"){
                num = num + 1;
                objects.push_back(num);
            }

            //if previous neighbor (left) is zero, and top neighbor is not 0 or NULL
            //then this node belongs to the same object as above 
            if(pic[i-1] == "0" && pic[i-8] != "" && pic[i-8] != "0"){
                temp = objects[i-8];
                objects.push_back(temp);
            }
        
            //if previous neighbor (left) is NOT zero, and not NULL
            //then this node belongs to that same object as left
            if(pic[i-1] != "0" && pic[i-1] != ""){
                temp = objects[i-1];
                objects.push_back(temp);
            }

            //find number of objects
            objNum = num;
        }
    }

    cout << endl << endl;

    for (int j = 0; j < objects.size(); ++j) //for the length of the size of vector...
    {
        cout << objects[j] << " "; //return the data

        if(j%8==0)
        {
            cout << endl;
        }
    }

        //populate the objects vector reading the data in the original vector
        //call function to do above
        //populate(pic);

        cout << endl << "number of objects: " << objNum << endl;
        return 0;
}