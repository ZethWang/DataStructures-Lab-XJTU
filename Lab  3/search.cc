
#include "student.h"
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
using namespace std;

Students st1[20];
int mm;
int addmain()
{
    std::ifstream fin("input.dat"); // 打开文件以供读取
    if (fin.is_open())
    {
        std::string data;
        cout << "已成功打开文件\n";
    }
    cout << "请输入要添加的学生成绩记录的个数" << endl;
    fin >> mm;
    for (int i = 0; i < mm; i++)
    {
        cout << "正在添加第" << i + 1 << "个学生的成绩记录" << endl;
        char aName[NUM1] = {0};
        int aNumber;
        int aMath;
        int aEnglish;
        int aComputer;
        cout << "请输入需要添加的学生的姓名、学号、数学成绩、英语成绩、计算机成绩" << endl;
        fin >> aName >> aNumber >> aMath >> aEnglish >> aComputer;
        Students st(aName, aNumber, aMath, aEnglish, aComputer);
        st1[i] = st;
        cout << "添加的记录为:" << endl;
        st1[i].disply(st1[i]);
        cout << endl;
    }
    cout << "添加完成" << endl;
    fin.close(); // 关闭文件
    return 0;
} // 添加学生成绩记录
void miodefy()
{
    int num;
    cout << "请输入要修改的学生成绩的学号" << endl;
    cin >> num;
    for (int j = 0; j < mm; j++)
    {
        if (st1[j].GetNumber() == num)
        {
            cout << "要修改的学生的信息为" << endl;
            st1[j].disply(st1[j]);
            char aName[NUM1];
            int aNumber;
            int aMath;
            int aEnglish;
            int aComputer;
            cout << "请输入修改后的学生的姓名、学号、数学成绩、英语成绩、计算机成绩" << endl;
            cin >> aName >> aNumber >> aMath >> aEnglish >> aComputer;
            Students st3(aName, aNumber, aMath, aEnglish, aComputer);
            st1[j] = st3;
            st1[j].disply(st1[j]);
            return;
        }
    }
    cout << "未找到相应的学生的成绩" << endl;
} // 修改学生成绩记录
void deletea()
{
    int num;
    cout << "请输入要删除的学生的学号" << endl;
    cin >> num;
    for (int j = 0; j < mm; j++)
    {
        if (st1[j].GetNumber() == num)
        {
            cout << "要删除的学生的信息为" << endl;
            st1[j].disply(st1[j]);
            for (int j1 = j; j1 < mm - 1; j1++)
            {
                st1[j1] = st1[j1 + 1];
            }
            mm--;
            cout << "删除完成" << endl;
            return;
        }
    }
    cout << "未找到相应的学生的成绩" << endl;
}
void displayall()
{
    for (int i = 0; i < mm; i++)
    {
        st1[i].disply(st1[i]);
    }
} // 全部信息
void chaxun()
{
    int num;
    cout << "请输入要查询的学生成绩的学号" << endl;
    cin >> num;
    for (int j = 0; j < mm; j++)
    {
        if (st1[j].GetNumber() == num)
        {
            st1[j].disply(st1[j]);
            return;
        }
    }
    cout << "未找到相应的学生的成绩" << endl;
} // 按学号查询成绩
void chaxunByName()
{
    char num[100] = {0};
    int flag = 0;
    cout << "请输入要查询的学生姓名" << endl;
    scanf("%s", num);
    for (int j = 0; j < mm; j++)
    {
        if (!strcmp(st1[j].GetName(), num))
        {
            st1[j].disply(st1[j]);
            flag = 1;
        }
    }
    if (!flag)
        cout << "未找到相应的学生的成绩" << endl;
}

