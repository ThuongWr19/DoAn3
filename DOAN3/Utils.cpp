#include "Library.h"

void print_Header_Output() {
	cout << setw(30) << left
		<< "Name";
	cout << setw(12) << left
		<< "| Code";
	cout << setw(10) << left
		<< "| Math";
	cout << setw(10) << left
		<< "| English";
	cout << setw(10) << left
		<< "| C++";
	cout << setw(20) << left
		<< "| Average score" << endl;
}

bool isEmpty(nodeptr list) {
	return list == NULL;
}

int length(nodeptr list) {
	int count = 0;
	while (list) {
		count++;
		list = list->link;
	}
	return count;
}

nodeptr nodeIndex(nodeptr list, int idx) {
	int count = 0;
	nodeptr p = list;
	while (p != NULL) {
		if (count == idx) return p;
		count++;
		p = p->link;
	}
	return NULL;
}

float Average_Subject_Score(SV sv) {
	return (sv.subject[0] + sv.subject[1] + sv.subject[2]) / 3;
}

void output_Student(SV data) {
	cout << setw(30) << left
		<< data.name << "| ";
	cout << setw(10) << left
		<< data.code << "| ";
	cout << setw(8) << left
		<< data.subject[0] << "| ";
	cout << setw(8) << left
		<< data.subject[1] << "| ";
	cout << setw(8) << left
		<< data.subject[2] << "| ";
	cout << setw(8) << left
		<< Average_Subject_Score(data)
		<< endl;
}

nodeptr make_Node(typeinfo data) {
	nodeptr p = new node;
	p->data = data;
	p->link = NULL;

	return p;
}

//1. Tạo danh sách sinh viên rỗng.
void init(nodeptr& list) {
	list = NULL;
}

//2. Xóa danh sách sinh viên.
void delete_All_List(nodeptr& list) {
	free(list);
}

//3. Thêm một sinh viên vào danh sách. Không có kiểm tra code trùng
void add_Last(nodeptr& list, typeinfo x) {
	if (isEmpty(list))
		list = make_Node(x);
	else {
		nodeptr r;
		for (r = list; r->link != NULL; r = r->link);
		r->link = make_Node(x);
	}
}

void input_Info_Student(SV& sv) {
	cout << "\nNhap code: ";
	cin >> sv.code;

	cout << "Nhap name: ";
	cin.ignore();
	char temp[100];
	cin.getline(temp, 100);
	sv.name = new char[strlen(temp) + 1];
	strcpy_s(sv.name, strlen(temp) + 1, temp);

	sv.subject = new float[3];
	cout << "Nhap Math: ";
	cin >> sv.subject[0];
	cout << "Nhap English: ";
	cin >> sv.subject[1];
	cout << "Nhap C++: ";
	cin >> sv.subject[2];
}

//4. Xóa một sinh viên ra khỏi danh sách.
void delete_Student_Code(nodeptr& list, int code) {

	if (list == nullptr) {
		cout << "Danh sach rong.\n";
		return;
	}
	nodeptr current = list;
	nodeptr previous = nullptr;

	while (current != NULL && current->data.code != code) {
		previous = current;
		current = current->link;
	}
	if (current != nullptr) {
		if (previous == nullptr)
			list = current->link;
		else
			previous->link = current->link;

		delete[] current->data.name;
		delete[] current->data.subject;
	}
	else
		cout << "Khong tim thay sinh vien co code: " << code << "\n";
}

//5. Tìm kiếm một sinh viên có trong danh sách.
void search_Student_Code(nodeptr list, int code) {

	if (list == nullptr) {
		cout << "Danh sach rong.\n";
		return;
	}
	nodeptr p = list;
	bool flag = false;
	print_Header_Output();
	while (p) {
		if (p->data.code == code) {
			output_Student(p->data);
			flag = true;
		}
		p = p->link;
	}
	if (!flag) {
		system("cls");
		cout << "Khong tim thay sinh vien!\n";
	}
}

//6. Cập nhật thông tin một sinh viên có trong danh sách.
void update_Info_Student(nodeptr& list, int code) {

	if (list == nullptr) {
		cout << "Danh sach rong.\n";
		return;
	}
	nodeptr p = list;
	while (p) {
		if (p->data.code == code) {
			cout << "Hay nhap thong tin moi.";
			input_Info_Student(p->data);
		}
		p = p->link;
	}
}

