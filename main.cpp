#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void printMatrix(vector<vector<int>> matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

void insertRowBefore(int &m, int n, vector<vector<int>> &matrix, long arg) {
    vector<vector<int>> tmpMatrix;
    int num, flag = 0;

    //cout << matrix[1][0];
    for (int i = 0; i < m + 1; i++) {
        vector<int> v;
        if (i != arg - 1) {
            for (int j = 0; j < n; j++) {
                if (flag == 1)
                    v.push_back(matrix[i - 1][j]);
                else
                    v.push_back(matrix[i][j]);
            }
        } else {
            //cout << "i = " << i << endl;
            for (int j = 0; j < n; j++) {
                cin >> num;
                v.push_back(num);
                flag = 1;
            }
        }
        tmpMatrix.push_back(v);
    }
    matrix.clear();
    m++;
    for (int i = 0; i < m; i++) {
        vector<int> v;
        for (int j = 0; j < n; j++) {
            v.push_back(tmpMatrix[i][j]);
        }
        matrix.push_back(v);
    }
}

void insertRowAfter(int &m, int n, vector<vector<int>> &matrix, long arg) {
    vector<vector<int>> tmpMatrix;
    int num, flag = 0;

    for (int i = 0; i < m + 1; i++) {
        vector<int> v;
        if (i == arg) {
            for (int j = 0; j < n; j++) {
                cin >> num;
                v.push_back(num);
                flag = 1;
            }
        } else {
            for (int j = 0; j < n; j++) {
                if (flag == 1)
                    v.push_back(matrix[i - 1][j]);
                else
                    v.push_back(matrix[i][j]);
            }
        }
        tmpMatrix.push_back(v);
    }
    matrix.clear();
    m++;
    for (int i = 0; i < m; i++) {
        vector<int> v;
        for (int j = 0; j < n; j++) {
            v.push_back(tmpMatrix[i][j]);
        }
        matrix.push_back(v);
    }
}

void insertColumnBefore(int m, int &n, vector<vector<int>> &matrix, long arg) {
    vector<vector<int>> tmpMatrix;
    int num, flag = 0;
    for (int i = 0; i < m; i++) {
        vector<int> v;
        for (int j = 0; j < n + 1; j++) {
            if (j == arg - 1) {
                cin >> num;
                v.push_back(num);
                flag++;
            } else {
                if (flag == 1) {
                    v.push_back(matrix[i][j - 1]);
                } else
                    v.push_back(matrix[i][j]);
            }
        }
        flag = 0;
        tmpMatrix.push_back(v);
    }
    n++;
    matrix.clear();
    for (int i = 0; i < m; i++) {
        vector<int> v;
        for (int j = 0; j < n; j++) {
            v.push_back(tmpMatrix[i][j]);
        }
        matrix.push_back(v);
    }
}

void insertColumnAfter(int m, int &n, vector<vector<int>> &matrix, long arg) {
    vector<vector<int>> tmpMatrix;
    int num, flag = 0;
    for (int i = 0; i < m; i++) {
        vector<int> v;
        for (int j = 0; j < n + 1; j++) {
            if (j == arg) {
                cin >> num;
                v.push_back(num);
                flag++;
            } else {
                if (flag == 1) {
                    v.push_back(matrix[i][j - 1]);
                } else
                    v.push_back(matrix[i][j]);
            }
        }
        flag = 0;
        tmpMatrix.push_back(v);
    }
    n++;
    matrix.clear();
    for (int i = 0; i < m; i++) {
        vector<int> v;
        for (int j = 0; j < n; j++) {
            v.push_back(tmpMatrix[i][j]);
        }
        matrix.push_back(v);
    }
}

void deleteRow(int &m, int n, vector<vector<int>> &matrix, long arg) {
    vector<vector<int>> tmpMatrix;
    for (int i = 0; i < m; i++) {
        vector<int> v;
        if (i == arg - 1)
            continue;
        else {
            for (int j = 0; j < n; j++) {
                v.push_back(matrix[i][j]);
            }
        }
        tmpMatrix.push_back(v);
    }
    m--;
    matrix.clear();
    for (int i = 0; i < m; i++) {
        vector<int> v;
        for (int j = 0; j < n; j++) {
            v.push_back(tmpMatrix[i][j]);
        }
        matrix.push_back(v);
    }
}

void deleteColumn(int m, int &n, vector<vector<int>> &matrix, long arg) {
    vector<vector<int>> tmpMatrix;
    for (int i = 0; i < m; i++) {
        vector<int> v;
        for (int j = 0; j < n; j++) {
            if (j != arg - 1) {
                v.push_back(matrix[i][j]);
            }
        }
        tmpMatrix.push_back(v);
    }

    n--;
    matrix.clear();
    for (int i = 0; i < m; i++) {
        vector<int> v;
        for (int j = 0; j < n; j++) {
            v.push_back(tmpMatrix[i][j]);
        }
        matrix.push_back(v);
    }
}