void avgs()
{
    double avg[20];
    for (int i1 = 0; i1 < mm; i1++)
    {
        avg[i1] = double((st1[i1].GetEnglish() + st1[i1].GetMath() + st1[i1].GetComputer()) / 3.0);
        cout << st1[i1].GetName() << " " << st1[i1].GetNumber() << " " << avg[i1] << endl;
    }

} // 每人的平均成绩
void avgcm()
{
    double avg = 0;
    for (int i2 = 0; i2 < mm; i2++)
    {
        avg += st1[i2].GetMath();
    }
    avg = avg / mm;
    cout << "数学成绩平均分为:" << avg << endl;
} // 数学成绩平均分
void avgcE()
{
    double avg = 0;
    for (int i2 = 0; i2 < mm; i2++)
    {
        avg += st1[i2].GetEnglish();
    }
    avg = avg / mm;
    cout << "英语成绩平均分为:" << avg << endl;
} // 英语成绩平均分
void avgcc()
{
    double avg = 0;
    for (int i2 = 0; i2 < mm; i2++)
    {
        avg += st1[i2].GetComputer();
    }
    avg = avg / mm;
    cout << "计算机成绩平均分为:" << avg << endl;
} // 计算机成绩平均分
void avgca()
{
    double avg = 0;
    for (int i2 = 0; i2 < mm; i2++)
    {
        avg += st1[i2].GetComputer() + st1[i2].GetEnglish() + st1[i2].GetMath();
    }
    avg = avg / (mm * 3);
    cout << "全部科目成绩平均分为:" << avg << endl;
} // 全部科目成绩平均分
int Max[20];
int maxM[20];
int maxE[20];
int maxC[20];
void temp()
{
    for (int i = 0; i < mm - 1; i++)
        for (int i2 = i + 1; i2 < mm; i2++)
        {
            Max[i] = st1[i].GetComputer() + st1[i].GetEnglish() + st1[i].GetMath();
            Max[i2] = st1[i2].GetComputer() + st1[i2].GetEnglish() + st1[i2].GetMath();
            if (Max[i] > Max[i2])
            {
                int temp;
                temp = Max[i];
                Max[i] = Max[i2];
                Max[i2] = temp;
            }
        }
} // 总成绩排序
void highall()
{
    temp();
    cout << "最高总分为:" << Max[0] << "分" << endl;
} // 最高总成绩
void lowall()
{
    temp();
    cout << "最低总分为:" << Max[mm - 1] << "分" << endl;
} // 最低总成绩
void tempM()
{
    std::ofstream fout("Output/Math.data");
    if (fout.good())
    {
        cout << "文件正常打开" << endl;
    }
    for (int i = 0; i < mm - 1; i++)
    {
        for (int i2 = i + 1; i2 < mm; i2++)
        {
            maxM[i] = st1[i].GetMath();
            maxM[i2] = st1[i2].GetMath();
            if (maxM[i] < maxM[i2])
            {
                Students temp;
                temp = st1[i];
                st1[i] = st1[i2];
                st1[i2] = temp;
            }
        }
        fout << st1[i].GetName() << " " << st1[i].GetMath() << endl;
    }
    fout << st1[mm - 1].GetName() << " " << st1[mm - 1].GetMath() << endl;

} // 数学成绩排序
void highallM()
{
    tempM();
    // cout << "最高数学成绩为:" << maxM[mm - 1] << "分" << endl;
} // 最高数学成绩
void lowallM()
{
    tempM();
    // cout << "最低数学成绩为:" << maxM[0] << "分" << endl;
} // 最低数学成绩
void tempE()
{
    std::ofstream fout("Output/English.data");
    if (fout.good())
    {
        cout << "文件正常打开" << endl;
    }
    for (int i = 0; i < mm - 1; i++)
    {
        for (int i2 = i + 1; i2 < mm; i2++)
        {
            maxE[i] = st1[i].GetEnglish();
            maxE[i2] = st1[i2].GetEnglish();
            if (maxE[i] < maxE[i2])
            {
                Students temp;
                temp = st1[i];
                st1[i] = st1[i2];
                st1[i2] = temp;
            }
        }
        fout << st1[i].GetName() << " " << st1[i].GetEnglish() << endl;
    }
    fout << st1[mm - 1].GetName() << " " << st1[mm - 1].GetEnglish() << endl;

} // 英语成绩排序
void highallE()
{
    tempE();
    // cout << "最高英语成绩为:" << maxE[mm-1] << "分" << endl;
} // 最高英语成绩
void lowallE()
{
    tempE();
    // cout << "最低英语成绩为:" << maxE[0] << "分" << endl;
} // 最低英语成绩
void tempC()
{
    std::ofstream fout("Output/Computer.data");
    if (fout.good())
    {
        cout << "文件正常打开" << endl;
    }
    for (int i = 0; i < mm - 1; i++)
    {
        for (int i2 = i + 1; i2 < mm; i2++)
        {
            maxC[i] = st1[i].GetComputer();
            maxC[i2] = st1[i2].GetComputer();
            if (maxC[i] < maxC[i2])
            {
                Students temp;
                temp = st1[i];
                st1[i] = st1[i2];
                st1[i2] = temp;
            }
        }
        fout << st1[i].GetName() << " " << st1[i].GetComputer() << endl;
    }
    fout << st1[mm - 1].GetName() << " " << st1[mm - 1].GetComputer() << endl;

} // 计算机成绩排序
void highallC()
{
    tempC();
    // cout << "最高计算级成绩为:" << maxC[mm - 1] << "分" << endl;
} // 最高计算机成绩
void lowallC()
{
    tempC();
    // cout << "最低计算机为:" << maxC[0] << "分" << endl;
} // 最低计算机成绩
void sortnumber()
{
    for (int i1 = 0; i1 < mm - 1; i1++)
        for (int i2 = i1 + 1; i2 < mm; i2++)
        {
            if (st1[i1].GetNumber() > st1[i2].GetNumber())
            {
                Students temp;
                temp = st1[i1];
                st1[i1] = st1[i2];
                st1[i2] = temp;
            }
        }
    cout << "按学号排列为:" << endl;
    displayall();
} // 按学号排列
void sortchengji()
{
    std::ofstream fout("Output/avg.dat");
    if (fout.good())
    {
        cout << "文件正常打开" << endl;
    }
    for (int i1 = 0; i1 < mm - 1; i1++)
    {
        for (int i2 = i1 + 1; i2 < mm; i2++)
        {
            Max[i1] = st1[i1].GetComputer() + st1[i1].GetEnglish() + st1[i1].GetMath();
            Max[i2] = st1[i2].GetComputer() + st1[i2].GetEnglish() + st1[i2].GetMath();
            if (Max[i1] < Max[i2])
            {
                Students temp;
                temp = st1[i1];
                st1[i1] = st1[i2];
                st1[i2] = temp;
            }
        }
        fout << st1[i1].GetName() << " " << st1[i1].GetNumber() << " " << (double)(st1[i1].GetEnglish() + st1[i1].GetComputer() + st1[i1].GetMath()) / 3 << endl;
    }
    fout << st1[mm - 1].GetName() << " " << st1[mm - 1].GetNumber() << " " << (double)(st1[mm - 1].GetEnglish() + st1[mm - 1].GetComputer() + st1[mm - 1].GetMath()) / 3 << endl;
    cout << "按成绩降序排列为:" << endl;

} // 按成绩排序
void coun1M()
{
    int count = 0;
    for (int i = 0; i < mm; i++)
    {
        if (st1[i].GetMath() >= 90)
        {
            count++;
        }
    }
    cout << "数学成绩大于等于90分的有" << count << "人" << endl;
}
void coun2M()
{
    int count = 0;
    for (int i = 0; i < mm; i++)
    {
        if (st1[i].GetMath() > 79 && st1[i].GetMath() < 90)
        {
            count++;
        }
    }
    cout << "数学成绩在80-89分的有" << count << "人" << endl;
}
void coun3M()
{
    int count = 0;
    for (int i = 0; i < mm; i++)
    {
        if (st1[i].GetMath() > 69 && st1[i].GetMath() < 80)
        {
            count++;
        }
    }
    cout << "数学成绩在70-79分的有" << count << "人" << endl;
}
void coun4M()
{
    int count = 0;
    for (int i = 0; i < mm; i++)
    {
        if (st1[i].GetMath() > 59 && st1[i].GetMath() < 70)
        {
            count++;
        }
    }
    cout << "数学成绩在60-69分的有" << count << "人" << endl;
}
void coun5M()
{
    int count = 0;
    for (int i = 0; i < mm; i++)
    {
        if (st1[i].GetMath() < 60)
        {
            count++;
        }
    }
    cout << "数学成绩不及格的有" << count << "人" << endl;
}
void coun1C()
{
    int count = 0;
    for (int i = 0; i < mm; i++)
    {
        if (st1[i].GetComputer() >= 90)
        {
            count++;
        }
    }
    cout << "计算机成绩大于等于90分的有" << count << "人" << endl;
}
void coun2C()
{
    int count = 0;
    for (int i = 0; i < mm; i++)
    {
        if (st1[i].GetComputer() > 79 && st1[i].GetComputer() < 90)
        {
            count++;
        }
    }
    cout << "计算机成绩在80-89分的有" << count << "人" << endl;
}
void coun3C()
{
    int count = 0;
    for (int i = 0; i < mm; i++)
    {
        if (st1[i].GetComputer() > 69 && st1[i].GetComputer() < 80)
        {
            count++;
        }
    }
    cout << "计算机成绩在70-79分的有" << count << "人" << endl;
}
void coun4C()
{
    int count = 0;
    for (int i = 0; i < mm; i++)
    {
        if (st1[i].GetComputer() > 59 && st1[i].GetComputer() < 70)
        {
            count++;
        }
    }
    cout << "计算机成绩在60-69分的有" << count << "人" << endl;
}
void coun5C()
{
    int count = 0;
    for (int i = 0; i < mm; i++)
    {
        if (st1[i].GetComputer() < 60)
        {
            count++;
        }
    }
    cout << "计算机成绩不及格的有" << count << "人" << endl;
}
void coun1E()
{
    int count = 0;
    for (int i = 0; i < mm; i++)
    {
        if (st1[i].GetEnglish() >= 90)
        {
            count++;
        }
    }
    cout << "英语成绩大于等于90分的有" << count << "人" << endl;
}
void coun2E()
{
    int count = 0;
    for (int i = 0; i < mm; i++)
    {
        if (st1[i].GetEnglish() > 79 && st1[i].GetEnglish() < 90)
        {
            count++;
        }
    }
    cout << "英语成绩在80-89分的有" << count << "人" << endl;
}
void coun3E()
{
    int count = 0;
    for (int i = 0; i < mm; i++)
    {
        if (st1[i].GetEnglish() > 69 && st1[i].GetEnglish() < 80)
        {
            count++;
        }
    }
    cout << "英语成绩在70-79分的有" << count << "人" << endl;
}
void coun4E()
{
    int count = 0;
    for (int i = 0; i < mm; i++)
    {
        if (st1[i].GetEnglish() > 59 && st1[i].GetEnglish() < 70)
        {
            count++;
        }
    }
    cout << "英语成绩在60-69分的有" << count << "人" << endl;
}
void coun5E()
{
    int count = 0;
    for (int i = 0; i < mm; i++)
    {
        if (st1[i].GetEnglish() < 60)
        {
            count++;
        }
    }
    cout << "英语成绩不及格的有" << count << "人" << endl;
}
void coun1Z()
{
    int count = 0;
    for (int i = 0; i < mm; i++)
    {
        if (double((st1[i].GetComputer() + st1[i].GetEnglish() + st1[i].GetMath()) / 3.0) >= 90)
        {
            count++;
        }
    }
    cout << "平均成绩大于等于90分的有" << count << "人" << endl;
}
void coun2Z()
{
    int count = 0;
    for (int i = 0; i < mm; i++)
    {
        double aa = double(st1[i].GetComputer() + st1[i].GetEnglish() + st1[i].GetMath()) / 3.0;
        if (aa > 79 && aa < 90)
        {
            count++;
        }
    }
    cout << "平均成绩在80-89分的有" << count << "人" << endl;
}
void coun3Z()
{
    int count = 0;
    for (int i = 0; i < mm; i++)
    {
        double aa = double(st1[i].GetComputer() + st1[i].GetEnglish() + st1[i].GetMath()) / 3.0;
        if (aa > 69 && aa < 80)
        {
            count++;
        }
    }
    cout << "平均成绩在70-79分的有" << count << "人" << endl;
}
void coun4Z()
{
    int count = 0;
    for (int i = 0; i < mm; i++)
    {
        double aa = double(st1[i].GetComputer() + st1[i].GetEnglish() + st1[i].GetMath()) / 3.0;
        if (aa > 59 && aa < 70)
        {
            count++;
        }
    }
    cout << "平均成绩在60-69分的有" << count << "人" << endl;
}
void coun5Z()
{
    int count = 0;
    for (int i = 0; i < mm; i++)
    {
        if ((double(st1[i].GetComputer() + st1[i].GetEnglish() + st1[i].GetMath()) / 3.0) < 60)
        {
            count++;
        }
    }
    cout << "平均成绩不及格的有" << count << "人" << endl;
}

