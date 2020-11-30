#include <bits/stdc++.h>

using namespace std;

int main() {
  int num; cin >> num;
  vector<int> nums(num);

  for (int &elem: nums) {
    cin >> elem;
  }

  int a, b; cin >> a >> b;

  for (int &elem: nums) {
    if (elem == a) {
      elem = b;
    }
  }

  for (int elem: nums) {
    cout << elem << " ";
  }
}

// int main() {
//   int num; cin >> num;
//   queue<int> nums, nums_1;
//   for (int i = 0, number; i < num / 2; i++) {
//     cin >> number;
//     nums.push(number);
//   }
//   for (int i = 0, number; i < num / 2; i++) {
//     cin >> number;
//     nums_1.push(number);
//   }

//   int moves = 0;

//   for(; !nums.empty() && !nums_1.empty(); ++moves) {
//       int num_1 = nums.front(), num_2 = nums_1.front();
//       nums.pop(); nums_1.pop();
//       queue<int> *win_nums = (num_1 == 0 && num_2 == num - 1) ? &nums : (num_2 == 0 && num_1 == num - 1) ? &nums_1 : (num_1 > num_2) ? &nums : &nums_1;
//       win_nums -> push(num_1); win_nums -> push(num_2);
//   }
//   if (nums.empty()) {
//     cout << "second " << moves << endl;
//   } else if (nums_1.empty()) {
//     cout << "first " << moves << endl;
//   } else {
//     cout << "draw" << endl;
//   }
// }



// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//   int a; cin >> a;
//   int enter;
//   int enter_1;  
//   queue <int> first, second;
  
//   for (int i = 0; i < a / 2; i++)
//     cin >> enter;
//     first.push(enter);
//   for(int j = 0; j < a / 2; j++)
//     cin >> enter_1;
//     second.push(enter_1);
  
//   int moves = 0;
//   for (; !first.empty() && !second.empty(); moves++) {
//     int num = first.front();
//     int num_2 = second.front();
//     first.pop(); second.pop();
//     if(num > num_2){
//       first.push(num);
//       first.push(num_2);
//     }else{
//       second.push(num);
//       second.push(num_2);
//     }
//   }
//   if(first.empty()){
//     cout << "second " << moves;
//   }
//   if(second.empty()){
//     cout << "first " << moves;
//   } else {
//     cout << "draw";
//   }
// }