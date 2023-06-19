#include <iostream>
#define MAX 100
using namespace std;
int a[MAX];
int n;

void input(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Nhap phan tu thu " << i + 1 << ":";
		cin >> a[i];
	}
}

void output(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

int search(int a[], int n, int x) {
	int i = 0;
	while (i < n && a[i] != x) {
		i++;
	}
	if (i == n) {
		return -1;
	}
	else {
		return i;
	}
}
int insertTaiPhanTui(int a[], int& n, int x, int i) {
	if (i <= n && n < MAX) {
		for (int j = n - 1; j >= i; j--)
			a[j + 1] = a[j];
		n++;
		a[i] = x;
		return 1;
	}
	return 0;
}
int deleteTaiPhanTui(int a[], int& n, int i) {
	if (i <= n && n < MAX) {
		for (int j = i; j < n - 1; j++)
			a[j] = a[j + 1];
		n--;
		return 1;
	}
	return 0;
}
void insert_first(int a[], int& n, int x) {
	for (int i = n - 1; i >= 0; i--) {
		a[i + 1] = a[i];
	}
	n++;
	a[0] = x;
}
void insert_last(int a[], int& n, int x) {
	for (int i = 0; i < n; i++)
	{
		a[n] = x;
	}
	n++;
}
void delete_first(int a[], int& n) {
	for (int j = 0; j < n - 1; j++)
		a[j] = a[j + 1];
	n--;
}
void delete_last(int a[], int& n) {
	n--;
}
int TimVaXoa(int a[], int& n, int x) {
	int found = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			for (int j = i; j < n - 1; j++) {
				a[j] = a[j + 1];
			}
			i--;
			n--;
			found++;
			break;
		}
	}
	if (found == 1) {
		return 1;
	}
	else {
		return 0;
	}
}
int TimPhanTuVaXoaAll(int a[], int& n, int x) {
	int found = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			for (int j = i; j < n - 1; j++) {
				a[j] = a[j + 1];
			}
			i--;
			n--;
			found++;
		}
	}
	if (found != 0) {
		return 1;
	}
	else {
		return 0;
	}
}
int main1() {
	int x, i, t, chon;
	//cout << "Nhap vao so luong phan tu cua mang:";
	//cin >> n;
	//cout << "Nhapp mang: \n";
	//input(a, n);
	while (true) {
		cout << "\nNhap chon:\n"
			<< "0. Thoat\n"
			<< "1. Nhap vao n phan tu\n"
			<< "2. Xuat danh sach\n"
			<< "3. Tim\n"
			<< "4. Xoa Dau\n"
			<< "5. Xoa Cuoi \n"
			<< "6. xoa tai vi tri thu i \n"
			<< "7. Them dau \n"
			<< "8. Them cuoi \n"
			<< "9. Them tai vi tri thu i \n"
			<< "10. Tim va xoa phan tu dau tien tim thay \n"
			<< "11. Tim va xoa tat ca phan tu do co trong mang \n"
			<< "Chon: ";
		cin >> chon;
		switch (chon) {
		case 0:
			return 1;
			break;
		case 1:
			cout << "Nhap n:";
			cin >> n;
			input(a, n);
			break;
		case 2:
			cout << "Cac gia tri cua mang: \n";
			output(a, n);
			break;
		case 3:
			cout << "Nhap gia tri can tim:";
			cin >> x;
			t = search(a, n, x);
			if (t != 0)
				cout << "Phan tu duoc tim thay tai vi tri thu " << t << endl;
			else
				cout << "Khong tim thay duoc phan tu \n";
			break;
		case 4:
			delete_first(a, n);
			cout << "Xoa thanh cong \n";
			output(a, n);
			break;
		case 5:
			delete_last(a, n);
			cout << "Xoa thanh cong \n";
			output(a, n);
			break;
		case 6:
			cout << "Nhap gia tri can xoa:";
			cin >> i;
			t = deleteTaiPhanTui(a, n, i);
			if (t == 1) {
				cout << "Xoa thanh cong!\n";
				output(a, n);
			}
			else
				cout << "Xoa that bai!\n";
			break;
		case 7:
			cout << "Nhap gia tri can them:";
			cin >> x;
			insert_first(a, n, x);
			cout << "Them thanh cong \n";
			output(a, n);
			break;
		case 8:
			cout << "Nhap gia tri can them:";
			cin >> x;
			insert_last(a, n, x);
			cout << "Them thanh cong \n";
			output(a, n);
			break;
		case 9:
			cout << "Nhap gia tri can them:";
			cin >> x;
			cout << "Them vao vi tri thu :";
			cin >> i;
			t = insertTaiPhanTui(a, n, x, i);
			if (t == 1) {
				cout << "Them thanh cong!\n";
				output(a, n);
			}
			else {
				cout << "Them that bai!";

			}
			break;
		case 10:
			cout << "Nhap gia tri can tim:";
			cin >> x;
			t = TimVaXoa(a, n, x);
			if (t != 0)
			{
				cout << "Tim va xoa thanh cong!\n";
				output(a, n);
			}
			else
				cout << "Khong tim thay duoc phan tu \n";
			break;
		case 11:
			cout << "Nhap gia tri can tim:";
			cin >> x;
			t = TimPhanTuVaXoaAll(a, n, x);
			if (t != 0)
			{
				cout << "Tim va xoa thanh cong!\n";
				output(a, n);
			}
			else
				cout << "Khong tim thay duoc phan tu \n";
			break;
		default:
			cout << "gia tri khong hop le! \n";
			break;
		}
	}
	return 0;
}