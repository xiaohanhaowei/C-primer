#include <iostream>
#include <vector>
#include <string>
using namespace std;
// int main() {
//     vector<int> vi{ 0,1,2,3,4,5,6,7,8,9};
//     auto iter = vi.begin();
//     while (iter != vi.end())  //实时更新end迭代器
//         if (*iter % 2) {
//             int* pointer_inside_buffer=&(*iter);
//             cout << "Original iterator value:" << pointer_inside_buffer << endl; 
//             iter = vi.insert(iter, *iter);//复制当前元素
//             pointer_inside_buffer=&(*iter);
//             cout << "Now      iterator value:" << pointer_inside_buffer << endl; 
//             iter += 2;	
//         } else {
//             iter = vi.erase(iter);
//         }
// }

//证明insert后返回的是新的元素的迭代器。
int main() {
    vector<int> vi={0,1,2,3,4,5};
    vector<int> vi2(10,-1);
    vector<int> vi3{10, 2};
    vector<string> vecs{10, "hi"};
    vector<string> vecs1(10, "hi");
    string vs{"abcdefg"};
    string vs2={"defghijk"};
    auto iter = vi.begin();
    iter += 2;
    auto new_iter = vi.insert(iter, 7);
    cout << "iter value: " << *iter <<endl;
    cout << "new_iter value: " << *new_iter << endl;
    cout << vs <<endl;
    cout << vs2 <<endl;
    cout << vi2.at(0) << endl;
    cout << vi3.at(1) << endl;
    cout << vs0.at(0) << endl;
    cout << vecs3.at(0) << endl;

    return 0;
}