//7. Sắp xếp danh sách tăng dần theo điểm trung bình 3 môn học.
void sort_By_Average_Subject_Score(nodeptr& list) {

	if (list == nullptr) {
		cout << "Danh sach rong.\n";
		return;
	}
	//duyệt từ đầu mảng đến cuối mảng
	for (nodeptr listTemp = list; listTemp->link != NULL; listTemp = listTemp->link) {
		nodeptr min = listTemp;
		//duyệt từ phẩn tử tiếp theo của listTemp đến cuối mảng
		for (nodeptr listTemp_Next = listTemp->link; listTemp_Next != NULL; listTemp_Next = listTemp_Next->link)
			if (Average_Subject_Score(listTemp->data) > Average_Subject_Score(listTemp_Next->data))
				min = listTemp_Next;
		//Swap
		SV temp = min->data;
		min->data = listTemp->data;
		listTemp->data = temp;
	}
}

//8. Tách tất cả sinh viên có mã code trùng có trong danh sách.
void split_Duplicate_Code(nodeptr& list, nodeptr& duplicate_List) {

	if (list == nullptr) {
		cout << "Danh sach rong.\n";
		return;
	}
	//Duyệt từng phân tử của danh sách
	for (nodeptr node_Check = list; node_Check != NULL && node_Check->link != NULL; node_Check = node_Check->link) {
		//Duyệt lại danh sách để kiểm tra node_Check có phần tử trùng không
		nodeptr curr = list;
		while (curr != NULL && curr->link != NULL) {
			if (node_Check != curr && node_Check->data.code == curr->link->data.code) {
				add_Last(duplicate_List, curr->link->data); //Thêm phần tử trùng vào danh sách mã trùng
				//Lưu trữ con trỏ đến phần tử cần xóa
				nodeptr temp = curr->link;
				curr->link = temp->link; //Bỏ qua phần tử cần xóa
				delete temp; //Xóa phần tử khỏi danh sách gốc
			}
			else
				curr = curr->link; //Di chuyển con trỏ nếu không xóa phần tử
		}
	}
}
// 9. Xóa tất cả các sinh viên có mã code trùng nhau
void delete_All_Duplicate_Code(nodeptr& list) {

	if (list == nullptr) {
		cout << "Danh sach rong.\n";
		return;
	}
	//Duyệt từng phân tử của danh sách
	for (nodeptr node_Check = list; node_Check != NULL && node_Check->link != NULL; node_Check = node_Check->link) {
		//Duyệt lại danh sách để kiểm tra node_Check có phần tử trùng không
		nodeptr curr = list;
		while (curr != NULL && curr->link != NULL) {
			if (node_Check != curr && node_Check->data.code == curr->link->data.code) {
				//Lưu trữ con trỏ đến phần tử cần xóa
				nodeptr temp = curr->link;
				curr->link = temp->link; //Bỏ qua phần tử cần xóa
				delete temp; //Xóa phần tử
			}
			else
				curr = curr->link; //Di chuyển con trỏ nếu không xóa phần tử
		}
	}
}

//10. Nhập 2 danh sách sinh viên của 2 lớp khác nhau và trộn hai danh sách này theo điểm toán (math)tăng dần
//Nhập 2 danh sách
void input_2_List(nodeptr& list1, nodeptr& list2) {
	SV sv1, sv2;
	int soLuong1, soLuong2;
	cout << "Nhap so luong sinh vien muon them vao danh sach 1: ";
	cin >> soLuong1;
	cout << "Nhap danh sach sinh vien 1\n";
	for (int i = 0; i < soLuong1; i++) {
		input_Info_Student(sv1);
		add_Last(list1, sv1);
	}
	cout << "\nNhap so luong sinh vien muon them vao danh sach 2: ";
	cin >> soLuong2;
	cout << "Nhap danh sach sinh vien 2\n";
	for (int i = 0; i < soLuong2; i++) {
		input_Info_Student(sv2);
		add_Last(list2, sv2);
	}
}
//Gộp 2 danh sách
nodeptr join_2_list(nodeptr& list1, nodeptr& list2) {
	nodeptr new_List = NULL;

	nodeptr temp1 = list1;
	while (temp1) {
		add_Last(new_List, temp1->data);
		temp1 = temp1->link;
	}

	nodeptr temp2 = list2;
	while (temp2) {
		add_Last(new_List, temp2->data);
		temp2 = temp2->link;
	}
	return new_List;
}
//Sắp xếp theo điểm toán
void sort_By_Math(nodeptr& list) {

	if (list == nullptr) {
		cout << "Danh sach rong.\n";
		return;
	}
	//duyệt từ đầu mảng đến cuối mảng
	for (nodeptr listTemp = list; listTemp != NULL; listTemp = listTemp->link) {
		nodeptr min = listTemp;
		//duyệt từ phẩn tử tiếp theo của listTemp đến cuối mảng
		for (nodeptr listTemp_Next = listTemp->link; listTemp_Next != NULL; listTemp_Next = listTemp_Next->link)
			if (min->data.subject[0] > listTemp_Next->data.subject[0])
				min = listTemp_Next;
		//Swap
		SV temp = min->data;
		min->data = listTemp->data;
		listTemp->data = temp;
	}
}

