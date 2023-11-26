
//  头文件
#define NUM1 30
class Students
{
public:
    Students(char *sNane, int cNumber,int sMath,int sEnglish,int sComputer);
    Students()
    {}
    ~Students()
    {}
    char* GetName();
    void SetName(char* sName);//获取姓名
     int GetNumber();
    void SetNumber(int sNumber);//获取学号
    int GetMath();
    void SetMath(int sMath);//获取数学成绩
    int GetEnglish();
    void SetEnglish(int sEnglish);//获取英语成绩
   int GetComputer();
    void SetComputer(int sComputer);//获取计算机成绩
    void disply(Students &st1);

protected:
    char Name[NUM1]={0};
    int Number;
    int  Math;
    int English;
    int Computer;
};