#include "Library.h"

void hienMenu() {
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << "\n1. Khoi tao danh sach sinh vien rong.";
	cout << "\n2. Xoa danh sach sinh vien.";
	cout << "\n3. Them mot sinh vien vao danh sach khong";
	cout << "\n   kiem tra ma Code trung.";
	cout << "\n4. Xoa mot sinh vien trong danh sach.";
	cout << "\n5. Tim kiem sinh vien danh sach.";
	cout << "\n6. Cap nhat thong tin sinh vien danh sach.";
	cout << "\n7. Sap xep danh sach sinh vien theo diem trung binh.";
	cout << "\n8. Tach tat ca sinh vien co ma code trung.";
	cout << "\n9. Xoa tat ca sinh vien co ma code trung.";
	cout << "\n10. Nhap vao 2 danh sach sinh vien cua 2 lop";
	cout << "\n    khac nhau va tron hai danh sach nay theo";
	cout << "\n    diem toan (Math) tang dan.";
	cout << "\n11. Tim kiem nhi phan theo diem toan.";
	cout << "\n12. Kiem tra danh sach tang dan.";
	cout << "\n13. Kiem tra danh sach giam dan.";
	cout << "\n14. Kiem mot nua danh sach dau co tong so";
	cout << "\n    sinh vien gioi lon hon mot nua cua danh";
	cout << "\n    sach sau hay khong?.";
	cout << "\n15. Tim cap sinh vien co tong diem toan nho";
	cout << "\n    hon 5 dau tien.";
	cout << "\n16. Them sinh vien co kiem tra ma Code trung.";
	cout << "\n17. Tach sinh vien gioi.";
	cout << "\n18. Xuat danh sach.";
	cout << "\n19. Tach danh sach sinh vien co thanh tich";
	cout << "\n    hoc tap 3 mon hoc tot nhat (Tren 6.5).";
	cout << "\n20. Xuat sinh vien xuat sac nhat trong danh sach.";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

void menu(nodeptr& list) {
	int choose, code;
	nodeptr new_List = NULL, duplicate_List = NULL, list1 = NULL, list2 = NULL, listbeta = NULL, list3mon = NULL;
	do {
		hienMenu();
		cout << "Nhap chuc nang: ";
		cin >> choose;
		switch (choose) {
		case 1:
			system("cls");
			init(list);
			cout << "Da tao danh sach rong!\n";
			break;
		case 2:
			system("cls");
			delete_All_List(list);
			cout << "Da xoa danh sach!";
			break;
		case 3:
			SV sv;
			system("cls");
			input_Info_Student(sv);
			add_Last(list, sv);
			cout << "Da them sinh vien vao danh sach";
			break;
		case 4:
			system("cls");
			cout << "Nhap code sinh vien muon xoa: ";
			cin >> code;
			delete_Student_Code(list, code);
			cout << "Da xoa sinh vien!" << "\n";
			break;
		case 5:
			system("cls");
			cout << "Nhap code sinh vien muon tim kiem: ";
			cin >> code;
			search_Student_Code(list, code);
			break;
		case 6:
			system("cls");
			cout << "Nhap code sinh vien muon cap nhat: ";
			cin >> code;
			update_Info_Student(list, code);
			break;
		case 7:
			system("cls");
			sort_By_Average_Subject_Score(list);
			cout << "Da sap xep danh sach tang dan theo diem trung binh";
			break;
		case 8:
			system("cls");
			split_Duplicate_Code(list, duplicate_List);
			cout << "\nDanh sach sinh vien co ma code trung:\n";
			output_List_Student(duplicate_List);
			break;
		case 9:
			system("cls");
			delete_All_Duplicate_Code(list);
			cout << "\nDa xoa tat ca sinh vien co ma code trung\n";
			break;
		case 10:
			system("cls");
			input_2_List(list1, list2);
			new_List = join_2_list(list1, list2);
			sort_By_Math(new_List);
			system("cls");
			cout << "Danh sach sinh vien sau khi gop va sap xep theo diem toan tang dan.\n";
			output_List_Student(new_List);
			break;
		case 11:
			system("cls");
			int mathScore;
			cout << "Nhap diem toan muon tim: ";
			cin >> mathScore;
			bool found;

			SV result = binary_Search_Student_Math_Score(new_List, mathScore, found);
			if (found) {
				print_Header_Output();
				output_Student(result);
			}
			else
				cout << "\nKhong tim thay.\n";
			break;
		case 12:
			system("cls");
			int choose_Check;
			cout << "Ban muon kiem tra danh sach tang dan theo (1) Toan, (2) English, (3) C++ hay (4) Average score? ";
			cin >> choose_Check;
			if (choose_Check == 1) {
				cout << "Kiem tra danh sach tang dan theo diem toan...";
				if (check_Ascending_By_Math(list))
					cout << "\nDanh sach tang dan theo diem toan!";
				else
					cout << "\nDanh sach khong tang dan theo diem toan!";
			}
			if (choose_Check == 2) {
				cout << "Kiem tra danh sach tang dan theo diem English...";
				if (check_Ascending_By_English(list))
					cout << "\nDanh sach tang dan theo diem English!";
				else
					cout << "\nDanh sach khong tang dan theo diem English!";
			}
			if (choose_Check == 3) {
				cout << "Kiem tra danh sach tang dan theo diem C++...";
				if (check_Ascending_By_Cpp(list))
					cout << "\nDanh sach tang dan theo diem C++!";
				else
					cout << "\nDanh sach khong tang dan theo diem C++!";
			}
			if (choose_Check == 4) {
				cout << "Kiem tra danh sach tang dan theo diem trung binh...";
				if (check_Ascending_By_Average_Score(list))
					cout << "\nDanh sach tang dan theo diem trung binh!";
				else
					cout << "\nDanh sach khong tang dan theo diem trung binh!";
			}
			break;

		case 13:
			system("cls");
			int choose_Check1;
			cout << "Ban muon kiem tra danh sach giam dan theo (1) Toan, (2) English, (3) C++ hay (4) Average score? ";
			cin >> choose_Check1;
			if (choose_Check1 == 1) {
				cout << "Kiem tra danh sach giam dan theo diem toan...";
				if (check_Descending_By_Math(list))
					cout << "\nDanh sach giam dan theo diem toan!";
				else
					cout << "\nDanh sach khong giam dan theo diem toan!";
			}
			if (choose_Check1 == 2) {
				cout << "Kiem tra danh sach giam dan theo diem English...";
				if (check_Descending_By_English(list))
					cout << "\nDanh sach giam dan theo diem English!";
				else
					cout << "\nDanh sach khong giam dan theo diem English!";
			}
			if (choose_Check1 == 3) {
				cout << "Kiem tra danh sach giam dan theo diem C++...";
				if (check_Descending_By_Cpp(list))
					cout << "\nDanh sach giam dan theo diem C++!";
				else
					cout << "\nDanh sach khong giam dan theo diem C++!";
			}
			if (choose_Check1 == 4) {
				cout << "Kiem tra danh sach giam dan theo diem trung binh...";
				if (check_Descending_By_Average_Score(list))
					cout << "\nDanh sach giam dan theo diem trung binh!";
				else
					cout << "\nDanh sach khong giam dan theo diem trung binh!";
			}
			break;
		case 14:
			system("cls");
			if (check_HalfList(list))
				cout << "Tong so sinh vien gioi cua danh sach dau lon hon mot nua cua danh sach sau!";
			else
				cout << "Tong so sinh vien gioi cua danh sach dau khong lon hon mot nua cua danh sach sau!";
			break;
		case 15:
			system("cls");
			find_CoupleStudentScore_LowerFive(list);
			break;
		case 16:
			system("cls");
			input_Info_Student_ktCode_trung(list, sv);
			break;
		case 17:
			system("cls");
			output_List_Student(list);
			cout << "\nDanh sach cac sinh vien gioi: \n";
			output_List_Student(split_SV_XL_gioi(list, listbeta));
			break;

		case 18:
			system("cls");
			output_List_Student(list);
			if (duplicate_List != NULL) {
				cout << "\nDanh sach sinh vien co ma code trung:\n";
				output_List_Student(duplicate_List);
			}
			break;

		case 19:
			system("cls");
			output_List_Student(list);
			cout << "\nDanh sach cac sinh vien co thanh tich hoc tap 3 mon > 6.5: \n";

			output_List_Student(split_SV_3Mon_Totnhat(list, list3mon));

			break;
		case 20:
			system("cls");
			output_List_Student(list);
			cout << "\nSinh vien xuat nhat trong danh sach: ";

			print_Header_Output();
			output_Student(find_SV_xuatsacnhat(list)->data);
			break;

		default:
			system("cls");
			cout << "Nhap sai roi!";
			break;
		}
	} while (choose != 0);
}