#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include "stack.h"
using namespace std;

/*
* @Author Alexander Kemos 100375966
* @Version 1.0
* @since 2022-02-12
*/

/*
* Ask user for a file containing a 2D matrix of numbers.
* Store values in a 2D vector.
* Find a continuous path through the matrix starting at 
* the top left and moving to the bottom right,
* where total sum of the path is greater than zero
* while using only ones each position and moving on 4 directions:
* Up, Down, Left and Right.
* Mark path using ‘V’ for down, ‘^’ for up, ‘>’ for right,‘<’ for left,
* ‘X’ where the path ends and ‘-‘ for all other positions in the matrix
* and print the path.
*/

// Please show mercy, I spended 15h on this. I had multiple versions that kinda worked. This is my last attempt I surrender. 

//Initialize a 2D int vector with rows and collumns
// and assign values from iput stream
bool markPosition(vector<vector<int>>& matrix, vector<vector<char>>& chMatrix,
                 unsigned ir, unsigned ic, int sum);
vector<vector<int>> vectorInit(int row, int c, int temp, ifstream & file){
    vector<vector<int>> matrix(row, vector<int>(c, 0));
    for(int i = 0; i < row; i++){
        for (int j = 0; j < c; j++){
            file >> temp;
            matrix[i][j] = temp;
        }
    }
    return matrix;
}



//Ask for a file the user that contain a matrix, 
//Initialize and populate data in a 2D vector
vector<vector<int>> fileInput(ifstream & file, int & row, int & c){
    string fileName, line;
    int temp =0;

   // cout << "Please insert a file with it's path" << endl;
    //cin >> fileName;
    file.open("matrix.txt");
    if (file.is_open()){
        getline(file, line);
        row = stoi(line);
        getline(file, line);
        c = stoi(line);

        vector<vector<int>> matrix = vectorInit(row,c,temp,file);
        return matrix;
    }
    else{
        cout << " Failed to open file. " << endl;
        vector<vector<int>> matrix;
        return matrix;
    }
}

//Print 2D int Vector
void print(vector<vector<int>> matrix){
    cout  << "OG matrix" << endl;
    for(vector<int> x : matrix){
        cout << endl;
        for(int z : x){
            cout << setw(4) << z << " ";
        }
    }
    cout << "\n" << endl;
}

//Print 2D int Vector
void print(vector<vector<bool>> matrix){
    cout  << "OG matrix" << endl;
    for(vector<bool> x : matrix){
        cout << endl;
        for(bool z : x){
            cout << setw(4) << z << " ";
        }
    }
    cout << "\n" << endl;
}

//Print 2D char Vector
void print(vector<vector<char>> matrix){
    cout << "Path matrix" << endl;
    for(vector<char> x : matrix){
        cout << endl;
        for(char z : x){
            cout << setw(4) << z << " ";
        }
    }
    cout << "\n" << endl;
}


void push(stack<int> & , int & , unsigned & , unsigned & , int & , const vector<vector<int>> & , 
            vector<vector<bool>> & , int & , int & , bool & );

void pop(bool &, stack<int> &, int & , 
                    int & , unsigned &, unsigned &, vector<vector<bool>> & ,
                    bool &, const vector<vector<int>> &,
                    int &, int & );

void pop(bool & tried_all, stack<int> & s, int & sum, 
                    int & crd, unsigned & ir, unsigned & ic, vector<vector<bool>> & flagMatrix,
                    bool & find_path, const vector<vector<int>> & matrix,
                    int & prevX, int & prevY){

    if(tried_all && !s.isEmpty()){ 

        //Popping location's data and go to previus
        sum = s.pop();      // This is the current popped sum
        crd = s.pop();      // This is the current direction   //Error here
        prevX = s.pop();
        prevY = s.pop();


        // Get information about current location after pop.
        int temp_sum = s.pop();
        int temp_crd = s.pop();

        ic = s.pop();
        ir = s.peek();

        crd = 0;
        s.push(ic);
        s.push(crd);
        s.push(temp_sum);
        
        flagMatrix[prevX][prevY] = false; //This is little dangerous we fix this by using the direction visited
            /////////////////
        if(s.isEmpty()) { //Not sure here
            // Stack is empty and we have no path.
            // return that we didn't find a path. 
            cout << "WE hit Is Empty" << endl;
            find_path = false;
        }
    }
}

void prev_loc_holder(stack<int> & s, int & prevX, int & prevY){
        int tempSum = s.pop();
        int tempDir = s.pop();
        prevY = s.pop();
        prevX = s.peek();
        s.push(prevY);
        s.push(tempDir);
        s.push(tempSum);
}

