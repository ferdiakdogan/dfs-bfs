#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"

using namespace std;

int main()
{

//Depth First Traverse Algorithm
    Stack<char> S1;    //for stacking nodes
    Stack<int> S2;      //fro stacking the numbers
    int coun=0,coun2=0;  //two counters for each output

    ifstream MyFile("read.txt");   //reading input from text file
    char x[6][6];                       //array declaration for input to write on

        for(int i=0 ; i<6 ; i++)        //for loop for input writing operation into array
        {
            for(int j=0 ; j<6 ; j++)
            {
                MyFile >> x[i][j];       //read input and write into array
            }
        }

    const char xarray[6]={'A','B','C','D','E','F'};     //array of nodes
    int visited[6];                                     //array of remembering visited nodes
    char output[6]={0,0,0,0,0,0};                       //array of output

    S1.Push(xarray[0]);                     //Push A into Stack S1
    S2.Push(0);                         //Push 0 into Stack S2

    output[0]='A';                      //Write A into first member of output array
    visited[0]=1;                       //Declare A as visited

     for(int i=0 ; i<6 ; i++)           //going through elements of the array starting from first element
        {
            for(int j=0 ; j<6 ; j++)
            {
                if(output[5]!=0)        //when output array is full, finish the loop
                {
                    j=6;                //for breaking from loop
                    i=6;
                }
                while(x[i][j]=='1'&&visited[j]!=1)      //if element of the array is 1 and not visited
                {
                    S1.Push(xarray[j]);                 //Push corresponding node of this element into Stack S1
                    S2.Push(j);                         //Push corresponding number into Stack S2
                    coun++;                             //increment counter
                    output[coun]=xarray[j];             //Write nodes into output array according to counter
                    visited[j]=1;                       //Mark the node as visited
                    i=j;                                //Go to corresponding line(node)
                    j=0;                                //Start from the beginning of the line
                }                                       //We are getting output and writing into output array
                while(j==5)                             //If j is not interrupted until it reaches 5, that means this node is a dead end.
                {
                    S1.Pop();                           //So Pop the last node
                    S2.Pop();                           //And corresponding number
                    i=S2.Peek();                        //Go to top element of the Stack
                    j=0;                                //reset j
                }

            }
        }
  //Breadth First Algorithm
    Queue<char> Q1;                                    //Queuing the nodes
    Queue<int> Q2;                                     //Queuing the numbers corresponding to nodes

    int visited2[6];                                   // Array for remembering visited nodes
    char output2[6]={0,0,0,0,0,0};                     // Array for writing output of BFT

    output2[0]='A';                                    //Write A to first element of output array
    visited2[0]=1;                                     //Mark A as visited


         for(int i=0 ; i<6 ; i++)                      //Go through elements of input array
        {
            for(int j=0 ; j<6 ; j++)
            {
                if(output2[5]!=0)                      //Break from loop if the output is full
                {
                    j=6;
                    i=6;
                }
                while(x[i][j]=='1'&&visited2[j]!=1)     //if the corresponding node is reachable and not visited
                {
                    Q1.QInsert(xarray[j]);              //Insert the node into queue
                    Q2.QInsert(j);                      //Insert corresponding number into queue
                    coun2++;                            //increment counter
                    output2[coun2]=xarray[j];           //Write into the output
                    visited2[j]=1;                      //Mark as visited
                }
                while(j==5)                             //if j is not interrupted until it reaches 5, node is a dead end
                {
                    Q1.QDelete();                       //Delete node from queue
                    i=Q2.QDelete();                     //Delete corresponding number from Queue Q2
                    j=0;                                //reset j
                }

            }
        }
    cout<<"BFT   DFT"<<endl;                            //Write the output arrays corresponding to BFT or DFT algorithms
  for (int k=0; k<6 ; k++)
  {
      cout<<output2[k]<<"     ";
      cout<<output[k]<<endl;
  }
}
