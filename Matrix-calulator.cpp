#include <bits/stdc++.h>
using namespace std;
class Matrix
{
private:
    int row;
    int column;
public:
    int** arr = new int*[row];
    Matrix(int row, int column)
    {
        this->row = row;
        this->column = column;
        for(int i = 0; i < row; i++)
            arr[i] = new int[column];
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                if(i == j)
                    arr[i][j] = 1;
                else
                    arr[i][j] = 0;
            }
        }
    }
    bool check_value(int row, int column)
    {
        if(row <= 0 || column <= 0)
            return false;
        return true;
    }
    int get_row()
    {
        return row;
    }
    int get_column()
    {
        return column;
    }
    void set_element(int i, int j, int value)
    {
        arr[i][j] = value;
    }
    void set_elements()
    {
        int element = 0;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                cout << "Enter element " << i + 1 << endl;
                cin >> element;
                arr[i][j] = element;
            }
        }
    }
    int get_element(int i, int j)
    {
        return arr[i][j];
    }
    void print()
    {
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    Matrix operator + (Matrix &obj)
    {
        Matrix temp(row,column);
        int value = 0;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                value = get_element(i,j) + obj.get_element(i,j);
                temp.set_element(i,j,value);
            }
        }
        return temp;
    }
    Matrix operator+(int num)
    {
        Matrix temp(row,column);
        int value = 0;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                value = get_element(i,j) + num;
                temp.set_element(i,j,value);
            }
        }
        return temp;
    }
    Matrix operator-(Matrix &obj)
    {
         Matrix temp(row,column);
        int value = 0;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                value = get_element(i,j) - obj.get_element(i,j);
                temp.set_element(i,j,value);
            }
        }
        return temp;
    }
    Matrix operator-(int num)
    {
        Matrix temp(row,column);
        int value = 0;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                value = get_element(i,j) - num;
                temp.set_element(i,j,value);
            }
        }
        return temp;
    }
    Matrix operator*(Matrix &obj)
    {
        Matrix temp(row,obj.get_column());
        int value;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < obj.get_column(); j++)
            {
                value = 0;
                for(int k = 0; k <column; k++)
                {
                    value += arr[i][k]*obj.get_element(k,j);
                }
                temp.set_element(i,j,value);
            }
        }
        return temp;
    }
    Matrix operator*(int num)
    {
        Matrix temp(row,column);
        int value = 0;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0;j < column; j++)
            {
                value = get_element(i,j) * num;
                temp.set_element(i,j, value);
            }
        }
        return temp;
    }
    Matrix transpose()
    {
        Matrix temp(column,row);
        for(int i = 0; i < column; i++)
        {
          for(int j = 0; j < row; j++)
          {
             temp.set_element(i,j,get_element(j,i));
          }
        }
        return temp;
    }
    void print_min(int** mtx, int r ,int c)
    {
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                cout << mtx[i][j] << endl;
            }
        }
    }
    int** minMatrix(int** Mtx, int i, int j, int r, int c)
    {
        int** temp = new int*[r-1];
        for(int i = 0; i < r - 1; i++)
            temp[i] = new int[c-1];
        int  n = 0, m = 0;
        for(int x = 0; x < r; x++)
        {
            for(int y = 0; y < c; y++)
            {
                if(x == i || y == j)
                    continue;
                temp[n][m] = Mtx[x][y];
                m += 1;
                if(m == r-1)
                {
                    n += 1;
                    m = 0;
                }
            }
        }
        return temp;
    }
   int calculateDeterminant(int** M,int r,int c)
   {
       if(r == 2 && c == 2)
       {
           return (M[0][0] * M[1][1]) - (M[0][1] * M[1][0]);
       }
        else
       {
            int res = 0;
            int sign = 0;
            int i =0;
            for(int j = 0; j < r; j++)
            {
                if(sign == 0)
                    res += M[i][j] * calculateDeterminant(minMatrix(M, i, j, r, c), r - 1, c - 1);
                else if(sign == 1)
                    res -= M[i][j] *calculateDeterminant(minMatrix(M, i, j, r, c), r - 1 , c - 1 );
                sign = 1 - sign;
            }
            return res;
       }
   }
};
void menu()
{
    int input = 0, constant = 0, row = 0, column = 0;
    cout << "1- add constant to a matrix" << endl << "2- add two matrices" << endl
    << "3- subtract a constant from matrix" << endl << "4- subtract two matrices" << endl
    << "5- multiply constant to a matrix" << endl << "6- multiply two matrices" << endl
    << "7- Transpose matrix" << endl << "8- calculate determinant" << endl << "9- exit" << endl;
    cin >> input;
    if(input < 1 || input > 10)
        menu();
    if(input == 1)
    {
        cout << "enter the constant" << endl;
        cin >> constant;
        cout << "Enter the dimensions of the matrix" << endl;
        cin >> row >> column;
        Matrix obj(row,column);
        obj.set_elements();
        Matrix obj2(row,column);
        obj2 = obj + constant;
        obj2.print();
    }
    else if(input == 2)
    {
        cout << "Enter the dimensions of the matrices" << endl;
        cin >> row >> column;
        Matrix obj(row,column);
        cout << "First Matrix Info" << endl;
        obj.set_elements();
        Matrix obj2(row,column);
        cout << "second Matrix Info" << endl;
        obj2.set_elements();
        Matrix obj3(row,column);
        obj3 = obj + obj2;
        obj3.print();
    }
    else if(input == 3)
    {
        cout << "enter the constant" << endl;
        cin >> constant;
        cout << "Enter the dimensions of the matrix" << endl;
        cin >> row >> column;
        Matrix obj(row,column);
        obj.set_elements();
        Matrix obj2(row,column);
        obj2 = obj - constant;
        obj2.print();
    }
    else if(input == 4)
    {
        cout << "Enter the dimensions of the matrices" << endl;
        cin >> row >> column;
        Matrix obj(row,column);
        cout << "First Matrix Info" << endl;
        obj.set_elements();
        Matrix obj2(row,column);
        cout << "second Matrix Info" << endl;
        obj2.set_elements();
        Matrix obj3(row,column);
        obj3 = obj - obj2;
        obj3.print();
    }
    else if(input == 5)
    {
        cout << "enter the constant" << endl;
        cin >> constant;
        cout << "Enter the dimensions of the matrix" << endl;
        cin >> row >> column;
        Matrix obj(row,column);
        obj.set_elements();
        Matrix obj2(row,column);
        obj2 = obj * constant;
        obj2.print();
    }
    else if(input == 6)
    {
        cout << "enter the dimensions of the first matrix" << endl;
        cin >> row >> column;
        Matrix obj(row,column);
        obj.set_elements();
        cout << "Enter the dimensions of the second matrix" << endl;
        cin >> row >> column;
        Matrix obj2(row,column);
        obj2.set_elements();
        Matrix obj3(obj.get_row(), obj2.get_column());
        obj3 = obj * obj2;
        obj3.print();
    }
    else if(input == 7)
    {
        cout << "enter the dimensions of the matrix" << endl;
        cin >> row >> column;
        Matrix obj(row,column);
        obj.set_elements();
        obj = obj.transpose();
        obj.print();
    }
    else if(input == 8)
    {
        cout << "enter the dimensions of the matrix" << endl;
        cin >> row >> column;
        Matrix obj(row,column);
        obj.set_elements();
        cout << obj.calculateDeterminant(obj.arr, row, column) << endl;
    }
    else if(input == 9)
         exit(0);
}
int main()
{
    while(true)
    {
        menu();
    }
    return 0;
}
