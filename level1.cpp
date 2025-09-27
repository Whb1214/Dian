#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

int Seat[10][10][10][10],Floor,Date,User_num;// Seat[date][floor][x][y]
string s,Name;
char str[200];
bool Status = 0;// 1 = ON, 0 = OFF
struct Node
{
	string name_1,date_1;
	int floor_1,x_1,y_1;
 	bool flag = 1;
}info[100005];

void Login()
{   
    if(Status == 1)
	{
		cout << "无效指令" << endl;
		cout << "已经登录过了" << endl;
	}
	if(Status == 0)
	{
		cout << "请输入用户名:" << endl;
	    cin >> s;
	    Name = s;
	    cout << "登录成功" << endl;
	    Status = 1;
	    for(int i = 1;i <= User_num;i++)
	    {
	    	if(info[i].name_1 != Name && info[i].flag == 1)
	    	{
	    		if(info[i].date_1 == "Monday")Seat[1][info[i].floor_1][info[i].x_1][info[i].y_1] = 1;
	    		if(info[i].date_1 == "Tuesday")Seat[2][info[i].floor_1][info[i].x_1][info[i].y_1] = 1;
	    		if(info[i].date_1 == "Wednesday")Seat[3][info[i].floor_1][info[i].x_1][info[i].y_1] = 1;
	    		if(info[i].date_1 == "Thursday")Seat[4][info[i].floor_1][info[i].x_1][info[i].y_1] = 1;
	    		if(info[i].date_1 == "Friday")Seat[5][info[i].floor_1][info[i].x_1][info[i].y_1] = 1;
	    		if(info[i].date_1 == "Saturday")Seat[6][info[i].floor_1][info[i].x_1][info[i].y_1] = 1;
	    		if(info[i].date_1 == "Sunday")Seat[7][info[i].floor_1][info[i].x_1][info[i].y_1] = 1;
			}
		}
    }
}

void Exit()
{
	if(Status == 0)
	{
		cout << "无效指令" << endl;
		cout << "未登录无效操作"<< endl;
	}
	if(Status == 1)
	{
		Status = 0;
		cout << "账户已退出，可以重新登录了" << endl;
		for(int i = 1;i <= User_num;i++)
		{
			if(info[i].date_1 == "Monday")Seat[1][info[i].floor_1][info[i].x_1][info[i].y_1] = 2;
	    	if(info[i].date_1 == "Tuesday")Seat[2][info[i].floor_1][info[i].x_1][info[i].y_1] = 2;
	    	if(info[i].date_1 == "Wednesday")Seat[3][info[i].floor_1][info[i].x_1][info[i].y_1] = 2;
	    	if(info[i].date_1 == "Thursday")Seat[4][info[i].floor_1][info[i].x_1][info[i].y_1] = 2;
	    	if(info[i].date_1 == "Friday")Seat[5][info[i].floor_1][info[i].x_1][info[i].y_1] = 2;
	    	if(info[i].date_1 == "Saturday")Seat[6][info[i].floor_1][info[i].x_1][info[i].y_1] = 2;
	    	if(info[i].date_1 == "Sunday")Seat[7][info[i].floor_1][info[i].x_1][info[i].y_1] = 2;
		}
	}
}


void Pre_read()
{
	freopen("DATA.txt","r",stdin);
	for(int d = 1;d <= 7;d++)
	{
		for(int f = 1;f <= 5;f++)
		{
			for(int i = 1;i <= 4;i++)
			{
				for(int j = 1; j <= 4;j++)
				{
					scanf("%d",&Seat[d][f][i][j]) ;
				    if(Seat[d][f][i][j] == 1 || Seat[d][f][i][j] == 2)User_num++;
				}
			}
		}
	}
	fclose(stdin);
	freopen("User.txt","r",stdin);
	cin >> User_num;
	for(int i = 1;i <= User_num;i++)
	{
		cin >> info[i].name_1 >> info[i].date_1 >> info[i].floor_1 >> info[i].x_1 >> info[i].y_1 >> info[i].flag;
	}
	fclose(stdin);
	freopen("CON","r",stdin);
}


