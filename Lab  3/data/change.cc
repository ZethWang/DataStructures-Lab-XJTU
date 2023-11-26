/*二进制文件转换*/

// #include <iostream>
// #include <fstream>
// #include <string>
// using namespace std;
// int main() {
//     std::ifstream fin("data.txt"); // 打开文本文件以供读取
//     std::ofstream fout("input.dat", std::ios::binary); // 创建二进制文件以供写入

//     if (fin.is_open() && fout.is_open()) {
//         string name;
//         int data;

//         while (fin >> name) {
//             fout.write(reinterpret_cast<const char*>(&name[0]),sizeof(name)); // Write the string as binary data
//             for (int i = 0; i < 4; i++) {
//                 fin >> data;
//                 fout.write(reinterpret_cast<const char*>(&data), sizeof(int)); // Write the int as binary data
//             }
//         }

//         fin.close();
//         fout.close();

//         std::cout << "转换完成" << std::endl;
//     } else {
//         std::cerr << "无法打开文件 'data.txt' 或 'input.dat'" << std::endl;
//     }

//     return 0;
// }