void swapRows(int m, int n, vector<vector<int>> &matrix, long arg1, long arg2) {
    vector<vector<int>> tmpMatrix;
    vector<int> tmp1;
    vector<int> tmp2;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == arg1 - 1) {
                tmp1.push_back(matrix[i][j]);
            } else if (i == arg2 - 1) {
                tmp2.push_back(matrix[i][j]);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        vector<int> v;
        for (int j = 0; j < n; j++) {
            v.push_back(matrix[i][j]);
        }
        if (i == arg1 - 1)
            tmpMatrix.push_back(tmp2);
        else if (i == arg2 - 1)
            tmpMatrix.push_back(tmp1);
        else
            tmpMatrix.push_back(v);
    }

    matrix.clear();
    for (int i = 0; i < m; i++) {
        vector<int> v;
        for (int j = 0; j < n; j++) {
            v.push_back(tmpMatrix[i][j]);
        }
        matrix.push_back(v);
    }
}

void swapColumns(int m, int n, vector<vector<int>> &matrix, long arg1, long arg2) {
    vector<vector<int>> tmpMatrix;
    vector<int> tmp1;
    vector<int> tmp2;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j == arg1 - 1) {
                tmp1.push_back(matrix[i][j]);
            } else if (j == arg2 - 1)
                tmp2.push_back(matrix[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        vector<int> v;
        for (int j = 0; j < n; j++) {
            if (j == arg1 - 1)
                v.push_back(tmp2[i]);
            else if (j == arg2 - 1)
                v.push_back(tmp1[i]);
            else
                v.push_back(matrix[i][j]);
        }
        tmpMatrix.push_back(v);
    }

    matrix.clear();
    for (int i = 0; i < m; i++) {
        vector<int> v;
        for (int j = 0; j < n; j++) {
            v.push_back(tmpMatrix[i][j]);
        }
        matrix.push_back(v);
    }
}

void transposeMatrix(int &m, int &n, vector<vector<int>> &matrix) {
    int newM = n, newN = m;
    vector<vector<int>> tmpMatrix;
    for (int i = 0; i < n; i++) {
        vector<int> v;
        for (int j = 0; j < m; j++) {
            v.push_back(matrix[j][i]);
        }
        tmpMatrix.push_back(v);
    }

    m = newM;
    n = newN;
    matrix.clear();
    for (int i = 0; i < m; i++) {
        vector<int> v;
        for (int j = 0; j < n; j++) {
            v.push_back(tmpMatrix[i][j]);
        }
        matrix.push_back(v);
    }
}

int main(int argc, char **argv) {
    int m, n, num;
    cin >> m;
    cin >> n;
    vector<vector<int>> matrix;
    for (int i = 0; i < m; i++) {
        vector<int> v;
        for (int j = 0; j < n; j++) {
            cin >> num;
            v.push_back(num);
        }
        matrix.push_back(v);
    }

    //cout << " *** BEFORE *** " << endl;
    //printMatrix(matrix);


    if (argc < 2) {
        //cout << "argc < 2" << endl;
        printMatrix(matrix);
        return 0;
    } else {
        string command;
        command = argv[1];
        char *ptr;
        long arg, arg2;
        if (command == "-irb") {
            if (argc == 3) {
                arg = strtol(argv[2], &ptr, 10);
                if (arg > 0 && arg <= m)
                    insertRowBefore(m, n, matrix, arg);
            }
        } else if (command == "-ira") {
            if (argc == 3) {
                arg = strtol(argv[2], &ptr, 10);
                if (arg > 0 && arg <= m)
                    insertRowAfter(m, n, matrix, arg);
            }

        } else if (command == "-icb") {
            if (argc == 3) {
                arg = strtol(argv[2], &ptr, 10);
                if (arg > 0 && arg <= n) {
                    insertColumnBefore(m, n, matrix, arg);
                }
            }
        } else if (command == "-ica") {
            if (argc == 3) {
                arg = strtol(argv[2], &ptr, 10);
                if (arg > 0 && arg <= n) {
                    insertColumnAfter(m, n, matrix, arg);
                }
            }
        } else if (command == "-dr") {
            if (argc == 3) {
                arg = strtol(argv[2], &ptr, 10);
                if (arg > 0 && arg <= m) {
                    deleteRow(m, n, matrix, arg);
                }
            }
        } else if (command == "-dc") {
            if (argc == 3) {
                arg = strtol(argv[2], &ptr, 10);
                if (arg > 0 && arg <= n)
                    deleteColumn(m, n, matrix, arg);
            }
        } else if (command == "-sr") {
            if (argc == 4) {
                arg = strtol(argv[2], &ptr, 10);
                arg2 = strtol(argv[3], &ptr, 10);
                if ((arg > 0 && arg <= m) && (arg2 > 0 && arg2 <= m) && arg != arg2)
                    swapRows(m, n, matrix, arg, arg2);
            }

        } else if (command == "-sc") {
            if (argc == 4) {
                arg = strtol(argv[2], &ptr, 10);
                arg2 = strtol(argv[3], &ptr, 10);
                if ((arg > 0 && arg <= n) && (arg2 > 0 && arg2 <= n) && arg != arg2)
                    swapColumns(m, n, matrix, arg, arg2);
            }
        } else if (command == "-t") {
            if (argc == 2)
                transposeMatrix(m, n, matrix);

        } else {
            //cout << "NOT A VIABLE COMMAND. TRY AGAIN!" << endl;
            printMatrix(matrix);
            return 0;
        }
        //cout << " *** AFTER *** " << endl;
        printMatrix(matrix);
    }
    return 0;
}