void Save()
{
	freopen("DATA.txt","w",stdout);
	for(int d = 1;d <= 7;d++)
	{
		for(int f = 1;f <= 5;f++)
		{
			for(int i = 1;i <= 4;i++)
			{
				for(int j = 1; j <= 4;j++)
				{
					if(Seat[d][f][i][j] == 1)Seat[d][f][i][j] = 2;
					cout << Seat[d][f][i][j] << " ";
				}
			}
		}
	}
	fclose(stdout);
	freopen("User.txt","w",stdout);
	cout << User_num << endl;
	for(int i = 1;i <= User_num;i++)
	{
		cout << info[i].name_1 << " " << info[i].date_1 << " " << info[i].floor_1 << " " << info[i].x_1 << " " << info[i].y_1 << " " << info[i].flag << endl;
	}
	fclose(stdout);
	freopen("CON","w",stdout);
}

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	Pre_read();
	puts("欢迎使用图书馆管理系统！");
	puts("输入 Login 以登录 用户名支持A-Z");
	puts("请依据 Guide ,勿输入错误指令！！！");
	puts("退出时自动存档,切记输入Quit以存档并退出");
	puts("Guide:");
	puts("Login 登录");
	puts("Exit 退出当前登录");
 	puts("Quit 中止程序");
	puts("Date Floor Num 形如Monday Floor 1的指令 查询某天某层楼的座位情况");
	puts("Reserve Date Floor Num Seat x y 形如Reserve Monday Floor 1 Seat 1 2的指令 预约某天某楼层某位置");
    puts("Reservation 查询当前登录用户的预约情况");
	puts("Clear 清除所有数据");
	puts("Save 保存当前预约信息");
	while(scanf("%s",str))
	{
		s = (string)str;
		if(s == "Quit")
		{
			Save();
			break;
		}
		else if(s != "Quit")
		{
			if(s == "Save")
			{
				Save();
				puts("数据已保存！");
			}
			if(s == "Login")Login();
			if(s == "Exit")Exit();
			if(s == "Monday")
			{
				if(Status == 1)
				{
					Date = 1;
				    string s1;
				    cin >> s1 >> Floor;
				    for(int i = 1;i <= 4;i++)
				    {
					    for(int j = 1;j <= 4;j++)
					    {
						    cout << Seat[Date][Floor][i][j] << " ";
					    }
					cout << endl;
				}
				}
				else cout << "未登录,不可操作" << endl;
			}
			if(s == "Tuesday")
			{
				if(Status == 1)
				{
					Date = 2;
				    string s1;
				    cin >> s1 >> Floor;
				    for(int i = 1;i <= 4;i++)
				    {
					    for(int j = 1;j <= 4;j++)
					    {
						    cout << Seat[Date][Floor][i][j] << " ";
					    }
					cout << endl;
				}
				}
				else cout << "未登录,不可操作" << endl;
			}
			if(s == "Wednesday")
			{
				if(Status == 1)
				{
					Date = 3;
				    string s1;
				    cin >> s1 >> Floor;
				    for(int i = 1;i <= 4;i++)
				    {
					    for(int j = 1;j <= 4;j++)
					    {
						    cout << Seat[Date][Floor][i][j] << " ";
					    }
					cout << endl;
				}
				}
				else cout << "未登录,不可操作" << endl;
			}
			if(s == "Thursday")
			{
				if(Status == 1)
				{
					Date = 4;
				    string s1;
				    cin >> s1 >> Floor;
				    for(int i = 1;i <= 4;i++)
				    {
					    for(int j = 1;j <= 4;j++)
					    {
						    cout << Seat[Date][Floor][i][j] << " ";
					    }
					cout << endl;
				}
				}
				else cout << "未登录,不可操作" << endl;
			}
			if(s == "Friday")
			{
				if(Status == 1)
				{
					Date = 5;
				    string s1;
				    cin >> s1 >> Floor;
				    for(int i = 1;i <= 4;i++)
				    {
					    for(int j = 1;j <= 4;j++)
					    {
						    cout << Seat[Date][Floor][i][j] << " ";
					    }
					cout << endl;
				}
				}
				else cout << "未登录,不可操作" << endl;
			}
			if(s == "Saturday")
			{
				if(Status == 1)
				{
					Date = 6;
				    string s1;
				    cin >> s1 >> Floor;
				    for(int i = 1;i <= 4;i++)
				    {
					    for(int j = 1;j <= 4;j++)
					    {
						    cout << Seat[Date][Floor][i][j] << " ";
					    }
					cout << endl;
				}
				}
				else cout << "未登录,不可操作" << endl;
			}
			if(s == "Sunday")
			{
				if(Status == 1)
				{
					Date = 7;
				    string s1;
				    cin >> s1 >> Floor;
				    for(int i = 1;i <= 4;i++)
				    {
					    for(int j = 1;j <= 4;j++)
					    {
						    cout << Seat[Date][Floor][i][j] << " ";
					    }
					cout << endl;
				}
				}
				else cout << "未登录,不可操作" << endl;
			}
            if(s == "Reserve")
            {
            	string s1,s2,s3;
            	int Floor,x,y;
            	cin >> s1 >> s2 >> Floor >> s3 >> x >> y;
            	if(s1 == "Monday")Date = 1;
            	if(s1 == "Tuesday")Date = 2;
            	if(s1 == "Wednesday")Date = 3;
            	if(s1 == "Thursday")Date = 4;
            	if(s1 == "Friday")Date = 5;
            	if(s1 == "Saturday")Date = 6;
            	if(s1 == "Sunday")Date = 7;
            	if(s2 == "Floor"&&s3 == "Seat")
            	{
            		if(Seat[Date][Floor][x][y] == 0)
            		{
            			User_num++;
            			cout << "OK" << endl;
            			info[User_num].date_1 = s1;
            			info[User_num].floor_1 = Floor;
            			info[User_num].name_1 = Name;
            			info[User_num].x_1 = x;
            			info[User_num].y_1 = y;
            			Seat[Date][Floor][x][y] = 2;
            		}
            		else cout << "座位已被预约! 无法操作" << endl;
				}
			}
			if(s == "Reservation")
			{
				for(int i = 1;i <= User_num;i++)
				{
					if(info[i].name_1 == Name)cout << info[i].date_1 << " " << "Floor" <<" "<< info[i].floor_1 <<" "<< "Seat" <<" "<< info[i].x_1 << " " << info[i].y_1 <<endl;
				}
			}
			if(s == "Clear")
			{
				for(int d = 1;d <= 7;d++)
				{
					for(int f = 1;f <= 5;f++)
					{
						for(int i = 1;i <= 4;i++)
						{
							for(int j = 1;j <= 4;j++)Seat[d][f][i][j] = 0;
						}
					}
				}
				for(int i = 1;i <= User_num;i++)info[i].flag = 0;
	            cout << "数据已清除" << endl;
			}
     	}
	}
}