//11. Tìm kiếm theo giải thuật nhị phân trên danh sách đã sắp xếp trong câu 10.

// Lấy nút ở chỉ số cụ thể trong danh sách
nodeptr get_node_at_index(nodeptr list, int index) {
	for (int i = 0; i < index && list != nullptr; ++i) {
		list = list->link;
	}
	return list;
}

SV binary_Search_Student_Math_Score(nodeptr list, int mathScore, bool& found) {
	nodeptr curr = list;
	int left = 0;
	int right = length(list) - 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		nodeptr midNode = get_node_at_index(list, mid);

		if (midNode != nullptr && midNode->data.subject[0] == mathScore) {
			found = true;
			return midNode->data;
		}
		else if (midNode != nullptr && midNode->data.subject[0] < mathScore)
			left = mid + 1;
		else
			right = mid - 1;
	}

	found = false;
	return {};
}

//12. Kiểm tra một danh sách là danh sách tăng dần
//Kiểm tra theo điểm toán
bool check_Ascending_By_Math(nodeptr list) {
	nodeptr p = list;
	while (p && p->link) {
		if (p->data.subject[0] > p->link->data.subject[0])
			return false;
		p = p->link;
	}
	return true;
}

//Kiểm tra theo điểm tiếng anh
bool check_Ascending_By_English(nodeptr list) {
	nodeptr p = list;
	while (p && p->link) {
		if (p->data.subject[1] > p->link->data.subject[2])
			return false;
		p = p->link;
	}
	return true;
}

//Kiểm tra theo điểm C++
bool check_Ascending_By_Cpp(nodeptr list) {
	nodeptr p = list;
	while (p && p->link) {
		if (p->data.subject[2] > p->link->data.subject[2])
			return false;
		p = p->link;
	}
	return true;
}

//Kiểm tra theo điểm trung bình
bool check_Ascending_By_Average_Score(nodeptr list) {
	nodeptr p = list;
	while (p && p->link) {
		if (Average_Subject_Score(p->data) > Average_Subject_Score(p->link->data))
			return false;
		p = p->link;
	}
	return true;
}

//13. Kiểm tra một danh sách là danh sách giảm dần
//Kiểm tra theo điểm toán
bool check_Descending_By_Math(nodeptr list) {
	nodeptr p = list;
	while (p && p->link) {
		if (p->data.subject[0] < p->link->data.subject[0])
			return false;
		p = p->link;
	}
	return true;
}

//Kiểm tra theo điểm tiếng anh
bool check_Descending_By_English(nodeptr list) {
	nodeptr p = list;
	while (p && p->link) {
		if (p->data.subject[1] < p->link->data.subject[2])
			return false;
		p = p->link;
	}
	return true;
}

//Kiểm tra theo điểm C++
bool check_Descending_By_Cpp(nodeptr list) {
	nodeptr p = list;
	while (p && p->link) {
		if (p->data.subject[2] < p->link->data.subject[2])
			return false;
		p = p->link;
	}
	return true;
}

//Kiểm tra theo điểm trung bình
bool check_Descending_By_Average_Score(nodeptr list) {
	nodeptr p = list;
	while (p && p->link) {
		if (Average_Subject_Score(p->data) < Average_Subject_Score(p->link->data))
			return false;
		p = p->link;
	}
	return true;
}

