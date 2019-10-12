//��Խ��Ȩ���� ѧ�ţ�0908170608 ��Ϯ�ؾ�����
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream> 
using namespace std;

//���������Ϣ�� 
class SingerInformation
{
 public:
	SingerInformation(){}  //���캯��  
	//�������غ�����objΪ�� SingerInformation�Ķ��������
	friend istream& operator>>(istream&in, SingerInformation&obj)  
	{
		int i;
		float min=1000,max=-1;
		in>>obj.name;
		if(obj.name.compare("-1")==0) return in; //����compare��������������Ϊ-1�ж�Ϊ������� 
		in>>obj.sex>>obj.age>>obj.phoneNumber;
		obj.averScore=0;  //ƽ���ֳ�ʼֵ��Ϊ0
		for(i=0;i<5;i++){
		    in>>obj.score[i];
			//max=min=obj.score[0];    //����������ֵ����Сֵ���ڵ�һ������ 
			if(min>obj.score[i]) min=obj.score[i];
			if(max<obj.score[i]) max=obj.score[i];  //ͨ��ѭ��ȷ�������Сֵ 
			obj.averScore=obj.averScore+obj.score[i]; 
		}
		obj.averScore=(obj.averScore-min-max)/3.0;  //ȥ�����Сֵ����ƽ���� 
		return in;
	}
	
	//������غ�����objΪ�� SingerInformation�Ķ��������
	friend ostream &operator<<(ostream&out,const SingerInformation&obj) //��ʱ���������Ҫ��const����ֹ���޸� 
	{
		out<<obj.name<<"\t"<<obj.sex<<"\t"<<obj.age<<"\t"<<obj.phoneNumber<<"\t"<<obj.averScore<<endl;
		return out;
	}

	//�������� 
	string getName(){return name;} 
	
	//�����Ա�
	string getSex(){return sex;} 
	
	//��������
	int getAge(){return age;} 

	//������ϵ��ʽ 
	string getPhoneNumber(){return phoneNumber;}
	
	//����ƽ���� 
	float getAverScore(){return averScore;}
	
	//���سɼ�����
	float* getSingleScore(){return score;} 
	
	//�������������� 
	void OutScore()
	{
		int i;
		for(i=0;i<5;i++){
			cout<<score[i]<<"\t";
		}
		cout<<endl;
    }
    
    //���ļ���ȡ��Ϣ����
	void setInformation(string name,string sex,int age,string num,float score[5],float aver)
	{
	    this->name=name; //thisָ�� 
	    this->sex=sex;
	    this->age=age;
	    this->phoneNumber=num;
	    for(int i=0;i<5;i++){
	    	this->score[i]=score[i];
		}
		this->averScore=aver;
	}
	 
 private:
	//�����������Ա����䡢�绰���롢�����ί������ƽ����Ϊ˽�����ݳ�Ա 
    string name;
	string sex;
	int age;
	string phoneNumber;
	float score[5];
	float averScore;
}; 
    

//����ϵͳ������
class SystemManage 
{
 public:
	SystemManage(){CurSingerNum=0;};
	static int frame();                //������ܺ���
	static void menuSwitch(SystemManage &sm);          //�����˵�ѡ����
	void inputInformation();    //�������뺯��
	void outputInformation();   //�����������
	void singerSort();          //����������Ϣ������
	int search();               //�������Һ���
	int omit();                 //����ɾ������
	int correct();              //����������Ϣ����
	int openfile();             //������ȡ�ļ����� 
	int savefile();             //���������ļ����� 
 private:
	SingerInformation singer[1000];  //����������飬���鳤��Ϊ1000����һ��ȫ������ 
	int CurSingerNum;      //δ֪����������ȫ��������ɺ����CurSingerNum�� 
};

/*SystemManage::SystemManage()
{
	CurSingerNum=0;  //��CurSingerNum��ֵΪ0 
}
*/
int main()
{
	SystemManage sm;    //����һ��ϵͳ������Ķ��󣬷����ö��������к������� 
	while (1)
	{
		SystemManage::frame();
		cout<<"��������Ӧ�˵���Ž��в���:"<<endl; 
		SystemManage::menuSwitch(sm);
	}
	return 1;
}	 
 
