/**
 * @file maze.cc
 * @author 王子涵(2533897252@qq.com)
 * @brief 迷宫问题求解
 * @date 2023-11-11
 */
#include <bits/stdc++.h>
using namespace std;

//方向数组，分别代表向上、向右、向下、向左移动
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
/* 
O —————————————————————> Y
|
|
|
|
|
|
|
↓
X
*/

/**
 * @brief 定义坐标结构
 */
struct Point
{
    int x, y;
};


vector<vector<int>> maze = {
    {0, 0, 1, 0, 0},
    {1, 1, 0, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0}};

vector<Point> path;


/**
 * @brief 检查(x, y)是否是有效位置 
 * @param maze 迷宫的二维数组
 * @param x 当前的x坐标
 * @param y 当前的y坐标
 * @param visited 记录是否访问过的二维数组
 * @return true 如果位置有效
 * @return false 如果位置无效
 */
bool isValid(const vector<vector<int>> &maze, int x, int y, vector<vector<bool>> &visited)
{
    int m = maze.size();
    int n = maze[0].size();
    return (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0 && !visited[x][y]);
}

/**
 * @brief 递归函数来找出迷宫的路径
 * @param maze 迷宫的二维数组
 * @param x 当前的x坐标
 * @param y 当前的y坐标
 * @param visited 记录是否访问过的二维数组
 * @param path 存储找到的路径的向量
 * @return true 如果找到一条路径
 * @return false 如果未找到路径
 */
bool findPath(vector<vector<int>> &maze, int x, int y, vector<vector<bool>> &visited, vector<Point> &path)
{
    int m = maze.size();
    int n = maze[0].size();

    if (x == m - 1 && y == n - 1)
    {
        path.push_back({x, y});
        return true;
    }

    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (isValid(maze, nextX, nextY, visited))
        {
            if (findPath(maze, nextX, nextY, visited, path))
            {
                path.push_back({x, y});
                return true;
            }
        }
    }

    visited[x][y] = false;
    return false;
}

/**
 * @brief 迷宫求解函数
 * @param maze 迷宫的二维数组
 * @param path 存储找到的路径的向量
 * @return true 如果找到一条路径
 * @return false 如果未找到路径
 */
bool solveMaze(vector<vector<int>> &maze, vector<Point> &path)
{
    int m = maze.size();
    int n = maze[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    return findPath(maze, 0, 0, visited, path);
}

/**
 * @brief 打印迷宫和找到的路径
 * @param maze 迷宫的二维数组
 * @param path 找到的路径
 */
void printMaze(const vector<vector<int>> &maze, const vector<Point> &path)
{
    int m = maze.size();
    int n = maze[0].size();
    vector<vector<char>> visualMaze(m, vector<char>(n, ' '));

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            visualMaze[i][j] = maze[i][j] ? '#' : ' ';
        }
    }

    for (const auto &p : path)
    {
        visualMaze[p.x][p.y] = '.';
    }

    visualMaze[0][0] = 'S';         // Start
    visualMaze[m - 1][n - 1] = 'E'; // End

    for (const auto &row : visualMaze)
    {
        for (char c : row)
        {
            cout << c << ' ';
        }
        cout << '\n';
    }
}

int flag=0;
int main()
{

    if (solveMaze(maze, path))
    {
        cout << "Path found:" << endl;
        reverse(path.begin(), path.end()); // 确保路径是从入口到出口的顺序
        printMaze(maze, path);
        for (int i = 0; i < path.size(); i++)
        {
            Point p = path[i];
            if(flag)cout << "-->";
             cout<<"(" << p.x << ", " << p.y << ")";
             flag=1;
        }
    }
    else
    {
        cout << "No path found." << endl;
    }
    return 0;
}