//14. Kiểm tra trong một nữa danh sách đầu có tổng số sinh viên giỏi lớn hơn một nữa của danh sách sau hay không ?
bool check_HalfList(nodeptr list) {
	int sum1 = 0, sum2 = 0, count;
	int size_List = length(list);
	nodeptr listTemp1, listTemp2;
	//Duyệt đầu danh sách đến giữa danh sách
	for (listTemp1 = list, count = 0; count < length(list) / 2; count++, listTemp1 = listTemp1->link)
		if (Average_Subject_Score(listTemp1->data) > 8.0)
			sum1++;
	//Duyệt nửa danh sách đến cuối danh sách
	for (listTemp2 = nodeIndex(list, size_List / 2); listTemp2->link != NULL; listTemp2 = listTemp2->link)
		if (Average_Subject_Score(listTemp2->data) > 8.0)
			sum2++;

	if (sum1 > sum2)
		return true;
	else
		return false;
}

//15. Tìm cặp sinh viên có tổng điểm toán nhỏ hơn 5 đầu tiên.
void find_CoupleStudentScore_LowerFive(nodeptr list) {
	nodeptr listTemp1, listTemp2;
	int count = 0;
	print_Header_Output();
	for (listTemp1 = list; listTemp1 != NULL && listTemp1->link != NULL; listTemp1 = listTemp1->link)
		for (listTemp2 = listTemp1->link; listTemp2 != NULL; listTemp2 = listTemp2->link)
			if ((double)listTemp1->data.subject[0] + (double)listTemp2->data.subject[0] < 5.0 && listTemp1 != listTemp2) {
				output_Student(listTemp1->data);
				output_Student(listTemp2->data);
				break;
			}
}

//cau 16 Thêm sinh viên vào danh sách có kiểm tra mã code trùng, nếu trùng sẽ yêu cầu nhập lại
void input_Info_Student_ktCode_trung(nodeptr& list, SV& sv) {
	do {
		nodeptr p = list;
		cout << "\nNhap code(0.Exit!): ";
		cin >> sv.code;
		if (sv.code == 0)
			break;

		while (list) {
			if (sv.code == list->data.code) {
				cout << "\nCode trung, nhap lai Code(0.Exit!): ";
				cin >> sv.code;
			}
			else
				break;
			if (sv.code == list->data.code)
				list = list;
			else
				list = list->link;
		}
		list = p;


		cout << "Nhap name: ";
		cin.ignore();
		char temp[100];
		cin.getline(temp, 100);
		sv.name = new char[strlen(temp) + 1];
		strcpy_s(sv.name, strlen(temp) + 1, temp);

		sv.subject = new float[3];
		cout << "Nhap Math: ";
		cin >> sv.subject[0];
		cout << "Nhap English: ";
		cin >> sv.subject[1];
		cout << "Nhap C++: ";
		cin >> sv.subject[2];
		add_Last(list, sv);
	} while (true);
}

//17. Tách tất cả các sinh viên xếp loại giỏi ra thành một danh sách khác
nodeptr split_SV_XL_gioi(nodeptr& list, nodeptr& listbeta) {
	while (list != NULL && list->link != NULL) {

		if (Average_Subject_Score(list->link->data) >= 8.0) {
			add_Last(listbeta, list->link->data);
			nodeptr temp = list->link;
			list->link = temp->link;
			delete(temp);
		}
		else if (Average_Subject_Score(list->data) >= 8.0) {
			add_Last(listbeta, list->data);
			nodeptr p = list;
			list = list->link;
			delete(p);
		}
		else
			list = list->link;

	}
	return listbeta;
}

//18. Xuất danh sách sinh viên
void output_List_Student(nodeptr list) {

	print_Header_Output();
	while (list != nullptr) {
		output_Student(list->data);
		list = list->link;
	}
}

//Cau 19. Tách danh sách sinh viên có thành tích học tập 3 môn học tốt nhất ( trên 6.5)
nodeptr split_SV_3Mon_Totnhat(nodeptr& list, nodeptr& list3mon) {

	for (nodeptr node_Check = list; node_Check != NULL; node_Check = node_Check->link) {

		if (node_Check->data.subject[0] >= 6.5 && node_Check->data.subject[1] >= 6.5 && node_Check->data.subject[2] >= 6.5)
			add_Last(list3mon, node_Check->data);

	}
	return list3mon;
}

//Cau 20 xuat sinh vien xuat sac nhat

nodeptr find_SV_xuatsacnhat(nodeptr list) {
	nodeptr p = list;

	while (list != NULL && list->link->link != NULL) {
		if (Average_Subject_Score(p->data) <= Average_Subject_Score(list->link->data))
			p = list->link;
		list = list->link;
	}
	return p;
}