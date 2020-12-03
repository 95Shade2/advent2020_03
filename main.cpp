#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

vector<char> Char_V(string data) {
    vector<char> data_c;

    for (int c = 0; c < data.size(); c++) {
        data_c.push_back(data[c]);
    }

    return data_c;
}

vector<vector<char>> Get_Trees() {
    vector<vector<char>> ary;
    vector<char> row;
    ifstream file;
    string line;

    file.open("trees.txt");

    getline(file, line);
    while (file) {
        row = Char_V(line);
        ary.push_back(row);
        getline(file, line);
    }

    file.close();

    return ary;
}

void Print(vector<vector<char>> ary, string col_sep, string row_sep) {
    for (int r = 0; r < ary.size(); r++) {
        for (int c = 0; c < ary[r].size(); c++) {
            cout << ary[r][c] << col_sep;
        }
        cout << row_sep;
    }
}

void Update_Movement(vector<vector<char>> ary, double *num_trees, int row, int col) {
    int r = 0;
    int c = 0;

    for (r = 0; r < ary.size(); r+=row) {
        if (ary[r][c] == '#') {
            (*num_trees)++;
        }

        c = (c + col) % ary[r].size();
    }
}

double Trees(vector<vector<char>> ary, int row, int col) {
    double num_trees = 0;

    Update_Movement(ary, &num_trees, row, col);

    cout << "\nNumber of trees hit for " << row << " " << col << " is " << num_trees << endl;

    return num_trees;
}

int main()
{
    vector<vector<char>> ary;
    double tree1, tree2, tree3, tree4, tree5;

    ary = Get_Trees();

    tree1 = Trees(ary, 1, 1);
    tree2 = Trees(ary, 1, 3);
    tree3 = Trees(ary, 1, 5);
    tree4 = Trees(ary, 1, 7);
    tree5 = Trees(ary, 2, 1);

    cout << "\nThe product of the trees is " << fixed << setprecision(0) << tree1 * tree2 * tree3 * tree4 * tree5 << endl;

    return 0;
}
