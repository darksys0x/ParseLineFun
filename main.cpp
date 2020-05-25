#include <iostream>
#include<fstream>
#include <string>
#include <sstream>
#include <vector>
using std::vector;
using std::string;
using std::stringstream;
using std::cout;
using std::ifstream;

vector<int> parsFile(string line){
    stringstream mystream(line);
    int n;
    char c;
    vector<int> row;
    while (mystream >> n >> c && c==',')
    {
        row.push_back(n);
    }
    return row;
}



vector<vector<int>> readFile (string path){
    ifstream myfile(path);
    vector<vector<int>> board_pick {};
    
    if(myfile){
        string l;
        while (getline(myfile,l))
        {
            cout<<l<<'\n'<<'\n'<<'\n';
            vector<int> row1 = parsFile(l);
            board_pick.push_back(row1);



        }
        
    }
    return board_pick;
}

//print vector 

void printFile (vector<vector<int>> board){
    for(int i =0 ; i<board.size(); i++ ){
        for (int  j= 0; j< board[i].size(); j++)
        {
            cout<<board[i][j];

        }
        cout<<"\n";
    }
}




int main(){
    auto board = readFile("1.board");

    printFile(board);
}