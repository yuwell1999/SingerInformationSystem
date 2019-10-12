//余越版权所有 学号：0908170608 抄袭必究！！
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream> 
using namespace std;

//定义歌手信息类 
class SingerInformation
{
 public:
	SingerInformation(){}  //构造函数  
	//输入重载函数，obj为类 SingerInformation的对象的引用
	friend istream& operator>>(istream&in, SingerInformation&obj)  
	{
		int i;
		float min=1000,max=-1;
		in>>obj.name;
		if(obj.name.compare("-1")==0) return in; //运用compare函数，输入名字为-1判断为输入结束 
		in>>obj.sex>>obj.age>>obj.phoneNumber;
		obj.averScore=0;  //平均分初始值定为0
		for(i=0;i<5;i++){
		    in>>obj.score[i];
			//max=min=obj.score[0];    //先令分数最大值和最小值等于第一个分数 
			if(min>obj.score[i]) min=obj.score[i];
			if(max<obj.score[i]) max=obj.score[i];  //通过循环确定最大最小值 
			obj.averScore=obj.averScore+obj.score[i]; 
		}
		obj.averScore=(obj.averScore-min-max)/3.0;  //去最大最小值并求平均分 
		return in;
	}
	
	//输出重载函数，obj为类 SingerInformation的对象的引用
	friend ostream &operator<<(ostream&out,const SingerInformation&obj) //临时对象的引用要用const，防止被修改 
	{
		out<<obj.name<<"\t"<<obj.sex<<"\t"<<obj.age<<"\t"<<obj.phoneNumber<<"\t"<<obj.averScore<<endl;
		return out;
	}

	//返回姓名 
	string getName(){return name;} 
	
	//返回性别
	string getSex(){return sex;} 
	
	//返回年龄
	int getAge(){return age;} 

	//返回联系方式 
	string getPhoneNumber(){return phoneNumber;}
	
	//返回平均分 
	float getAverScore(){return averScore;}
	
	//返回成绩数组
	float* getSingleScore(){return score;} 
	
	//输出五个分数函数 
	void OutScore()
	{
		int i;
		for(i=0;i<5;i++){
			cout<<score[i]<<"\t";
		}
		cout<<endl;
    }
    
    //从文件读取信息函数
	void setInformation(string name,string sex,int age,string num,float score[5],float aver)
	{
	    this->name=name; //this指针 
	    this->sex=sex;
	    this->age=age;
	    this->phoneNumber=num;
	    for(int i=0;i<5;i++){
	    	this->score[i]=score[i];
		}
		this->averScore=aver;
	}
	 
 private:
	//歌手姓名、性别、年龄、电话号码、五个评委分数及平均分为私有数据成员 
    string name;
	string sex;
	int age;
	string phoneNumber;
	float score[5];
	float averScore;
}; 
    

//定义系统管理类
class SystemManage 
{
 public:
	SystemManage(){CurSingerNum=0;};
	static int frame();                //声明框架函数
	static void menuSwitch(SystemManage &sm);          //声明菜单选择函数
	void inputInformation();    //声明输入函数
	void outputInformation();   //声明输出函数
	void singerSort();          //声明歌手信息排序函数
	int search();               //声明查找函数
	int omit();                 //声明删除函数
	int correct();              //声明更改信息函数
	int openfile();             //声明读取文件函数 
	int savefile();             //声明保存文件函数 
 private:
	SingerInformation singer[1000];  //定义对象数组，数组长度为1000，不一定全部用完 
	int CurSingerNum;      //未知歌手总数，全部输入完成后存入CurSingerNum中 
};

/*SystemManage::SystemManage()
{
	CurSingerNum=0;  //令CurSingerNum初值为0 
}
*/
int main()
{
	SystemManage sm;    //定义一个系统管理类的对象，方便用对象名进行函数操作 
	while (1)
	{
		SystemManage::frame();
		cout<<"请输入相应菜单编号进行操作:"<<endl; 
		SystemManage::menuSwitch(sm);
	}
	return 1;
}	 
 