void mainloop1()
{
    cout << "输入1:查看全部成绩" << endl;
    cout << "输入2:按学号查询" << endl;
    cout << "输入3:按姓名查询" << endl;
    int xun;
    cin >> xun;
    if (xun == 1)
    {
        displayall();
    }
    else if (xun == 2)
    {
        chaxun();
    }
    else if (xun == 3)
    {
        chaxunByName();
    }
}
void mainloop2()
{
    addmain();
}
void mainloop3()
{
    miodefy();
}
void mainloop4()
{
    deletea();
}
void mainloop5()
{
    avgs();
}
void mainloop6()
{
    cout << "输入 1:查看数学平均成绩" << endl;
    cout << "输入 2:查看英语平均成绩" << endl;
    cout << "输入 3:查看计算机平均成绩" << endl;
    cout << "输入 4:查看总平均成绩" << endl;
    int m;
    cin >> m;
    if (m == 1)
    {
        avgcm();
    }
    else if (m == 2)
    {
        avgcE();
    }
    else if (m == 3)
    {
        avgcc();
    }
    else if (m == 4)
    {
        avgca();
    }
    //  system("pause");
}
void mainloop7()
{
    cout << "输入 1:查看数学最高成绩" << endl;
    cout << "输入 2:查看英语最高成绩" << endl;
    cout << "输入 3:查看计算机最高成绩" << endl;
    cout << "输入 4:查看总最高成绩" << endl;
    int m;
    cin >> m;
    if (m == 1)
    {
        highallM();
    }
    else if (m == 2)
    {
        highallE();
    }
    else if (m == 3)
    {
        highallC();
    }
    else if (m == 4)
    {
        highall();
    }
    //  system("pause");
}
void mainloop8()
{
    cout << "输入 1:查看数学最低成绩" << endl;
    cout << "输入 2:查看英语最低成绩" << endl;
    cout << "输入 3:查看计算机最低成绩" << endl;
    cout << "输入 4:查看总最低成绩" << endl;
    int m;
    cin >> m;
    if (m == 1)
    {
        lowallM();
    }
    else if (m == 2)
    {
        lowallE();
    }
    else if (m == 3)
    {
        lowallC();
    }
    else if (m == 4)
    {
        lowall();
    }
    //  system("pause");
}
void mainloop9()
{
    cout << "输入  1:查看90分及以上人数" << endl;
    cout << "输入 2:查看80~89分人数" << endl;
    cout << "输入 3:查看70~79分人数" << endl;
    cout << "输入 4:查看60~69分人数" << endl;
    cout << "输入 5:查看不及格人数" << endl;
    int i1;
    cin >> i1;
    if (i1 == 1)
    {
        cout << "输入 1:查看数学在此范围内人数" << endl;
        cout << "输入 2:查看英语在此范围内人数" << endl;
        cout << "输入 3:查看计算机在此范围内人数" << endl;
        cout << "输入 4:查看平均成绩在此范围内人数" << endl;
        int jj;
        cin >> jj;
        if (jj == 1)
        {
            coun1M();
        }
        else if (jj == 2)
        {
            coun1E();
        }
        else if (jj == 3)
        {
            coun1C();
        }
        else if (jj == 4)
        {
            coun1Z();
        }
    }
    else if (i1 == 2)
    {
        cout << "输入 1:查看数学在此范围内人数" << endl;
        cout << "输入 2:查看英语在此范围内人数" << endl;
        cout << "输入 3:查看计算机在此范围内人数" << endl;
        cout << "输入 4:查看平均成绩在此范围内人数" << endl;
        int jj;
        cin >> jj;
        if (jj == 1)
        {
            coun2M();
        }
        else if (jj == 2)
        {
            coun2E();
        }
        else if (jj == 3)
        {
            coun2C();
        }
        else if (jj == 4)
        {
            coun2Z();
        }
    }
    else if (i1 == 3)
    {
        cout << "输入 1:查看数学在此范围内人数" << endl;
        cout << "输入 2:查看英语在此范围内人数" << endl;
        cout << "输入 3:查看计算机在此范围内人数" << endl;
        cout << "输入 4:查看平均成绩在此范围内人数" << endl;
        int jj;
        cin >> jj;
        if (jj == 1)
        {
            coun3M();
        }
        else if (jj == 2)
        {
            coun3E();
        }
        else if (jj == 3)
        {
            coun3C();
        }
        else if (jj == 4)
        {
            coun3Z();
        }
    }
    else if (i1 == 4)
    {
        cout << "输入 1:查看数学在此范围内人数" << endl;
        cout << "输入 2:查看英语在此范围内人数" << endl;
        cout << "输入 3:查看计算机在此范围内人数" << endl;
        cout << "输入 4:查看平均成绩在此范围内人数" << endl;
        int jj;
        cin >> jj;
        if (jj == 1)
        {
            coun4M();
        }
        else if (jj == 2)
        {
            coun4E();
        }
        else if (jj == 3)
        {
            coun4C();
        }
        else if (jj == 4)
        {
            coun4Z();
        }
    }
    else if (i1 == 5)
    {
        cout << "输入 1:查看数学在此范围内人数" << endl;
        cout << "输入 2:查看英语在此范围内人数" << endl;
        cout << "输入 3:查看计算机在此范围内人数" << endl;
        cout << "输入 4:查看平均成绩在此范围内人数" << endl;
        int jj;
        cin >> jj;
        if (jj == 1)
        {
            coun5M();
        }
        else if (jj == 2)
        {
            coun5E();
        }
        else if (jj == 3)
        {
            coun5C();
        }
        else if (jj == 4)
        {
            coun5Z();
        }
    }
    //  system("pause");
}
void mainloop10()
{
    sortchengji();
    //  system("pause");
}

