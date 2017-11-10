#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <utility>

using namespace std;

void shift(int ** & elements,
           unsigned int & result_rows,
           unsigned int & result_columns,
           int k){
    for (int i = 0; i < k; i++){
        for (int j = 0; j < result_columns - 1; j++){
            swap(elements[0][j], elements[0][j + 1]);
        }
        for (int j = 0; j < result_columns - 1; j++){
            swap(elements[j][result_rows - 1], elements[j + 1][result_rows - 1]);
        }
        for (int j = result_rows - 1; j > 0; j--){
            swap(elements[result_columns - 1][j], elements[result_columns - 1][j-1]);
        }
        for (int j = result_columns - 1; j > 1; j--) {
            swap(elements[j][0], elements[j - 1][0]);
        }
    }
}

void create( int ** & elements,
             unsigned int rows,
             unsigned int columns,
             float filler = 0.0f) {

    elements = new int *[ rows ];
    for( unsigned int i = 0; i < rows; ++i ) {
        elements[ i ] = new int[ columns ];
        for( unsigned int j = 0; j < columns; ++j ) {
            elements[ i ][ j ] = filler;
        }
    }
}

bool read_matrix( int ** & elements,
                  unsigned int & result_rows,
                  unsigned int & result_columns,
                  float filler = 0.0f) {
    char symbol;
    string s;
    getline(cin, s);
    istringstream stream(s);
    if ((stream >> result_rows) && (stream >> symbol) && (stream >> result_columns)) {

        create(elements, result_rows, result_columns);

        bool success = true;
        for (int i = 0; i < result_rows && success; ++i) {
            string string;
            getline(cin, string);
            istringstream stream(string);
            for (int j = 0; j < result_columns; ++j) {
                if (!(stream >> elements[j][i])) {
                    success = false;
                    break;
                }
            }
        }

        return success;

    }
    else return false;

}

void write(int ** elements,
           unsigned int rows,
           unsigned int columns) {
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            cout << elements[j][i] << " ";
        }
        cout << endl;
    }

}

int **matrix;

int main() {
    unsigned int result_rows;
    unsigned int result_columns, k;
    if(read_matrix(matrix, result_rows, result_columns)) {
        cin >> k;
        shift(matrix, result_rows, result_columns, k);
        write(matrix, result_rows, result_columns);
    }
    else{
        cout << "An error has occured while reading input data";
    }
    cin.get();
    return 0;
}