//定义框架函数 
int SystemManage::frame()      
{
    cout<<"                         歌手比赛成绩管理系统 V1.0             "<<endl;
    cout<<"                          余越   版权所有 Copyright             "<<endl<<endl;
    cout<<"**************************************************************************"<<endl;
    cout<<"*                                                                        *"<<endl;
    cout<<"*                          1、输入歌手相关信息                           *"<<endl;
    cout<<"*                          2、从外部文件获取数据(文件在同一目录)         *"<<endl;
    cout<<"*                          3、显示基本信息和平均分                       *"<<endl;
    cout<<"*                          4、排序输出                                   *"<<endl;
    cout<<"*                          5、查询功能                                   *"<<endl;
    cout<<"*                          6、修改歌手信息                               *"<<endl;
    cout<<"*                          7、删除歌手信息                               *"<<endl;
    cout<<"*                          8、保存文件                                   *"<<endl;
    cout<<"*                          9、退出系统                                   *"<<endl;
    cout<<"*                                                                        *"<<endl;
    cout<<"**************************************************************************"<<endl;
	return 0;
}

//定义菜单选择函数 
void SystemManage::menuSwitch(SystemManage &sm)   //引用SystemManage中sm对象          
{
	int n;
    cin>>n;
	switch(n)
	{
		case 1:
			sm.inputInformation();
			system("pause"); system("cls"); break;
		case 2:
		    sm.openfile();
		    system("pause"); system("cls"); break;
		case 3:
			sm.outputInformation();
			system("pause"); system("cls"); break;
		case 4:
	        sm.singerSort();
			system("pause"); system("cls"); break;
		case 5:
			sm.search();
			system("pause"); system("cls"); break;
		case 6:
			sm.correct();
			system("pause"); system("cls"); break;    
		case 7:
			sm.omit();
			system("pause"); system("cls"); break; 
		case 8:
		    sm.savefile();
		    system("pause"); system("cls"); break;	        
		case 9:
			exit(0);      
		default:
			cout<<"请输入正确的编号！"<<endl; 
			system("pause");
			system("cls");
	}
}

//定义输入函数 
void SystemManage::inputInformation()    
{
	cout<<"请输入歌手相关信息:(名字输入-1表示结束)"<<endl;
	cout<<"姓名\t性别\t年龄\t联系电话\t评委1\t评委2\t评委3\t评委4\t评委5\n";
	while (1){
		cin>>singer[CurSingerNum];
		if(singer[CurSingerNum].getName().compare("-1")==0) break;  //用到了.compare函数，特点是不区分大小写 
		CurSingerNum++;
	}
	cout<<"信息输入已完成！请进行下一步操作："<<endl;
 } 

//定义输出函数 
void SystemManage::outputInformation()    
{
	int i;
	cout<<"下面是此次比赛歌手的信息:"<<endl<<endl;
	cout<<"姓名\t性别\t年龄\t手机号码\t平均成绩"<<endl<<endl;
	for(i=0;i<CurSingerNum;i++){                       
		cout<<singer[i]<<endl;  //输出为用户定义的对象，按照重载的方式输出 
	}  
	cout<<"信息输出已完成！请继续操作："<<endl<<endl;
} 

//定义歌手信息排序函数
void SystemManage::singerSort()      
{
	int i,j;                //i代表第i+1个歌手，j代表每个歌手第j+1个评委的分数
	SingerInformation temp;  //临时对象数组用于交换 
	for (i=0;i<CurSingerNum;i++){         //从第一个歌手开始，把每个歌手的成绩进行顺序排序
		for (j=i+1;j<CurSingerNum;j++){
			if(singer[i].getAverScore()<singer[j].getAverScore()){  //用getAverScore函数获取平均分，并排序 
				temp=singer[i];
				singer[i]=singer[j];
				singer[j]=temp;
			}
		}
	}
	outputInformation();
}

//定义查找信息函数 
int SystemManage::search()    
{
	int i;
	int count=0;   //count用来计数确认待查询名字是否存在 
	string searchName;
	cout<<"请输入查询歌手的姓名："<<endl;
	cin>>searchName;
	for(i=0;i<CurSingerNum;i++){      //逐个名字检索 
		if(searchName.compare(singer[i].getName())==0){  //私有数据name不能直接读取，只能用getName函数获得 
			cout<<endl<<"歌手信息如下"<<endl<<"姓名\t性别\t年龄\t电话号码\t平均成绩"<<endl<<endl;
			cout<<singer[i]<<endl;
			cout<<"该歌手各成绩如下:"<<endl<<endl;
			singer[i].OutScore();  //运用OutScore函数输出五个成绩 
			count++; //查询名字存在，count自加 
		}
	}
	if(count==0) cout<<"歌手不存在!"<<endl;
	return 0;
}

