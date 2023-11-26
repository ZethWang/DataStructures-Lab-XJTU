/*二叉排序树-----------------静态链表*/

// #include <bits/stdc++.h>
// using namespace std;

// void InOrder(int index);
// void insert(int &index, int w);
// void remove(int &index, int w);
// double GetASL(int index, int depth);
// int Max(int a, int b);
// int GetH(int index);
// int Find(int index, int x);
// int FindMax(int index);
// const int N = 2010, INF = 1e8;
// // idx 代表下一个可以使用的空白结点，其中 0 代表空状态，第1个结点位置应该是从1开始
// int l[N], r[N], v[N], idx;

// int main()
// {
//   int n, x, k = 1;
//   cout << "请输入节点个数：" << endl;
//   scanf("%d", &n); // 要插入结点的个数

//   int root = 0;
//   cout << "请输入元素" << endl;
//   for (int i = 0; i < n; i++)
//   {
//     int x;
//     scanf("%d", &x);
//     insert(root, x); // 依次插入到二叉搜索树中
//   }
//   cout << "其中序遍历为:" << endl;
//   InOrder(1);
//   double ASL = GetASL(1, 1) / idx;
//   cout << endl
//        << "其平均查找长度为:" << ASL;
//   cout << endl
//        << "------------------------------------";
//   cout << "\n"
//        << "请输入你想查找的元素:";
//   cin >> x;
//   int index = Find(1, x);
//   if (index)
//   {
//     cout << "它的地址为:" << Find(1, x);
//     remove(k, x);
//     cout << "\n"
//          << "删除" << x << "后的中序遍历为:";
//     InOrder(1);
//   }
// }
// // 最核心的插入操作
// void insert(int &index, int w)
// {
//   if (!index)
//   {
//     index = ++idx; // 类似于Trie字典树，0作为空状态不用（Trie中0代表根节点）
//     v[index] = w;
//   }
//   else if (w < v[index])
//     insert(l[index], w);
//   else
//     insert(r[index], w);
// }

// // 删除操作
// void remove(int &index, int w)
// {
//   if (!index)
//     return; // 如果找不到要删除的值，直接结束
//   if (w < v[index])
//     remove(l[index], w);
//   else if (w > v[index])
//     remove(r[index], w);
//   else
//   {
//     if (!l[index] && !r[index])
//       index = 0; // 如果是叶子结点，直接删除
//     else if (!r[index])
//       index = l[index]; // 如果右子树为空，则左子树替换
//     else if (!l[index])
//       index = r[index]; // 如果左子树为空，则右子树替换
//     else
//     {
//       int p = l[index];
//       // 找到左子树的最大值
//       while (r[p])
//         p = r[p];
//       v[index] = v[p];        // 直接将值进行覆盖，注意不是替换
//       remove(l[index], v[p]); // 然后去左子树中删掉前驱
//     }
//   }
// }

// void InOrder(int index)
// {
//   if (l[index])
//     InOrder(l[index]);
//   printf("%d ", v[index]);
//   if (r[index])
//     InOrder(r[index]);
// }

// double GetASL(int index, int depth)
// {
//   if (!index)
//     return 0;
//   return depth + GetASL(l[index], depth + 1) + GetASL(r[index], depth + 1);
// }

// int Max(int a, int b)
// {
//   return a > b ? a : b;
// }

// int FindMax(int T)
// {
//   if (!T)
//     return 0;
//   while (l[T])
//     T = l[T];
//   return T;
// }

// int GetH(int T)
// {
//   if (!T)
//     return 0;
//   if (!l[T])
//     return GetH(r[T]) + 1;
//   else if (!r[T])
//     return GetH(l[T]) + 1;
//   else
//     return Max(GetH(l[T]), GetH(r[T])) + 1;
// }

// int Find(int T, int x)
// {
//   if (!T)
//   {
//     cout << "查找失败";
//   }
//   else
//   {
//     if (x > v[T])
//       return Find(r[T], x);
//     else if (x < v[T])
//       return Find(l[T], x);
//   }
//   return T;
// }