//�����ܺ��� 
int SystemManage::frame()      
{
    cout<<"                         ���ֱ����ɼ�����ϵͳ V1.0             "<<endl;
    cout<<"                          ��Խ   ��Ȩ���� Copyright             "<<endl<<endl;
    cout<<"**************************************************************************"<<endl;
    cout<<"*                                                                        *"<<endl;
    cout<<"*                          1��������������Ϣ                           *"<<endl;
    cout<<"*                          2�����ⲿ�ļ���ȡ����(�ļ���ͬһĿ¼)         *"<<endl;
    cout<<"*                          3����ʾ������Ϣ��ƽ����                       *"<<endl;
    cout<<"*                          4���������                                   *"<<endl;
    cout<<"*                          5����ѯ����                                   *"<<endl;
    cout<<"*                          6���޸ĸ�����Ϣ                               *"<<endl;
    cout<<"*                          7��ɾ��������Ϣ                               *"<<endl;
    cout<<"*                          8�������ļ�                                   *"<<endl;
    cout<<"*                          9���˳�ϵͳ                                   *"<<endl;
    cout<<"*                                                                        *"<<endl;
    cout<<"**************************************************************************"<<endl;
	return 0;
}

//����˵�ѡ���� 
void SystemManage::menuSwitch(SystemManage &sm)   //����SystemManage��sm����          
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
			cout<<"��������ȷ�ı�ţ�"<<endl; 
			system("pause");
			system("cls");
	}
}

//�������뺯�� 
void SystemManage::inputInformation()    
{
	cout<<"��������������Ϣ:(��������-1��ʾ����)"<<endl;
	cout<<"����\t�Ա�\t����\t��ϵ�绰\t��ί1\t��ί2\t��ί3\t��ί4\t��ί5\n";
	while (1){
		cin>>singer[CurSingerNum];
		if(singer[CurSingerNum].getName().compare("-1")==0) break;  //�õ���.compare�������ص��ǲ����ִ�Сд 
		CurSingerNum++;
	}
	cout<<"��Ϣ��������ɣ��������һ��������"<<endl;
 } 

//����������� 
void SystemManage::outputInformation()    
{
	int i;
	cout<<"�����Ǵ˴α������ֵ���Ϣ:"<<endl<<endl;
	cout<<"����\t�Ա�\t����\t�ֻ�����\tƽ���ɼ�"<<endl<<endl;
	for(i=0;i<CurSingerNum;i++){                       
		cout<<singer[i]<<endl;  //���Ϊ�û�����Ķ��󣬰������صķ�ʽ��� 
	}  
	cout<<"��Ϣ�������ɣ������������"<<endl<<endl;
} 

//���������Ϣ������
void SystemManage::singerSort()      
{
	int i,j;                //i�����i+1�����֣�j����ÿ�����ֵ�j+1����ί�ķ���
	SingerInformation temp;  //��ʱ�����������ڽ��� 
	for (i=0;i<CurSingerNum;i++){         //�ӵ�һ�����ֿ�ʼ����ÿ�����ֵĳɼ�����˳������
		for (j=i+1;j<CurSingerNum;j++){
			if(singer[i].getAverScore()<singer[j].getAverScore()){  //��getAverScore������ȡƽ���֣������� 
				temp=singer[i];
				singer[i]=singer[j];
				singer[j]=temp;
			}
		}
	}
	outputInformation();
}

//���������Ϣ���� 
int SystemManage::search()    
{
	int i;
	int count=0;   //count��������ȷ�ϴ���ѯ�����Ƿ���� 
	string searchName;
	cout<<"�������ѯ���ֵ�������"<<endl;
	cin>>searchName;
	for(i=0;i<CurSingerNum;i++){      //������ּ��� 
		if(searchName.compare(singer[i].getName())==0){  //˽������name����ֱ�Ӷ�ȡ��ֻ����getName������� 
			cout<<endl<<"������Ϣ����"<<endl<<"����\t�Ա�\t����\t�绰����\tƽ���ɼ�"<<endl<<endl;
			cout<<singer[i]<<endl;
			cout<<"�ø��ָ��ɼ�����:"<<endl<<endl;
			singer[i].OutScore();  //����OutScore�����������ɼ� 
			count++; //��ѯ���ִ��ڣ�count�Լ� 
		}
	}
	if(count==0) cout<<"���ֲ�����!"<<endl;
	return 0;
}

//����ɾ������ 
int SystemManage::omit()        
{
	int i,j;
	string deleteName;
	cout<<"��������Ҫɾ���ĸ�������:"<<endl;
	cin>>deleteName;
	for(i=0;i<CurSingerNum;i++){
        if(deleteName.compare(singer[i].getName())==0){
			for (j=i+1;j<CurSingerNum;j++){   //�Ѹø��ֺ���ĸ�����Ϣ������ǰŲ�ƣ��ﵽɾ��Ŀ��
				singer[j-1]=singer[j];
			}
			CurSingerNum=CurSingerNum-1;   //������������1 
			break;      //�޸���ɺ��˳�ѭ�� 
        }
	}
/*	if(i!=CurSingerNum){     //����Ҫɾ�����ִ��ڣ���iά��ԭֵ��CurSingerNum��ԭ��Сһ������жϲ���
		cout<<"ɾ���������Ϣ��"<<endl;
		outputInformation();
	}
	else cout<<"�ø��ֲ�����"<<endl ;
*/ 
	cout<<"ɾ���ɹ���"<<endl;
	outputInformation();
	return 0 ;
} 

//�����޸���Ϣ���� 
int SystemManage::correct()    
{
	int i;
	string correctName;
	cout<<"��������Ҫ�޸ĵĸ���������"<<endl;
	cin>>correctName;
	for(i=0;i<CurSingerNum;i++){
		if(correctName.compare(singer[i].getName())==0){
			cout<<"�������޸ĺ������Ϣ:"<<endl;
			cout<<"����\t�Ա�\t����\t��ϵ�绰\t��ί1\t��ί2\t��ί3\t��ί4\t��ί5"<<endl;
			cin>>singer[i];
			break; 
		}
	}
	//����i�ۼӵ�CurSingerNum֮ǰ�ͷ�����Ҫ�޸ĵ����֣�����ѭ����i������CurSingerNum��ִ�������� 
	if(i!=CurSingerNum){   
		cout<<"�޸ĳɹ�!"<<endl;
		cout<<"�޸ĺ����и�����Ϣ��"<<endl;
		cout<<"����\t�Ա�\t����\t��ϵ�绰\tƽ����"<<endl;
		for (i=0; i<CurSingerNum; i++){
			cout<<singer[i];
		}
	}
	else cout<<"�ø��ֲ�����"<<endl;
	return 0 ;
}

//�����ȡ�ļ����� 
int SystemManage::openfile()
{
	ifstream in;
	in.open("ԭʼ����.txt",ios::in);  //���ļ�
	//in.is_open()Ϊbool���ж� 
	if(!in.is_open()) {
		cout<<"�ļ���ȡʧ�ܣ�"<<endl;
		return 0; 
	}
	else cout<<"��ȡ�ɹ����������һ��������"; 
	//������ʱ��Ϣ���ݣ����ڴ������������ 
	string name;
	string sex;
	int age;
	string tel;
	float score[5];
	float aver;
	while(in>>name>>sex>>age>>tel>>score[0]>>score[1]>>score[2]>>score[3]>>score[4]>>aver){
		singer[CurSingerNum].setInformation(name,sex,age,tel,score,aver);
		CurSingerNum++;    //���ⲿ�ļ���ȡʱδȷ������������������CurSingerNum������ 
	}
} 

//���屣���ļ�����
int SystemManage::savefile()
{
	ofstream out("������Ϣ.txt");
	out<<"����\t�Ա�\t����\t��ϵ�绰\t\t��ί1\t��ί2\t��ί3\t��ί4\t��ί5\tƽ����";
	out<<endl<<endl;
	for(int i=0;i<CurSingerNum;i++){
		out<<singer[i].getName()<<"\t"<<singer[i].getSex()<<"\t"<<singer[i].getAge()<<"\t";
		out<<singer[i].getPhoneNumber()<<"\t"; 
		float* a=singer[i].getSingleScore();     //��ָ���ȡ�����ί�ɼ� 
		for(int j=0;j<5;j++){
			out<<a[j]<<"\t";
		}
		out<<singer[i].getAverScore()<<endl<<endl;
	}
	out.close();
	cout<<"�����ļ��ɹ���"<<endl<<endl; 
} 
