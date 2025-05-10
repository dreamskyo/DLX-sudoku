
#ifndef __DLX_HPP__
#define __DLX_HPP__

#include<iostream>
#include<vector>
using namespace std;

struct Node {
    Node *L, *R, *U, *D;
    Node *C;  // 所屬欄的 Column Header
    int rowID;  // 該節點對應的 Sudoku 729 行中的哪一列
};
struct Column : Node {
    int S;  // 目前欄中有幾個節點（1的數量）
    int name; // 例如第0~323欄
};

const int N = 9;
const int SIZE = N * N * N; // 729 行
const int COLS = 4 * N * N; // 324 欄

int cellCol(int r, int c);
int rowCol(int r, int num);
int colCol(int c, int num); 
int boxCol(int r, int c, int num);
void initDLX(vector<Column> &columns, Node *&root ,vector<vector<Node*>> &row_nodes);//這裡的傳入值需要注意
void cover(Column* col);
void uncover(Column* col);
Column* selectColumn(Node *&root);
bool search(vector<Node*> &solution, Node *&root, int k);
void applyClues(vector<vector<int>> &sudoku,vector<vector<Node*>> &row_nodes);
void extractAnswer(vector<Node*> &solution, vector<vector<int>> &answer);
void printGrid(vector<vector<int>> grid);

#endif