//定义删除函数 
int SystemManage::omit()        
{
	int i,j;
	string deleteName;
	cout<<"请输入需要删除的歌手名字:"<<endl;
	cin>>deleteName;
	for(i=0;i<CurSingerNum;i++){
        if(deleteName.compare(singer[i].getName())==0){
			for (j=i+1;j<CurSingerNum;j++){   //把该歌手后面的歌手信息数组往前挪移，达到删除目的
				singer[j-1]=singer[j];
			}
			CurSingerNum=CurSingerNum-1;   //歌手人数减少1 
			break;      //修改完成后退出循环 
        }
	}
/*	if(i!=CurSingerNum){     //若需要删除名字存在，则i维持原值，CurSingerNum比原来小一，则此判断不等
		cout<<"删除后歌手信息："<<endl;
		outputInformation();
	}
	else cout<<"该歌手不存在"<<endl ;
*/ 
	cout<<"删除成功！"<<endl;
	outputInformation();
	return 0 ;
} 

//定义修改信息函数 
int SystemManage::correct()    
{
	int i;
	string correctName;
	cout<<"请输入需要修改的歌手姓名："<<endl;
	cin>>correctName;
	for(i=0;i<CurSingerNum;i++){
		if(correctName.compare(singer[i].getName())==0){
			cout<<"请输入修改后歌手信息:"<<endl;
			cout<<"姓名\t性别\t年龄\t联系电话\t评委1\t评委2\t评委3\t评委4\t评委5"<<endl;
			cin>>singer[i];
			break; 
		}
	}
	//若在i累加到CurSingerNum之前就发现需要修改的名字，跳出循环，i不等于CurSingerNum，执行输出语句 
	if(i!=CurSingerNum){   
		cout<<"修改成功!"<<endl;
		cout<<"修改后所有歌手信息："<<endl;
		cout<<"姓名\t性别\t年龄\t联系电话\t平均分"<<endl;
		for (i=0; i<CurSingerNum; i++){
			cout<<singer[i];
		}
	}
	else cout<<"该歌手不存在"<<endl;
	return 0 ;
}

//定义读取文件函数 
int SystemManage::openfile()
{
	ifstream in;
	in.open("原始数据.txt",ios::in);  //打开文件
	//in.is_open()为bool型判断 
	if(!in.is_open()) {
		cout<<"文件读取失败！"<<endl;
		return 0; 
	}
	else cout<<"读取成功！请进行下一步操作！"; 
	//定义临时信息数据，用于存入对象数组中 
	string name;
	string sex;
	int age;
	string tel;
	float score[5];
	float aver;
	while(in>>name>>sex>>age>>tel>>score[0]>>score[1]>>score[2]>>score[3]>>score[4]>>aver){
		singer[CurSingerNum].setInformation(name,sex,age,tel,score,aver);
		CurSingerNum++;    //从外部文件读取时未确定歌手人数，所以用CurSingerNum来限制 
	}
} 

//定义保存文件函数
int SystemManage::savefile()
{
	ofstream out("歌手信息.txt");
	out<<"姓名\t性别\t年龄\t联系电话\t\t评委1\t评委2\t评委3\t评委4\t评委5\t平均分";
	out<<endl<<endl;
	for(int i=0;i<CurSingerNum;i++){
		out<<singer[i].getName()<<"\t"<<singer[i].getSex()<<"\t"<<singer[i].getAge()<<"\t";
		out<<singer[i].getPhoneNumber()<<"\t"; 
		float* a=singer[i].getSingleScore();     //用指针获取五个评委成绩 
		for(int j=0;j<5;j++){
			out<<a[j]<<"\t";
		}
		out<<singer[i].getAverScore()<<endl<<endl;
	}
	out.close();
	cout<<"保存文件成功！"<<endl<<endl; 
} 
