
// /*二叉排序树-----------------二叉链表*/
// #include <bits/stdc++.h>
// using namespace std;
// typedef struct Tree* tree;
// void PreOrderTraversal(tree& T);
// void InOrderTraversal(tree& T);
// double GetASL(tree T,int num);
// int Max(int a,int b);
// int GetH (tree T);
// tree Insert(tree& T,int x);
// tree Find(tree T,int x);
// tree FindMax(tree T);
// tree Delete(tree T,int x);

// struct Tree
// {
//   int x;
//   int h;
//   tree left;
//   tree right;
// };

// int main()
// {
//   tree root=NULL;
//   int x,cnt=0;
//   cout<<"请输入:";
//   while(cin>>x)
//   {
//     root=Insert(root,x);
//     cnt++;
//   }
//   cin.clear(); 
//   int num=0;
//   double ASL=GetASL(root,1)/cnt;
//   cout<<"该二叉排序树中序遍历为:";
//   InOrderTraversal(root);
//   cout<<endl<<"其平均查找长度为:"<<ASL;
//   cout<<endl<<"------------------------------------";
//   cout<<"\n"<<"请输入你想查找的元素:";
//   cin>>x;
//   tree p=Find(root,x);
//   if(p) 
//   {
//     cout<<"它的地址为:"<<Find(root,x);
//     cout<<"\n"<<"删除"<<x<<"后的中序遍历为:";

//     Delete(root,x);
//     InOrderTraversal(root);
//   }

// }

// tree Find(tree T,int x)
// {
//   if(!T)
//   {
//     cout<<"查找失败";
//   }
//   else
//   {
//     if(x>T->x) return Find(T->right,x);
//     else if(x<T->x)return Find(T->left,x);
//   }
//   return T;
// }

// tree Delete(tree T,int x)
// {
//   if(!T)cout<<"无该元素";
//   else
//   {
//     if(x>T->x) T->right=Delete(T->right,x);
//     else if(x<T->x) T->left=Delete(T->left,x);
//     else 
//     {
//       if(T->left&&T->right)  //不要写出左右空
//       {
//         tree temp=FindMax(T->left);
//         T->x=temp->x;
//         T->left=Delete(T->left,temp->x);  //这里不能直接跳到temp,否则找不到父节点
//       }
//       else
//       {
//         tree t=T;
//         if(!T->left) T=T->right;
//         else if(!T->right) T=T->left;
//         free(t);
//       }
//     }
//   }
//   return T;
// }

// tree FindMax(tree T)
// {
//   if(!T)return NULL;
//   while(T->right)T=T->right;
//   return T;
// }

// tree Insert(tree& T,int x)
// {
//   if(!T)
//   {
//     T=new struct Tree;
//     T->x=x;
//     T->left=T->right=NULL;
//     T->h=1;
//   }
//   else
//   {
//     if(T->x<x)Insert(T->right,x); //这里也可以T=Insert(),因为如果直接Insert传递的是一个指针拷贝
//     else if(T->x>x)Insert(T->left,x); //不会实际修改T->right的值，但也可用引用
//     else cout<<"已有该元素"; 
//   }
//   T->h=Max(GetH(T->left),GetH(T->right))+1;
//   return T;
// }

// int Max(int a,int b)
// {
//   return a>b?a:b;
// }

// double GetASL(tree T,int depth)
// {
//   if(!T)return 0;
//   return depth+GetASL(T->left,depth+1)+GetASL(T->right,depth+1);
// }

// int GetH (tree T)
// {
//   if(!T)return 0;
//   if(!T->left)return GetH(T->right)+1;
//   else if(!T->right)return GetH(T->left)+1;
//   else return Max(GetH(T->left),GetH(T->right))+1;
// }

// void InOrderTraversal(tree& T)
// {
//   if(T)
//   {
//     InOrderTraversal(T->left);
//     cout<<T->x<<" ";
//     InOrderTraversal(T->right);
//   }
// }