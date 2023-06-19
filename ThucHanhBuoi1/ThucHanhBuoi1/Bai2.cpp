#include <iostream>
using namespace std;
struct Node {
	int info;
	Node* link;
};
Node* first;
void init() {
	first = NULL;
}
void insert_first(int x) {
	Node* p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}
void insert_last(int x) {
	Node* p = new Node;
	p->info = x;
	p->link = NULL;
	if (first == NULL) {
		first = p;
	}
	else {
		Node* q = first;
		while (q->link != NULL) {
			q = q->link;
		}
		q->link = p;
	}

}
void output() {
	Node* p = first;
	while (p != NULL) {
		cout << p->info <<" ";
		p = p->link;
	}
}
Node *search(int x) {
	Node* p = first;
	while (p != NULL && p->info == x) {
		p = p->link;
	}
	return p;
}
int delete_first() {
	if (first != NULL) {
		Node* p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}
int delete_last() {
	if (first != NULL) {
		Node* p = first, * q = NULL;
		while (p->link != NULL) {
			q = p;
			p = p->link;
		}
		if (p != first) {
			q->link = NULL;
		}
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}
int find_and_delete(int x) {
	if (first != NULL) {
		Node *p = first, *q = NULL;
		while (p != NULL && p->info != x) {
			q = p;
			p = p->link;
		}
		if (p!=NULL) {
			q->link = p->link;
			delete p;
			return 1;
		}
		else {
			return 0;
		}
		
	}
	return 0;
}
void insertGiamDan(int x) {
	Node* p = first;
	Node* newNode = new Node;
	newNode->info = x;
	newNode->link = NULL;
	Node* q = NULL;
	while (p != NULL && p->info > x) {
		q = p;
		p = p->link;
	}
	if (q != NULL) {
		q->link = newNode;
		newNode->link = p;
	}
	else {
		newNode->link = first;
		first = newNode;
	}
}
int main() {
	int x, t, chon;
	Node* tmp;
	init();
	while (true) {
		cout << "\n Nhap chon:\n"
			<< "0. Thoat\n"
			<< "1. Xuat danh sach\n"
			<< "2. Tim\n"
			<< "3. Xoa Dau\n"
			<< "4. Xoa Cuoi \n"
			<< "5. Tim va xoa phan tu \n"
			<< "6. Them dau \n"
			<< "7. Them cuoi \n"
			<< "8. Them giam dan \n"
			<< "Chon: ";
		cin >> chon;
		switch (chon) {
		case 0:
			return 1;
			break;
		case 1:
			cout << "Danh sach phan tu la:";
			output();
			break;
		case 2:
			cout << "Nhap gia tri can tim trong danh sach:";
			cin >> x;
			tmp = search(x);
			if (tmp != NULL) {
				cout << "Gia tri co trong dslk";
				output();
			}
			else
				cout << "Gia tri khong co trong danh sach";
			break;

		case 3:
			t = delete_first();
			if (t != 0)
				cout << "Xoa thanh cong!";
			else
				cout << "Xoa that bai!";
			break;
		case 4:
			t = delete_last();
			if (t != 0)
				cout << "Xoa thanh cong!";
			else
				cout << "Xoa that bai!";
			break;
		case 5:
			cout << "Nhap gia tri can tim de xoa:";
			cin >> x;
			t = find_and_delete(x);
			if (t != 0)
				cout << "Xoa thanh cong!";
			else
				cout << "Xoa that bai vi khong tim thay phan tu hoac danh sach rong!";
			break;
		case 6:
			cout << "Nhap gia tri can them:";
			cin >> x;
			insert_first(x);
			cout << "Danh sach sau khi them dau:\n";
			output();
			break;
		case 7:
			cout << "Nhap gia tri can them:";
			cin >> x;
			insert_last(x);
			cout << "Danh sach sau khi them cuoi:\n";
			output();
			break;
		case 8:
			cout << "Nhap gia tri can them:";
			cin >> x;
			insertGiamDan(x);
			cout << "Danh sach sau khi them giam dan:\n";
			output();
			cout << endl;
			break;
		default:
			cout << "gia tri khong hop le! \n";
			break;

		}
	}
	return 0;
}

