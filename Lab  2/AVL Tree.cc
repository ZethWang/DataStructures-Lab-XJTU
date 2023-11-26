
/*平衡二叉树*/
#include <bits/stdc++.h>
using namespace std;
typedef struct Tree* tree;
int Max(int a,int b);
int GetH (tree T);
tree Insert(tree& T,int x);
tree LeftLeftRotation(tree T);
tree RightRightRotation(tree T);
tree LeftRightRotation(tree T);
tree RightLeftRotation(tree T);
double GetASL(tree index,int depth);
void DeleteTree(tree& T);
void LevelTraversal(tree T);

struct Tree
{
  int x;
  int h;
  char wo;
  tree left;
  tree right;
};

int flag=0;
int main()
{
  int x,cnt=0;
  tree root=NULL;
  while(cin>>x)
  {
    root=Insert(root,x);
    cnt++;
  }
  double ASL=GetASL(root,1)/cnt;
  cout<<"该AVL树层序遍历为:";
  LevelTraversal(root);
  cout<<endl<<"------------------------------------";
  cout<<endl<<"其平均查找长度为:"<<ASL;
  DeleteTree(root);
  return 0;
}
int Max(int a,int b)
{
  return a>b?a:b;
}

int GetH (tree T)
{
  if(!T)return 0;
  if(!T->left)return GetH(T->right)+1;
  else if(!T->right)return GetH(T->left)+1;
  else return Max(GetH(T->left),GetH(T->right))+1;
}

double GetASL(tree index,int depth)
{
  if(!index)return 0;
  return depth+GetASL(index->left,depth+1)+GetASL(index->right,depth+1);
}

tree Insert(tree& T,int x)
{
  if(!T)
  {
    T=new struct Tree;
    T->x=x;
    T->left=T->right=NULL;
    T->h=1;
  }
  else
  {
    if(T->x<x)Insert(T->right,x); //这里也可以T=Insert(),因为如果直接Insert传递的是一个指针拷贝
    else if(T->x>x)Insert(T->left,x); //不会实际修改T->right的值，但也可用引用
    else cout<<"已有该元素"; 
    if(GetH(T->left)-GetH(T->right)==2)  //只有经过的节点平衡因子会改变，无需计算每个节点Height?
    {                                     //因此只需回溯时计算一下就好？但每次计算都要o(logn)的递归,可以在递归时保存到结构体变量中，空间换时间
      if(x>T->left->x) T=LeftRightRotation(T); //这里必须要return 而一般二叉查找树插入无需return
      else T=LeftLeftRotation(T);
    }
    else if(GetH(T->left)-GetH(T->right)==-2)
    {
      if(x>T->right->x) T=RightRightRotation(T);
      else T=RightLeftRotation(T);
    }
  }
  return T;
}

tree LeftLeftRotation(tree T)
{
  tree TL=T->left;
  T->left=TL->right;
  TL->right=T;
  return TL;
}

tree RightRightRotation(tree T)
{
  tree TR=T->right;
  T->right=TR->left;
  TR->left=T;
  return TR;
}

tree LeftRightRotation(tree T)
{
  T->left=RightRightRotation(T->left);
  return LeftLeftRotation(T);
}

tree RightLeftRotation(tree T)
{
  T->right=LeftLeftRotation(T->right);
  return RightRightRotation(T);
}


void DeleteTree(tree& T)
{
  if(T)
  {
    DeleteTree(T->left);
    DeleteTree(T->right);
    delete(T);
  }
}

void LevelTraversal(tree T)
{
  queue<tree> que;
  que.push(T);
  while(!que.empty())
  {
    tree node=que.front();
    que.pop();
    if(flag)cout<<" ";
    cout<<node->x;
    flag=1;
    if(node->left)que.push(node->left);
    if(node->right)que.push(node->right);
  }
}