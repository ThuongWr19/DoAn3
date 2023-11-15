#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

typedef struct Student {
	int code;
	char* name;
	float* subject;//Math, english, c++
}SV;
typedef SV typeinfo;

struct node {
	typeinfo data;
	node* link;
};

typedef node* nodeptr;

void print_Header_Output();
float Average_Subject_Score(SV sv);
bool isEmpty(nodeptr list);
int length(nodeptr list);
nodeptr make_Node(typeinfo data);
void init(nodeptr& list);
void delete_All_List(nodeptr& list);
void add_Last(nodeptr& list, typeinfo x);
void input_Info_Student(SV& sv);
void delete_Student_Code(nodeptr& list, int code);
void output_Student(SV data);
void search_Student_Code(nodeptr list, int code);
void output_List_Student(nodeptr list);
void update_Info_Student(nodeptr& list, int code);
void sort_By_Average_Subject_Score(nodeptr& list);
void split_Duplicate_Code(nodeptr& list, nodeptr& duplicate_List);
void delete_All_Duplicate_Code(nodeptr& list);
void input_2_List(nodeptr& list1, nodeptr& list2);
nodeptr join_2_list(nodeptr& list1, nodeptr& list2);
void sort_By_Math(nodeptr& list);
SV binary_Search_Student_Math_Score(nodeptr list, int mathScore, bool& found);
bool check_Ascending_By_Math(nodeptr list);
bool check_Ascending_By_English(nodeptr list);
bool check_Ascending_By_Cpp(nodeptr list);
bool check_Ascending_By_Average_Score(nodeptr list);
bool check_Descending_By_Math(nodeptr list);
bool check_Descending_By_English(nodeptr list);
bool check_Descending_By_Cpp(nodeptr list);
bool check_Descending_By_Average_Score(nodeptr list);
bool check_HalfList(nodeptr list);
void find_CoupleStudentScore_LowerFive(nodeptr list);
void menu(nodeptr& list);
void init(nodeptr& list);
void input_Info_Student_ktCode_trung(nodeptr &list,SV& sv);
nodeptr split_SV_XL_gioi(nodeptr& list, nodeptr& listbeta);
nodeptr find_SV_xuatsacnhat(nodeptr list);
nodeptr split_SV_3Mon_Totnhat(nodeptr& list, nodeptr& list3mon);