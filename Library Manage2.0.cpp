#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

int Seat[10][10][10][10],Floor,Date,User_num;// Seat[date][floor][x][y]
string s,Name;
char str[200];
bool Status = 0,Key = 0;// 1 = ON, 0 = OFF
struct Node
{
	string name_1,date_1;
	int floor_1,x_1,y_1;
	bool flag = 1; // 检测该预约是否有效 1 = 有效 0 = 无效
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
	    		if(info[i].date_1 == "Monday" && Seat[1][info[i].floor_1][info[i].x_1][info[i].y_1] != 3)Seat[1][info[i].floor_1][info[i].x_1][info[i].y_1] = 1;
	    		if(info[i].date_1 == "Tuesday" && Seat[2][info[i].floor_1][info[i].x_1][info[i].y_1] != 3)Seat[2][info[i].floor_1][info[i].x_1][info[i].y_1] = 1;
	    		if(info[i].date_1 == "Wednesday" && Seat[3][info[i].floor_1][info[i].x_1][info[i].y_1] != 3)Seat[3][info[i].floor_1][info[i].x_1][info[i].y_1] = 1;
	    		if(info[i].date_1 == "Thursday" && Seat[4][info[i].floor_1][info[i].x_1][info[i].y_1] != 3)Seat[4][info[i].floor_1][info[i].x_1][info[i].y_1] = 1;
	    		if(info[i].date_1 == "Friday" && Seat[5][info[i].floor_1][info[i].x_1][info[i].y_1] != 3)Seat[5][info[i].floor_1][info[i].x_1][info[i].y_1] = 1;
	    		if(info[i].date_1 == "Saturday" && Seat[6][info[i].floor_1][info[i].x_1][info[i].y_1] != 3)Seat[6][info[i].floor_1][info[i].x_1][info[i].y_1] = 1;
	    		if(info[i].date_1 == "Sunday" && Seat[7][info[i].floor_1][info[i].x_1][info[i].y_1] != 3)Seat[7][info[i].floor_1][info[i].x_1][info[i].y_1] = 1;
			}
			if(info[i].name_1 == Name && info[i].flag == 1)
			{ 
			    
	    		if(info[i].date_1 == "Monday" && Seat[1][info[i].floor_1][info[i].x_1][info[i].y_1] != 3)Seat[1][info[i].floor_1][info[i].x_1][info[i].y_1] = 2;
	    		if(info[i].date_1 == "Tuesday" && Seat[2][info[i].floor_1][info[i].x_1][info[i].y_1] != 3)Seat[2][info[i].floor_1][info[i].x_1][info[i].y_1] = 2;
	    		if(info[i].date_1 == "Wednesday" && Seat[3][info[i].floor_1][info[i].x_1][info[i].y_1] != 3)Seat[3][info[i].floor_1][info[i].x_1][info[i].y_1] = 2;
	    		if(info[i].date_1 == "Thursday" && Seat[4][info[i].floor_1][info[i].x_1][info[i].y_1] != 3)Seat[4][info[i].floor_1][info[i].x_1][info[i].y_1] = 2;
	    		if(info[i].date_1 == "Friday" && Seat[5][info[i].floor_1][info[i].x_1][info[i].y_1] != 3)Seat[5][info[i].floor_1][info[i].x_1][info[i].y_1] = 2;
	    		if(info[i].date_1 == "Saturday" && Seat[6][info[i].floor_1][info[i].x_1][info[i].y_1] != 3)Seat[6][info[i].floor_1][info[i].x_1][info[i].y_1] = 2;
	    		if(info[i].date_1 == "Sunday" && Seat[7][info[i].floor_1][info[i].x_1][info[i].y_1] != 3)Seat[7][info[i].floor_1][info[i].x_1][info[i].y_1] = 2;
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
		Key = 0;
		cout << "账户已退出，可以重新登录了" << endl;
		for(int i = 1;i <= User_num;i++)
		{
			if(info[i].date_1 == "Monday" && info[i].flag == 1)Seat[1][info[i].floor_1][info[i].x_1][info[i].y_1] = 2;
	    	if(info[i].date_1 == "Tuesday" && info[i].flag == 1)Seat[2][info[i].floor_1][info[i].x_1][info[i].y_1] = 2;
	    	if(info[i].date_1 == "Wednesday" && info[i].flag == 1)Seat[3][info[i].floor_1][info[i].x_1][info[i].y_1] = 2;
	    	if(info[i].date_1 == "Thursday" && info[i].flag == 1)Seat[4][info[i].floor_1][info[i].x_1][info[i].y_1] = 2;
	    	if(info[i].date_1 == "Friday" && info[i].flag == 1)Seat[5][info[i].floor_1][info[i].x_1][info[i].y_1] = 2;
	    	if(info[i].date_1 == "Saturday" && info[i].flag == 1)Seat[6][info[i].floor_1][info[i].x_1][info[i].y_1] = 2;
	    	if(info[i].date_1 == "Sunday" && info[i].flag == 1)Seat[7][info[i].floor_1][info[i].x_1][info[i].y_1] = 2;
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
	for(int i = 1;i <= User_num;i++)
	{
		cout << info[i].name_1 << " " << info[i].date_1 << " " << info[i].floor_1 << " " << info[i].x_1 << " " << info[i].y_1 << " " << info[i].flag << endl;
	}
	fclose(stdout);
}

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	Pre_read();
	puts("欢迎使用图书馆管理系统！");
	puts("输入 Login 以登录 用户名支持A-Z");
	puts("输入 Guide 以查询指令列表");
	puts("在登录后输入 Admin 以管理员身份进入 拥有更多权限");
	puts("PS:管理员权限退出登录后清除,有需要重新键入指令即可!");
	puts("请依据 Guide ,勿输入错误指令！！！");
	puts("退出时自动存档,切记输入Quit以存档并退出");
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
			if(s == "Guide")
			{
				puts("普通模式指令如下:");
				puts("Login 登录");
				puts("Exit 退出当前登录");
				puts("Quit 中止程序");
				puts("Date Floor Num 形如Monday Floor 1的指令 查询某天某层楼的座位情况");
				puts("Reserve Date Floor Num Seat x y 形如Reserve Monday Floor 1 Seat 1 2的指令 预约某天某楼层某位置");
				puts("Reservation 查询当前登录用户的预约情况");
				puts("Clear 清除所有数据");
				puts("Save 保存当前预约信息");
				puts("管理员模式额外指令如下:");
				puts("Help A/B/C/... Reserve Date Floor Num Seat x y 可以为自己或其他人预约座位");
				puts("Cancel A Reservation/Cancel Date Floor Num Seat x y/Cancel Floor x 取消某人预约或取消某座位或取消某层楼的预约");
				puts("Delete Floor Num Seat x y 直接撤销某层楼某个座位");
				puts("Reset Floor Num Seat x y 恢复被撤销的座位");
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
					    	if(Seat[Date][Floor][i][j] != 3)cout << Seat[Date][Floor][i][j] << " ";
					    	else cout << "X" << " ";
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
						    if(Seat[Date][Floor][i][j] != 3)cout << Seat[Date][Floor][i][j] << " ";
					    	else cout << "X" << " ";
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
						    if(Seat[Date][Floor][i][j] != 3)cout << Seat[Date][Floor][i][j] << " ";
					    	else cout << "X" << " ";
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
						    if(Seat[Date][Floor][i][j] != 3)cout << Seat[Date][Floor][i][j] << " ";
					    	else cout << "X" << " ";
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
						    if(Seat[Date][Floor][i][j] != 3)cout << Seat[Date][Floor][i][j] << " ";
					    	else cout << "X" << " ";
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
						    if(Seat[Date][Floor][i][j] != 3)cout << Seat[Date][Floor][i][j] << " ";
					    	else cout << "X" << " ";
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
						    if(Seat[Date][Floor][i][j] != 3)cout << Seat[Date][Floor][i][j] << " ";
					    	else cout << "X" << " ";
					    }
					cout << endl;
				}
				}
				else cout << "未登录,不可操作" << endl;
			}
            if(s == "Reserve" && Status == 1)
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
            		else cout << "座位已被预约/被撤销! 无法操作" << endl;
				}
			}
			if(s == "Reservation")
			{
				if(Status != 1)
				{
					cout << "未登录,不可操作" << endl;
					continue;
				}
				int cnt = 0;
				for(int i = 1;i <= User_num;i++)
				{
					if(info[i].name_1 == Name)
					{
						cout << info[i].date_1 << " " << "Floor" <<" "<< info[i].floor_1 <<" "<< "Seat" <<" "<< info[i].x_1 << " " << info[i].y_1 <<endl;
						++cnt;
					}
				}
				if(cnt == 0)puts("当前用户仍未预约座位!");
			}
			if(s == "Clear")
			{
				if(Status != 1)
				{
					cout << "未登录,不可操作" << endl;
					continue;
				}
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

			if(s == "Admin")
			{
				if(Status == 1)
				{
					Key = 1;
					puts("已获得管理员权限!");
			    }
			    else puts("未登录,先登录再获取管理员权限");
			}
			if(s == "Help")
			{
				//Help B Reserve Monday Floor 1 Seat 1 2
				string s1,s2,s3,s4,s5;//
				int Floor,x,y;
				cin >> s1 >> s2 >> s3 >> s4 >> Floor >> s5 >> x >> y;
				//     
				if(Status != 1 || Key != 1)
				{
					cout << "未登录/无权限,不可操作" << endl;
					continue;
				}
            	if(s3 == "Monday")Date = 1;
            	if(s3 == "Tuesday")Date = 2;
            	if(s3 == "Wednesday")Date = 3;
            	if(s3 == "Thursday")Date = 4;
            	if(s3 == "Friday")Date = 5;
            	if(s3 == "Saturday")Date = 6;
            	if(s3 == "Sunday")Date = 7;
            	if(s4 == "Floor" && s5 == "Seat")
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
            			Seat[Date][Floor][x][y] = 1;
            		}
            		else cout << "座位已被预约/被撤销!无法操作" << endl;
				}
			}
			if(s == "Cancel")
			{
				string s1;
				cin >> s1;
				if(s1.length() == 1)
				{
					string s2;
					cin >> s2;
					if(Status != 1 || Key != 1)
					{
						cout << "未登录/无权限,不可操作" << endl;
						continue;
					}
					for(int i = 1;i <= User_num;i++)
					{
						if(info[i].name_1 == s1)
						{
							int Date;
							info[i].flag = 0;
							if(info[i].date_1 == "Monday")Date = 1;
            	    		if(info[i].date_1 == "Tuesday")Date = 2;
            	   			if(info[i].date_1 == "Wednesday")Date = 3;
            	   	 		if(info[i].date_1 == "Thursday")Date = 4;
            	    		if(info[i].date_1 == "Friday")Date = 5;
            	   			if(info[i].date_1 == "Saturday")Date = 6;
            	    		if(info[i].date_1 == "Sunday")Date = 7;
							Seat[Date][info[i].floor_1][info[i].x_1][info[i].y_1] = 0;
						}
					}
					puts("已取消目标用户的所有预约");
				}
				// Cancel Floor 1 on Monday
				else if(s1.length() == 5)
				{
					int Floor;
					string s2,s3;
					cin >> Floor >> s2 >> s3;
					if(Status != 1 || Key != 1)
					{
						cout << "未登录/无权限,不可操作" << endl;
						continue;
					}
					if(s3 == "Monday")Date = 1;
            	    if(s3 == "Tuesday")Date = 2;
            	   	if(s3 == "Wednesday")Date = 3;
            	   	if(s3 == "Thursday")Date = 4;
            	    if(s3 == "Friday")Date = 5;
            	   	if(s3 == "Saturday")Date = 6;
            	    if(s3 == "Sunday")Date = 7;
					for(int i = 1;i <= User_num;i++)
					{
						if(info[i].floor_1 == Floor && info[i].date_1 == s3 && info[i].flag == 1)
						{
							info[i].flag = 0;
							Seat[Date][info[i].floor_1][info[i].x_1][info[i].y_1] = 0;
						}
					}
					puts("已清除该日该层所有座位！可以安排特别活动了");
				}
				//Cancel A Reservation/Cancel Date Floor Num Seat x y
				else 
				{
					string s2,s3,s4;
					int Floor,x,y,Date;
					cin >> s2 >> s3 >> Floor >> s4 >> x >> y;
					if(Status != 1 || Key != 1)
					{
						cout << "未登录/无权限,不可操作" << endl;
						continue;
					}
					if(s2 == "Monday")Date = 1;
            	    if(s2 == "Tuesday")Date = 2;
            	    if(s2 == "Wednesday")Date = 3;
            	    if(s2 == "Thursday")Date = 4;
            	    if(s2 == "Friday")Date = 5;
            	    if(s2 == "Saturday")Date = 6;
            	    if(s2 == "Sunday")Date = 7;
            	    for(int i = 1;i <= User_num;i++)
            	    {
            	    	if(info[i].date_1 == s2 && info[i].floor_1 && info[i].x_1 == x && info[i].y_1 == y && info[i].flag)
						{
							info[i].flag = 0;
							Seat[Date][info[i].floor_1][info[i].x_1][info[i].y_1] = 0;
							cout << "查询到该位置预约者为:" << info[i].name_1 << ",已取消其预约!";
							i = User_num;
						}
					}
				}
			}
			//Delete/Reset Floor 1 Seat 1 2
			if(s == "Delete")
			{
				string s1,s2;
				int Floor,x,y;
				cin >> s1 >> Floor >> s2 >> x >> y;
				if(Status != 1 || Key != 1)
				{
					cout << "未登录/无权限,不可操作" << endl;
					continue;
				}
				for(int d = 1;d <= 7;d++)
				{
					Seat[d][Floor][x][y] = 3;
				}
				puts("已永久撤销该位置,用Reset指令以恢复");
			}
			
			if(s == "Reset")
			{
				string s1,s2;
				int Floor,x,y;
				cin >> s1 >> Floor >> s2 >> x >> y;
				if(Status != 1 || Key != 1)
				{
					cout << "未登录/无权限,不可操作" << endl;
					continue;
				}
				for(int d = 1;d <= 7;d++)
				{
					Seat[d][Floor][x][y] = 0;
				}
				puts("已永久恢复该位置");
			}
     	}
	}
}