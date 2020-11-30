#include <bits/stdc++.h>

using namespace std;


auto menu() {
  cout << "1. Add matrices" << endl << "2. Substract matrices" << endl << "3. Multiply matrices" << endl << "4. Calculate matrix 4x4 determinant" << endl << "5. Cramers rule" << endl << "0. Exit" << endl;
  int num; cin >> num;
  return num;
}



auto printmatrix(vector<vector<int>> matrix, int m = 0, int n = 0)  {

  if (m == 0 and n == 0) {
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[i].size(); j++) {
        cout << matrix[i][j] << " ";
      } 
      cout << endl;
    }
  } else {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cout << matrix[i][j] << " ";
      }
      cout << endl;
    }
  }

}



auto addition_matrix(vector<vector<int>> &m, vector<vector<int>> n) {

  if (m.size() != n.size() or m[0].size() != n[0].size()) {
    cout << "The operation cannot be performed" << endl;
  } else {
    for (int i = 0; i < m.size(); i++) {
      for (int j = 0; j < m[i].size(); j++) {
        m[i][j] += n[i][j];
      }
    }
    printmatrix(m);
  }

}



auto substract_matrix(vector<vector<int>> &m, vector<vector<int>> n) {

  if (m.size() != n.size() or m[0].size() != n[0].size()) {
    cout << "The operation cannot be performed" << endl;
  } else {
    for (int i = 0; i < m.size(); i++) {
      for (int j = 0; j < m[i].size(); j++) {
        m[i][j] -= n[i][j];
      }
    }
    printmatrix(m);
  }

}



auto multi_matrix(vector<vector<int>> &m, vector<vector<int>> n, vector<vector<int>> &res) {

  if (m[0].size() == n.size()) {

    for (int i = 0; i < res.size(); i++) {
      for (int j = 0; j < res.size(); j++) {
        res[i][j] = 0;
      }
    }

    for (int i = 0; i < m.size(); i++){
      for (int j = 0; j < n[0].size(); j++) {
        for (int k = 0; k < m[0].size(); k++) {
          res[i][j] += m[i][k] * n[k][j];
        }
      }
    }
    printmatrix(res, m.size(), n[0].size());
  } else {
    cout << "The operation cannot be performed" << endl;
  }

}



auto power(int num){
  if (num % 2 == 0) {
    return 1;
  } else {
    return -1;
  }
}



double calculate_det(vector<vector<double>> data){   
  vector<vector<double>> data_1;
  float determinant = 0, first_row_num;

  // На всякий случай =)
  if (data.size() == 2) {        
    determinant = (data[0][0] * data[1][1] - data[0][1] * data[1][0]);
  } else {        
    for (int i = 0; i < data.size(); i++){            
      first_row_num = data[0][i];
      data_1 = data;
      data_1.erase(data_1.begin());
      for(int j = 0; j < data.size() - 1; j++) {
        data_1[j].erase(data_1[j].begin() + i);
      }
      determinant = determinant + power(i) * first_row_num * calculate_det(data_1);
    }  
  }

  return determinant;
}



auto transpose(vector<vector<int>> &data) {
  vector<vector<int>> data_1(data[0].size(), vector<int>(data.size()));
  for (int i = 0; i < data.size(); i++) {
    for (int j = 0; i < data[i].size(); j++) {
      data[i][j] = data[j][i];
    }
  }
  data = data_1;
}



auto cramers_rule(vector<vector<double>> data, vector<double> results) {
  vector<vector<double>> data_1 = data;
  vector<double> determinants(data.size() + 1);

  for (int i = 0; i < data_1.size(); i++) {
    
    for (int j = 0; j < data_1.size(); j++) {
      data_1[j][i] = results[j];
    }

    determinants[i] = calculate_det(data_1);
    data_1 = data;
  }

  determinants[data.size()] = calculate_det(data);

  cout << "The results are: " << endl;

  for (int i = 0; i < data.size(); i++) {
    cout << i+1 << ": " << determinants[i] / determinants[data.size()] << endl;
  }

  cout << endl;
}



int main() {

  while (true) {
    auto choice = menu();

    if (choice == 0) {
      break;
    } else {

      if (choice == 4) {

        vector<vector<double>> data(4, vector<double>(4));
        cout << "Enter the matrix" << endl;

        for (int i = 0; i < 4; i++) {
          for (int j = 0; j < 4; j++) {
            cin >> data[i][j];
          }
        }

        cout << "The determinant of matrix is: " << calculate_det(data) << endl << endl;
      } else if (choice == 5) {

        cout << "Enter size of square matrix" << endl;
        int num; cin >> num;
        vector<vector<double>> data(num, vector<double>(num));
        vector<double> data_res(num);

        cout << "INPUT UNKOWNS!!! (WITHOUT RESULTS)" << endl;

        for (int i = 0; i < num; i++) {
          for (int j = 0; j < num; j++) {
            cin >> data[i][j];
          }
        }

        cout << "NOW ENTER THE RESULTS OF EACH EQUATION" << endl;

        for (int i = 0; i < num; i++) {
          cin >> data_res[i];
        }

        cramers_rule(data, data_res);

      } else {

        cout << "Enter first matrix size" << endl;
        int a, b; cin >> a >> b;

        vector<vector<int>> data(a, vector<int>(b));
        cout << "Enter first matrix" << endl;
        for (int i = 0; i < a; i++) {
          for (int j = 0; j < b; j++) {
            cin >> data[i][j];
          }
        }

        cout << "Enter second matrix size" << endl;
        int c, d; cin >> c >> d;

        vector<vector<int>> data_1(c, vector<int>(d));
        cout << "Enter second matrix" << endl;
        for (int i = 0; i < c; i++) {
          for (int j = 0; j < d; j++) {
            cin >> data_1[i][j];
          }
        }

        cout << "Result: " << endl;

        if (choice == 1) {
          addition_matrix(data, data_1);
          cout << endl;
        } else if (choice == 2) {
          substract_matrix(data, data_1);
          cout << endl;
        } else if (choice == 3) {
          vector<vector<int>> res(10, vector<int>(10));
          multi_matrix(data, data_1, res);
          cout << endl;
        } 
      }
    }
  }
  
}