void push(stack<int> & s, int & crd, unsigned & ir, unsigned & ic, int & sum, const vector<vector<int>> & matrix, 
            vector<vector<bool>> & flagMatrix, int & prevX, int & prevY, bool & find_path, bool & popFlag){

    // If location up is within bounds, we havent been before and it is not where we came from
    // move up.
    if (crd == 0 && ((int)(ir -1) > 0 && flagMatrix[ir-1][ic] == false && (ir - 1 != (unsigned)prevX && ic != (unsigned)prevY))){

        ir -=1;
        flagMatrix[ir][ic] = true;
        sum += matrix[ir][ic];

        prev_loc_holder(s, prevX, prevY);
        s.push(ir);
        s.push(ic);
        s.push(crd);
        s.push(sum);
        cout << "PRINTING WHEN MOVING TOWARDS UP" << endl;
        print(flagMatrix);
        cout << "Trying ^, sum is " << sum << endl;
        cout << "Current location is [" << ir <<"][" << ic << "]" << endl;
        cout << "PREVIES LOCATION WAS: [" << prevX <<  "][" << prevY << endl;
        crd = 0;


    }else{
        if(crd == 0){
            crd = 1;
        }
    }
    
    // If location down is within bounds, we havent been before and it is not where we came from
    // move down.
    if (crd == 1 && ((ir + 1) < matrix[ir].size() && flagMatrix[ir+1][ic] == false && 
            (ir + 1 != (unsigned)prevX && ic != (unsigned)prevY))){  
        ir +=1;
        flagMatrix[ir][ic] = true;
        sum += matrix[ir][ic];

        prev_loc_holder(s, prevX, prevY);
        s.push(ir);
        s.push(ic);
        s.push(crd);
        s.push(sum);


        cout << "PRINTING WHEN MOVING TOWARDS DOWN" << endl;
        print(flagMatrix);
        cout << "Trying V, sum is " << sum << endl;
        cout << "Current location is [" << ir <<"][" << ic << "]" << endl;
        cout << "PREVIES LOCATION WAS: [" << prevX <<  "][" << prevY << endl;
        crd = 0;
    }else{
        if(crd == 1){
            crd = 2;
        }
    }

    // If location left is within bounds, we havent been before and it is not where we came from
    // move left.
    if (crd == 2 && ((int)(ic - 1) > 0 && flagMatrix[ir][ic-1] == false && (ir != (unsigned)prevX && ic -1 != (unsigned)prevY))){
        ic -=1;
        flagMatrix[ir][ic] = true;
        sum += matrix[ir][ic];

        prev_loc_holder(s, prevX, prevY);
        s.push(ir);
        s.push(ic);
        s.push(crd);
        s.push(sum);
        cout << "PRINTING WHEN MOVING TOWARDS LEFT" << endl;
        print(flagMatrix);
        cout << "Trying <, sum is " << sum << endl;
        cout << "Current location is [" << ir <<"][" << ic << "]" << endl;
        cout << "PREVIES LOCATION WAS: [" << prevX <<  "][" << prevY << endl;
        crd = 0;
    }else{
        if(crd == 2){
            crd = 3;
        }
    }
    
    // If location right is within bounds, we havent been before and it is not where we came from
    // move right.
    if (crd == 3 && ((ic + 1) < matrix.size() && flagMatrix[ir][ic+1] == false && (ir != (unsigned)prevX && ic +1 != (unsigned)prevY))){
        ic +=1;
        flagMatrix[ir][ic] = true;
        sum += matrix[ir][ic];

        prev_loc_holder(s, prevX, prevY);
        s.push(ir);
        s.push(ic);
        s.push(crd);
        s.push(sum);
        cout << "PRINTING WHEN MOVING TOWARDS RIGHT" << endl;
        print(flagMatrix);
        cout << "Trying <, sum is " << sum << endl;
        cout << "Current location is [" << ir <<"][" << ic << "]" << endl;
        cout << "PREVIES LOCATION WAS: [" << prevX <<  "][" << prevY << endl;
        crd = 0;

    } 
    // If we tried all possible pushes, change flag to pop
    else if (crd == 3){
        popFlag = true;
    }
}

void path_found(unsigned ir, unsigned ic, int sum, const vector<vector<int>> & matrix, bool & find_path, bool & popFlag){
    if(ir == matrix.size() && ic == matrix[ir].size()){
        if(sum > 0){
            find_path = false;
            // Print path and terminate
        }else{
            popFlag = true;
        }
    }
}
//Find a valid path from top left to bottom right and
//mark path in char 2D vector.
void pathFinder(const vector<vector<int>> & matrix, vector<vector<char>> & chMatrix,
                 unsigned ir, unsigned ic, vector<vector<bool>> flagMatrix){

    // Setting up conditions environment 
    unsigned counter = 0;
    bool valid_path = false; //Check if we found a valid path with sum positive
    bool find_path = true; //if its true we continue looping
    bool tried_all = false; // Tried to move to all possible directions
    bool popFlag = false; // Go back flag

    
    int crd = 0; // Move up:0 down:1 left:2 right:3
    int sum = matrix[0][0]; // total sum of path at current position
    flagMatrix[0][0] = true;

    stack<int> s;

    // Push the First Node before anything
    s.push(ir);
    s.push(ic);
    s.push(crd);
    s.push(sum);
    int prevX = ir;
    int prevY = ic;

    while(find_path){

        counter++;
        // Move.
        push(s, crd, ir, ic, sum, matrix, 
            flagMatrix, prevX, prevY, find_path, popFlag);

        // Check if path found
        path_found(ic, ir, sum, matrix, find_path, popFlag);

        //If we need to pop, pop
        if (popFlag == true){
            pop(tried_all, s, sum, 
                        crd, ir, ic, flagMatrix,
                        find_path, matrix, prevX, prevY);
        }
    }

    if (counter > matrix.size()*matrix[0].size()*10){
        find_path = false;
    }
}
int main(){
    int row = 0, c = 0;
    ifstream file;
    
    //Create 2D vectors int, char, bool.
    vector<vector<int>> matrix = fileInput(file, row, c);
    vector<vector<char>> chMatrix(row, vector<char>(c, '-'));
    vector<vector<bool>> flagMatrix(row, vector<bool>(c, false));

    print(matrix);

    /*pathFinder( matrix, chMatrix,
                 0, 0, flagMatrix);*/

    print(chMatrix);


    return 0;
}