int mainlook()
{
    int c;
    cout << endl;
    cout << endl;
    cout << "                          学生成绩管理系统                   " << endl;
    cout << "                    ==========================================" << endl;
    cout << "                        1.学生成绩查询    \t" << endl;
    cout << "                        2.添加学生成绩    \t" << endl;
    cout << "                        3.修改学生成绩    \t" << endl;
    cout << "                        4.删除学生成绩  \t" << endl;
    cout << "                        5.学生平均成绩      \t" << endl;
    cout << "                        6.科目平均成绩      \t" << endl;
    cout << "                        7.学生最高成绩    \t" << endl;
    cout << "                        8.学生最低成绩          \t" << endl;
    cout << "                        9.学生各个分数段人数         \t" << endl;
    cout << "                        10.按成绩降序排列为:           \t" << endl;
    cout << "                  ==========================================" << endl;
    cout << "0-退出    请选择(1-10): \n";
    do
    {
        cout << endl;
        cout << endl;
        cout << "                          学生成绩管理系统                   " << endl;
        cout << "                    ==========================================" << endl;
        cout << "                        1.学生成绩查询    \t" << endl;
        cout << "                        2.添加学生成绩    \t" << endl;
        cout << "                        3.修改学生成绩    \t" << endl;
        cout << "                        4.删除学生成绩  \t" << endl;
        cout << "                        5.学生平均成绩      \t" << endl;
        cout << "                        6.科目平均成绩      \t" << endl;
        cout << "                        7.学生最高成绩    \t" << endl;
        cout << "                        8.学生最低成绩          \t" << endl;
        cout << "                        9.学生各个分数段人数         \t" << endl;
        cout << "                        10.按成绩降序排列为:           \t" << endl;
        cout << "                  ==========================================" << endl;
        cout << "0-退出    请选择(1-10): \n";
        cin >> c;
        switch (c)
        {
        case 1:
            mainloop1();
            break;
        case 2:
            mainloop2();
            break;
        case 3:
            mainloop3();
            break;
        case 4:
            mainloop4();
            break;
        case 5:
            mainloop5();
            break;
        case 6:
            mainloop6();
            break;
        case 7:
            mainloop7();
            break;
        case 8:
            mainloop8();
            break;
        case 9:
            mainloop9();
            break;
        case 10:
            mainloop10();
            break;
        default:
            break;
        }
    } while (c != 0);
    return 0;
}

int main()
{
    mainlook();
    return 0;
}