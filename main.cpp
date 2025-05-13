#include"DLX.hpp"
using namespace std;

int main(){
    vector<int> cols = {
        cellCol(1, 2),
        rowCol(1, 4),
        colCol(2, 4),
        boxCol(1, 2, 4)
    };
    vector<vector<int>> sudoku(9,vector<int>(9)); // 0 表示空格，其餘是題目的提示數
    vector<vector<int>> answer; // 儲存解答
    vector<Node*> solution;
    vector<Column> columns(COLS);
    Node* root = nullptr;
    vector<vector<Node*>> row_nodes(SIZE); // 每行的節點（最多 4 個）
    // 讀入數獨題目（以空格分隔，0 表空格）
    cout << "請輸入 9x9 數獨（0 表空格）：\n";
    for (int r = 0; r < 9; ++r)
        for (int c = 0; c < 9; ++c)
            cin >> sudoku[r][c];
    answer = sudoku;
    initDLX(columns, root, row_nodes);      // 建立 Dancing Links 結構
    applyClues(sudoku, row_nodes);   // 根據已知數字 cover
    if (search(solution, root, 0)) {
        extractAnswer(solution, answer); // 還原解答
        cout << "\n解答為：\n";
        printGrid(answer);
    } else {
        cout << "找不到解。\n";
	}
    clearDLX(row_nodes, columns, root, solution);
    system("pause");
    return 0;
}
