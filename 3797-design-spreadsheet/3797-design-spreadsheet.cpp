class Spreadsheet {
public:
    vector<vector<int>> grid;
    Spreadsheet(int rows) {
        grid.assign(rows, vector<int> (26, 0));
    }
    
    void setCell(string cell, int value) {
        //cout << cell.substr(1, cell.length()-1) << endl;
        int r = stoi(cell.substr(1, cell.length()-1))-1;
        int c = cell[0]-'A';

        grid[r][c] = value;
    }
    
    void resetCell(string cell) {
        int r = stoi(cell.substr(1, cell.length()-1))-1;
        int c = cell[0]-'A';

        grid[r][c] = 0;
    }
    
    int getValue(string formula) {
        string X = "", Y = "";
        int x = 0, y = 0;
        int ptr = 1;
        while(formula[ptr] != '+'){
            ptr++;
        }

        X = formula.substr(1, ptr-1);
        //cout << X << endl;
        if(formula[1] >= 'A' && formula[1] <= 'Z'){
            int r = stoi(X.substr(1, X.length()-1))-1;
            int c = X[0]-'A';

            x = grid[r][c];
        }

        else{
            x = stoi(X);
        }

        ptr++;
        Y = formula.substr(ptr, formula.length()-ptr);
        //cout << Y << endl;
        if(formula[ptr] >= 'A' && formula[ptr] <= 'Z'){
            int r = stoi(Y.substr(1, Y.length()-1))-1;
            int c = Y[0]-'A';

            y = grid[r][c];
        }

        else{
            y = stoi(Y);
        }

        return x+y;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */