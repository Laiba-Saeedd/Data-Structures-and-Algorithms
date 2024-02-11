#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
class library{
	private:
		struct Node{
			int id,s_rollno;
			string b_name,b_author,b_publisher,s_name,s_department,DOI,DOR;
			Node *next;
		};
		public:
		Node *head=NULL;
		Node *tail=NULL;
		void menu1();
		void menu2();
		void insert_data();	
		void search_record();
		void search_file();
		void update_record();
		void update_file();
		void del_record();
		void del_record_file();
		void sort();
		void show_record();
		void show_file();
		void count();
};

void library::menu1(){
	int c2;
	do{
	int c1;
	system("cls");
	cout<<"\n\n\t\t\t==============================================================";
	cout<<"\n\n\t\t\t==================LIBRARY MANAGEMENT SYSTEM===================";
	cout<<"\n\n\t\t\t==============================================================";
	cout<<"\n\n 1. Insert New Record";
	cout<<"\n\n 2. Search Record";
	cout<<"\n\n 3. Search Record From File";
	cout<<"\n\n 4. Update Record";
	cout<<"\n\n 5. Update Record From File";
	cout<<"\n\n 6. Delete Record";
	cout<<"\n\n 7. Delete Record From File";
	cout<<"\n\n 8. Show All Record";
	cout<<"\n\n 9. Show All Record From File";
	cout<<"\n\n 10. Count All Record";
	cout<<"\n\n 11. Exit";
	cout<<"\n\n Enter Your Choice  : ";
	cin>>c1;
	switch(c1){
		case 1:{
			insert_data();
			break;
		}
		case 2:{
			search_record();
			break;
		}
		case 3:{
			search_file();
			break;
		}
		case 4:{
			update_record();
			break;
		}
		case 5:{
			update_file();
			break;
		}
		case 6:{
			del_record();
			break;
		}
		case 7:{
			del_record_file();
			break;
		}
		case 8:{
			sort();
			show_record();
			break;
		}
		case 9:{
			show_file();
			break;
		}
		case 10:{
			count();
			break;
		}
		case 11:{
			exit(0);
			break;
		}
		default:{
			cout<<"\n\n Invalid Choice.......Please Try Again..";
			break;
		}
	}
	getch();
	cout<<"\n\n\t\t\t Do You Want to Run Again....\n\n\t\t\tEnter Any Number Except 0  : ";
	cin>>c2;
   }while(c2!=0);
}
void library::menu2(){
	int c2;
	do{
	int c1;
	system("cls");
	cout<<"\n\n\t\t\t==============================================================";
	cout<<"\n\n\t\t\t==================LIBRARY MANAGEMENT SYSTEM===================";
	cout<<"\n\n\t\t\t==============================================================";
	cout<<"\n\n 1. Search Record";
	cout<<"\n\n 2. Show All Record";
	cout<<"\n\n 3. Exit";
	cout<<"\n\n Enter Your Choice  : ";
	cin>>c1;
	switch(c1){
		case 1:{
			search_record();
			break;
		}
		case 2:{
			sort();
			show_record();
			break;
		}
		case 3:{
			exit(0);
			break;
		}
		default:{
			cout<<"\n\n Invalid Choice.......Please Try Again..";
			break;
		}
	}
	getch();
	cout<<"\n\n\t\t\t Do You Want to Run Again....\n\n\t\t\tEnter Any Number Except 0  : ";
	cin>>c2;
   }while(c2!=0);
}
void library::insert_data(){
	fstream file;
	file.open("LMS.txt",ios::app);
	system("cls");
	cout<<"\n\n\t\t\t==============================================================";
	cout<<"\n\n\t\t\t==================LIBRARY MANAGEMENT SYSTEM===================";
	cout<<"\n\n\t\t\t==============================================================";
	Node *new_node=new Node;
	cout<<"\n\n Book ID : ";
	cin>>new_node->id;
	cout<<"\n\n Book Name : ";
	cin>>new_node->b_name;
	cout<<"\n\n Book Author Name : ";
	cin>>new_node->b_author;
	cout<<"\n\n Book Publisher Name : ";
	cin>>new_node->b_publisher;
	cout<<"\n\n Student Name : ";
	cin>>new_node->s_name;
	cout<<"\n\n Student Roll Number : ";
	cin>>new_node->s_rollno;
	cout<<"\n\n Student Department : ";
	cin>>new_node->s_department;
	cout<<"\n\n Date of Issue : ";
	cin>>new_node->DOI;
	cout<<"\n\n Date of Return : ";
	cin>>new_node->DOR;
	new_node->next=NULL;
    file<<"\n"<<new_node->id<<"\t"<<new_node->b_name<<"\t"<<new_node->b_author<<"\t "<<new_node->b_publisher<<"\t";
	file<<new_node->s_name<<"\t"<<new_node->s_rollno<<"\t"<<new_node->s_department<<"\t"<<new_node->DOI<<"\t";
	file<<new_node->DOR;
	if(head==NULL){
		head=new_node;
	}
	else{
		Node *ptr=head;
		while(ptr->next!=NULL){
			ptr=ptr->next;
			}
			ptr->next=new_node;
	}
	cout<<"\n\n\t\t\t New Book Inserted Successfully......";
	file.close();
}
void library::search_record(){
	int t_id,found=0;
	system("cls");
	cout<<"\n\n\t\t\t==============================================================";
	cout<<"\n\n\t\t\t==================LIBRARY MANAGEMENT SYSTEM===================";
	cout<<"\n\n\t\t\t==============================================================";
	if(head==NULL){
		cout<<"\n\n Linked List is Empty......";
	}
	else{
		cout<<"\n\n Book ID : ";
		cin>>t_id;
		Node *ptr=head;
		while(ptr!=NULL){
			if(t_id==ptr->id){
				system("cls");
	            cout<<"\n\n\t\t\t==============================================================";
	            cout<<"\n\n\t\t\t==================LIBRARY MANAGEMENT SYSTEM===================";
           	    cout<<"\n\n\t\t\t==============================================================";
				cout<<"\n\n Book Information";
           	    cout<<"\n\n Book ID : "<<ptr->id;
           	    cout<<"\n\n Book Name : "<<ptr->b_name;
           	    cout<<"\n\n Book Author Name : "<<ptr->b_author;
           	    cout<<"\n\n Book Publisher Name : "<<ptr->b_publisher;
           	    cout<<"\n\n\t\t\t==============================================================";
           	    cout<<"\n\n Student Information";
           	    cout<<"\n\n Student Name : "<<ptr->s_name;
           	    cout<<"\n\n Student Roll Number : "<<ptr->s_rollno;
           	    cout<<"\n\n Student Department : "<<ptr->s_department;
           	    cout<<"\n\n Date of Issue : "<<ptr->DOI;
           	    cout<<"\n\n Date of Return : "<<ptr->DOR;
           	    found++;
			}
			ptr=ptr->next;
		}
		if(found==0){
			cout<<"\n\n Book ID is Invalid.....\n No Record Found....";
		}
	}
}
void library::search_file(){
	int t_id; int found=0;
	ifstream f("LMS.txt");
	cout<<"\n Enter ID You Want to Search......";
	cin>>t_id;
	while(!f.eof()){
		Node *temp=new Node;
		temp->next=head;
		if(head==NULL){
			tail=temp;
		}
		else{
			head=temp;
		}
		f>>temp->id;
		f>>temp->b_name;
		f>>temp->b_author;
		f>>temp->b_publisher;
		f>>temp->s_name;
		f>>temp->s_rollno;
		f>>temp->s_department;
		f>>temp->DOI;
		f>>temp->DOR;
		if(t_id==temp->id){
			system("cls");
	            cout<<"\n\n\t\t\t==============================================================";
	            cout<<"\n\n\t\t\t==================LIBRARY MANAGEMENT SYSTEM===================";
           	    cout<<"\n\n\t\t\t==============================================================";
				cout<<"\n\n Book Information";
           	    cout<<"\n\n Book ID : "<<temp->id;
           	    cout<<"\n\n Book Name : "<<temp->b_name;
           	    cout<<"\n\n Book Author Name : "<<temp->b_author;
           	    cout<<"\n\n Book Publisher Name : "<<temp->b_publisher;
           	    cout<<"\n\n\t\t\t==============================================================";
           	    cout<<"\n\n Student Information";
           	    cout<<"\n\n Student Name : "<<temp->s_name;
           	    cout<<"\n\n Student Roll Number : "<<temp->s_rollno;
           	    cout<<"\n\n Student Department : "<<temp->s_department;
           	    cout<<"\n\n Date of Issue : "<<temp->DOI;
           	    cout<<"\n\n Date of Return : "<<temp->DOR;
           	    found++;
		}
	}
		if(found==0){
			system("cls");
	            cout<<"\n\n\t\t\t==============================================================";
	            cout<<"\n\n\t\t\t==================LIBRARY MANAGEMENT SYSTEM===================";
           	    cout<<"\n\n\t\t\t==============================================================";
			    cout<<"\n\n Book ID is Invalid.....\n No Record Found....";
		}
	f.close();
}
void library::update_file(){
	int t_id; int found=0;
	fstream f("LMS.txt");
	cout<<"\n Enter ID You Want to Update......";
	cin>>t_id;
	while(!f.eof()){
		Node *temp=new Node;
		temp->next=head;
		if(head==NULL){
			tail=temp;
		}
		else{
			head=temp;
		}
		f>>temp->id;
		f>>temp->b_name;
		f>>temp->b_author;
		f>>temp->b_publisher;
		f>>temp->s_name;
		f>>temp->s_rollno;
		f>>temp->s_department;
		f>>temp->DOI;
		f>>temp->DOR;
		if(t_id==temp->id){
			system("cls");
	            cout<<"\n\n\t\t\t==============================================================";
	            cout<<"\n\n\t\t\t==================LIBRARY MANAGEMENT SYSTEM===================";
           	    cout<<"\n\n\t\t\t==============================================================";
				cout<<"\n\n Book Information";
           	    cout<<"\n\n Book ID : ";
				cin>>temp->id;
           	    cout<<"\n\n Book Name : ";
				cin>>temp->b_name;
           	    cout<<"\n\n Book Author Name : ";
				cin>>temp->b_author;
           	    cout<<"\n\n Book Publisher Name : ";
				cin>>temp->b_publisher;
           	    cout<<"\n\n\t\t\t==============================================================";
           	    cout<<"\n\n Student Information";
           	    cout<<"\n\n Student Name : ";
				cin>>temp->s_name;
           	    cout<<"\n\n Student Roll Number : ";
				cin>>temp->s_rollno;
           	    cout<<"\n\n Student Department : ";
				cin>>temp->s_department;
           	    cout<<"\n\n Date of Issue : ";
				cin>>temp->DOI;
           	    cout<<"\n\n Date of Return : ";
				cin>>temp->DOR;
           	    found++;
           	    cout<<"\n\n Update Book Successfully.......";
		}
		f<<"\n"<<temp->id<<"\t"<<temp->b_name<<"\t"<<temp->b_author<<"\t"<<temp->b_publisher<<"\t";
		f<<temp->s_name<<"\t"<<temp->s_rollno<<"\t"<<temp->s_department<<"\t"<<temp->DOI<<"\t";
		f<<temp->DOR;
	}
		if(found==0){
			system("cls");
	            cout<<"\n\n\t\t\t==============================================================";
	            cout<<"\n\n\t\t\t==================LIBRARY MANAGEMENT SYSTEM===================";
           	    cout<<"\n\n\t\t\t==============================================================";
			    cout<<"\n\n Book ID is Invalid.....\n No Record Found....";
		}
	f.close();
}
void library::count(){
	system("cls");
	if(head==NULL){
	system("cls");
	cout<<"\n\n\t\t\t==============================================================";
	cout<<"\n\n\t\t\t==================LIBRARY MANAGEMENT SYSTEM===================";
	cout<<"\n\n\t\t\t==============================================================";
		cout<<"\nLinked List is Empty....";
	}
	else{
		int c1=0;
		Node *ptr=head;
		while(ptr!=NULL){
			c1++;
			ptr=ptr->next;
		}
		cout<<"\n\n\t\t\t===========================================================";
		cout<<"\n\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
		cout<<"\nNumber of Record: "<<c1;
	}
}
void library::update_record(){
	int t_id,found=0;
    system("cls");
	cout<<"\n\n\t\t\t==============================================================";
	cout<<"\n\n\t\t\t==================LIBRARY MANAGEMENT SYSTEM===================";
	cout<<"\n\n\t\t\t==============================================================";
	if(head==NULL){
		cout<<"\n\n Linked List is Empty......";
	}
	else{
		cout<<"\n\n Book ID : ";
	    cin>>t_id;
		Node *ptr=head;
		while(ptr!=NULL){
			if(t_id==ptr->id){
	            cout<<"\n\n\t\t\t==============================================================";
	            cout<<"\n\n\t\t\t==================LIBRARY MANAGEMENT SYSTEM===================";
           	    cout<<"\n\n\t\t\t==============================================================";	
           	    cout<<"\n\n Book ID : ";
				   cin>>ptr->id;
           	    cout<<"\n\n Book Name : ";
				   cin>>ptr->b_name;
           	    cout<<"\n\n Book Author Name : ";
				   cin>>ptr->b_author;
           	    cout<<"\n\n Book Publisher Name : ";
				   cin>>ptr->b_publisher;
				cout<<"\n\n Student Name : ";
	                cin>>ptr->s_name;
            	cout<<"\n\n Student Roll Number : ";
	                cin>>ptr->s_rollno;
	            cout<<"\n\n Student Department : ";
                 	cin>>ptr->s_department;
              	cout<<"\n\n Date of Issue : ";
	                cin>>ptr->DOI;
	            cout<<"\n\n Date of Return : ";
	                cin>>ptr->DOR;
           	    found++;
           	    cout<<"\n\n Update Book Successfully.......";
			}
			ptr=ptr->next;
		}
		if(found==0){
			cout<<"\n\n Book ID is Invalid.....";
		}
	}
}
void library::del_record(){
	int t_id,found=0;
	system("cls");
	cout<<"\n\n\t\t\t==============================================================";
	cout<<"\n\n\t\t\t==================LIBRARY MANAGEMENT SYSTEM===================";
	cout<<"\n\n\t\t\t==============================================================";
	
	if(head==NULL){
		cout<<"\n\n Linked List is Empty......";
	}
	else{
		cout<<"\n\n Book ID : ";
		cin>>t_id;
	    if(t_id==head->id){
	    	Node *ptr=head;
	    	head=head->next;
	    	delete ptr;
	    	cout<<"\n\n Delete Book Successfully......";
	    	found++;
		}
		else{
			Node *pre=head;
			Node *ptr=head;
			while(ptr!=NULL){
				if(t_id==ptr->id){
					pre->next=ptr->next;
					delete ptr;
	    	        cout<<"\n\n Delete Book Successfully......";
	    	        found++;
	    	        break;
				}
				pre=ptr;
				ptr=ptr->next;
			}
		}
		if(found==0){
			cout<<"\n\n Book ID is Invalid......";
		}
	}
}
void library::del_record_file(){
    int id,s_rollno;
	string b_name,b_author,b_publisher,s_name,s_department,DOI,DOR;
    ifstream myfile;
    ofstream temp;
    myfile.open("LMS.txt");
    temp.open("temp.txt");
    while (!myfile.eof())
   {
  	myfile>>id;
  	myfile>>b_name;
  	myfile>>b_author;
  	myfile>>b_publisher;
  	myfile>>s_name;
  	myfile>>s_rollno;
  	myfile>>s_department;
  	myfile>>DOI;
  	myfile>>DOR;
   }
  cout << "\nThe record in file is deleted successfully......";
  myfile.close();
  temp.close();
  remove("LMS.txt");
  rename("temp.txt", "LMS.txt");
}
void library::sort(){
		if(head==NULL){
		system("cls");
		cout<<"\n\n\t\t\t==============================================================";
	    cout<<"\n\n\t\t\t==================LIBRARY MANAGEMENT SYSTEM===================";
	    cout<<"\n\n\t\t\t==============================================================";
		cout<<"\n\n Linked List is Empty......";
		getch();
		menu1();
	    }
	    int count=0,t_id,t_sRollNo;
	    string t_name,t_author,t_publisher,t_sname,t_sdepartment,t_DOI,t_DOR;
	    Node *ptr=head;
	    while(ptr!=NULL){
	    	count++;
	    	ptr=ptr->next;
		}
		for(int i=1;i<=count;i++){
			Node *ptr=head;
			for(int j=1;j<count;j++){
				if(ptr->id>ptr->next->id){
					//Save data into temp variables
					t_id=ptr->id;
					t_name=ptr->b_name;
					t_author=ptr->b_author;
					t_publisher=ptr->b_publisher;
					t_sname=ptr->s_name;
					t_sRollNo=ptr->s_rollno;
					t_sdepartment=ptr->s_department;
					t_DOI=ptr->DOI;
					t_DOR=ptr->DOR;
					//Save data into current node
					ptr->id=ptr->next->id;
					ptr->b_name=ptr->next->b_name;
					ptr->b_author=ptr->next->b_author;
					ptr->b_publisher=ptr->next->b_publisher;
					ptr->s_name=ptr->next->s_name;
					ptr->s_rollno=ptr->next->s_rollno;
					ptr->s_department=ptr->next->s_department;
					ptr->DOI=ptr->next->DOI;
					ptr->DOR=ptr->next->DOR;
					//Save data into next node
					ptr->next->id=t_id;
					ptr->next->b_name=t_name;
					ptr->next->b_author=t_author;
					ptr->next->b_publisher=t_publisher;
					ptr->next->s_name=t_sname;
					ptr->next->s_rollno=t_sRollNo;
					ptr->next->s_department=t_sdepartment;
					ptr->next->DOI=t_DOI;
					ptr->next->DOR=t_DOR;
				}
				ptr=ptr->next;
			}
	 	}
    }
    void library::show_record(){
    system("cls");
    cout<<"\n\n\t\t\t==============================================================";
	cout<<"\n\n\t\t\t==================LIBRARY MANAGEMENT SYSTEM===================";
	cout<<"\n\n\t\t\t==============================================================";
		Node *ptr=head;
		while(ptr!=NULL){
		cout<<"\n\n Book Information";	
	    cout<<"\n\n Book ID : "<<ptr->id;
       	cout<<"\n\n Book Name : "<<ptr->b_name;
       	cout<<"\n\n Book Author Name : "<<ptr->b_author;
       	cout<<"\n\n Book Publisher Name : "<<ptr->b_publisher;
       	cout<<"\n\n\t\t\t==============================================================";
        cout<<"\n\n Student Information";
        cout<<"\n\n Student Name : "<<ptr->s_name;
   	    cout<<"\n\n Student Roll Number : "<<ptr->s_rollno;
		cout<<"\n\n Student Department : "<<ptr->s_department;
        cout<<"\n\n Date of Issue : "<<ptr->DOI;
        cout<<"\n\n Date of Return : "<<ptr->DOR;
       	cout<<"\n\n===================================================================";
       	cout<<"\n\n*******************************************************************";
		cout<<"\n\n===================================================================";
		ptr=ptr->next;
		}
	}
	void library::show_file(){
		string line;
        ifstream myfile ("LMS.txt");
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
       {
                cout<<line <<'\n';
       }
       myfile.close();
       }

        else
	            cout << "Unable to open file"; 
	}
int main(){
       library l1;int c,ch, password;string name;
       do{
	   cout<<"\n\n\t\t\t==============================================================";
	   cout<<"\n\n\t\t\t==================LIBRARY MANAGEMENT SYSTEM===================";
	   cout<<"\n\n\t\t\t==============================================================";
       cout<<"\n\n\t\t\t==================Login As====================================";
	   cout<<"\n\n1. Librarian\n\n2. Student\n\n Enter Your Choice : ";
       cin>>c;
       if(c==1){
       system("cls");
       cout<<"\n\n\t\t\t==============================================================";
	   cout<<"\n\n\t\t\t==================LIBRARY MANAGEMENT SYSTEM===================";
	   cout<<"\n\n\t\t\t==============================================================";
	   cout<<"\n\n Enter Name : ";
	   cin>>name;
	   cout<<"\n\n Enter Password : ";
	   cin>>password;
	   if(password==1234){
       l1.menu1();}
       else{
       	cout<<"\n\n Invalid Password.....Please Try Again...";
	   }
       }
       else if(c==2){
       system("cls");
       cout<<"\n\n\t\t\t==============================================================";
	   cout<<"\n\n\t\t\t==================LIBRARY MANAGEMENT SYSTEM===================";
	   cout<<"\n\n\t\t\t==============================================================";
	   cout<<"\n\n Enter Name : ";
	   cin>>name;
	   cout<<"\n\n Enter Password : ";
	   cin>>password;
	   if(password==123456){
       l1.menu2();}
       else{
       	cout<<"\n\n Invalid Password.....Please Try Again...";
	   }
	   }
	   else{
	   	cout<<"\n\n Invalid Number.....Please Try Again...";
	   }
	   cout<<"\n\n Do You Want to Run Again....\n\n Enter Any Number Except 0 : ";
	   cin>>ch;
	   system("cls");
   }while(ch!=0);
}
