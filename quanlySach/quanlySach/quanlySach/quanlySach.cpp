#include<iostream>
#include"Sach.h"
#include "SachGiaoKhoa.h"
#include"SachThamKhao.h"
using namespace std;
void nhapCung(vector<Sach*>& mangSach) {
	mangSach.push_back(new SachGiaoKhoa("TH", "27/09/2024", 10000, 5, "Tan Ngoc", "moi"));
	mangSach.push_back(new SachGiaoKhoa("VL", "16/09/2005", 10000, 3, "Tien Vy", "cu"));
	mangSach.push_back(new SachGiaoKhoa("VH", "07/12/2001", 50000, 2, "Ngoc Thanh", "cu"));
	mangSach.push_back(new SachGiaoKhoa("TH", "21/01/1999", 2000, 5, "Tan Ngoc", "moi"));
	mangSach.push_back(new SachGiaoKhoa("HH", "10/08/2013", 32000, 12, "Van Dong", "cu"));
	mangSach.push_back(new SachGiaoKhoa("MT", "06/04/2006", 50000, 11, "Ngoc Thanh", "cu"));
	mangSach.push_back(new SachThamKhao("AV", "12/09/2012", 300000, 4, "Van Thanh", 5000));
	mangSach.push_back(new SachThamKhao("TD", "31/02/2023", 10000, 12, "Kim Dong", 1000));
	mangSach.push_back(new SachThamKhao("HH", "22/05/2015", 590000, 9, "Hoang Kim", 2000));
	mangSach.push_back(new SachThamKhao("AV", "11/09/2022", 310000, 4, "Van Thanh", 5000));
	mangSach.push_back(new SachThamKhao("TD", "31/02/2023", 40000, 7, "Tan Ngoc", 1000));
	mangSach.push_back(new SachThamKhao("HH", "29/04/2015", 521000, 9, "Quoc Dat", 2000));
}

void nhapMem(vector<Sach*>& mangSach) {
	int gk, tk, chon, dem;
	string maSach;
	string ngayNhap;
	double donGia;
	int soLuong;
	string nhaXuatBan;
	string tinhTrang;
	double thue;
	while (true)
	{
		cout << "\t\tCHON LOAI SACH " << endl;
		cout << "1. Sach Giao Khoa " << endl;
		cout << "2. Sach Tham Khao " << endl;
		cout << "3. Thoat " << endl;
		cout << "Chon: ";
		cin >> chon;
		if (chon == 1) {
			cout << "Nhap so sach giao khoa: ";
			cin >> gk;
			cout << "\n\n\t\tNHAP SACH GIAO KHOA" << endl;
			cout << "\t\t-------------------" << endl;
			cin.ignore();
			for (int i = 0; i < gk; i++)
			{
				cout << "Sach thu " << i + 1 << endl;
				cout << "Nhap ma sach: ";
				getline(cin, maSach);
				cout << "Nhap ngay nhap: ";
				getline(cin, ngayNhap);
				cout << "Nhap don gia: ";
				cin >> donGia;
				cout << "Nhap so luong: ";
				cin >> soLuong;
				cin.ignore();
				cout << "Nhap nha xuat ban: ";
				getline(cin, nhaXuatBan);
				cout << "Nhap tinh trang: ";
				getline(cin, tinhTrang);
				mangSach.push_back(new SachGiaoKhoa(maSach, ngayNhap, donGia, soLuong, nhaXuatBan, tinhTrang));
				cout << endl;
			}
		}
		else if (chon == 2)
		{
			cout << "Nhap so sach tham khao: ";
			cin >> tk;
			cout << "\n\n\t\tNHAP SACH THAM KHAO" << endl;
			cout << "\t\t-------------------" << endl;
			
			for (int i = 0; i < tk; i++)
			{
				cout << "Sach thu " << i + 1 << endl;
				cin.ignore();
				cout << "Nhap ma sach: ";
				getline(cin, maSach);
				cout << "Nhap ngay nhap: ";
				getline(cin, ngayNhap);
				cout << "Nhap don gia: ";
				cin >> donGia;
				cout << "Nhap so luong: ";
				cin >> soLuong;
				cin.ignore();
				cout << "Nhap nha xuat ban: ";
				getline(cin, nhaXuatBan);
				cout << "Nhap thue: ";
				cin >> thue;
				mangSach.push_back(new SachThamKhao(maSach, ngayNhap, donGia, soLuong, nhaXuatBan, thue));
				cout << endl;
			}
		}
		else if (chon == 3)
		{
			break;
		}

	}

}



void xuat(vector<Sach*>& mangSach) {
	//cout << "\n\n\t\t *SACH GIAO KHOA* " << endl;
	long sumgk = 0;
	long sumtk = 0;
	cout << setw(51) << left << ' ' << setw(17) << left << "*SACH GIAO KHOA*" << setw(48) << left << " " << endl;
	cout << setw(15) << left << "MA SACH" << setw(20) << left << "NGAY NHAP" << setw(10) << right << "DON GIA" << setw(13) << right << "SO LUONG"<<"\t" << setw(25) << left << "NHA SAN XUAT"<<setw(15)<<left<<"TINH TRANG"<<setw(15)<<right<<"THANH TIEN" << endl;
	for (int i = 0; i < mangSach.size(); i++)
	{
		if (mangSach[i]->KT() == false) {
			mangSach[i]->inSach();
			cout << setw(15) << right << (long)(mangSach[i]->thanhTien()) << endl;
			sumgk = sumgk + (long)(mangSach[i]->thanhTien());
		}
	}
	cout << setfill('-') << setw(119) << "-" << endl;
	cout << setfill(' ');
	cout << setw(16) << left << "TONG THANH TIEN:" << setw(103) << right << sumgk << endl;
	cout << setfill('=') << setw(119) << "=" << endl;
	cout << setfill(' ');
	cout << setw(51) << left << ' ' << setw(17) << left << "*SACH THAM KHAO*" << setw(48) << left << " " << endl;
	cout << setw(15) << left << "MA SACH" << setw(20) << left << "NGAY NHAP" << setw(10) << right << "DON GIA" << setw(13) << right << "SO LUONG" << "\t" << setw(25) << left << "NHA SAN XUAT" << setw(15) << left << "THUE" << setw(15) << right << "THANH TIEN" << endl;
	for (int i = 0; i < mangSach.size(); i++)
	{
		if (mangSach[i]->KT() == true) {
			mangSach[i]->inSach();
			cout << setw(15) << right << (long)(mangSach[i]->thanhTien()) << endl;
			sumtk = sumtk + (long)(mangSach[i]->thanhTien());
		} 
	}
	cout << setfill('-') << setw(119) << "-" << endl;
	cout << setfill(' ');
	cout << setw(16) << left << "TONG THANH TIEN:" << setw(103) << right << sumtk << endl;
	cout << setfill('=') << setw(119) << "=" << endl;
	cout << setfill(' ');
}
void tinhTrungBinhDonGia(vector<Sach*>& mangSach) {
	float sum = 0;
	int dem = 0;
	long sumtk = 0;
	cout << setw(51) << left << ' ' << setw(17) << left << "*SACH THAM KHAO*" << setw(48) << left << " " << endl;
	cout << setw(15) << left << "MA SACH" << setw(20) << left << "NGAY NHAP" << setw(10) << right << "DON GIA" << setw(13) << right << "SO LUONG" << "\t" << setw(25) << left << "NHA SAN XUAT" << setw(15) << left << "THUE" << setw(15) << right << "THANH TIEN" << endl;
	for (int i = 0; i < mangSach.size(); i++)
	{
		if (mangSach[i]->KT() == true) {
			mangSach[i]->inSach();
			cout << setw(15) << right << (long)(mangSach[i]->thanhTien()) << endl;
			sumtk = sumtk + (long)(mangSach[i]->thanhTien());
			sum = sum + mangSach[i]->getDonGia();
			dem++;
		}
	}
	cout << setfill('-') << setw(119) << "-" << endl;
	cout << setfill(' ');
	cout << setw(16) << left << "TONG THANH TIEN:" << setw(103) << right << sumtk << endl;
	cout << setw(16) << left << "DON GIA TRUNG BINH:" << setw(100) << right << sum/dem << endl;
	cout << setfill('=') << setw(119) << "=" << endl;
	cout << setfill(' ');
}

void kiemTraNhaXuatBan(vector<Sach*>& mangSach) {
	string nxb;
	cin.ignore();
	cout << "\nnhap nha xuat ban can tim: " << endl;
	getline(cin, nxb);
	cout << nxb;
	cout << endl;
	cout << setw(51) << left << ' ' << setw(17) << left << "*SACH GIAO KHOA*" << setw(48) << left << " " << endl;
	cout << setw(15) << left << "MA SACH" << setw(20) << left << "NGAY NHAP" << setw(10) << right << "DON GIA" << setw(13) << right << "SO LUONG" << "\t" << setw(25) << left << "NHA SAN XUAT" << setw(15) << left << "TINH TRANG" << setw(15) << right << "THANH TIEN" << endl;
	for (int i = 0; i < mangSach.size(); i++)
	{
		if (mangSach[i]->ktNhaxb(nxb) == true) {
			mangSach[i]->inSach();
			cout << setw(15) << right << mangSach[i]->thanhTien() << endl;
			cout << endl;
		}
	}
	cout << setfill('-') << setw(119) << "-" << endl;
	cout << setfill(' ');
}
void tongThanhTien(vector<Sach*>& mangSach) {
	double sumgk = 0;
	double sumtk = 0;
	for (int i = 0; i < mangSach.size(); i++)
	{
		if (mangSach[i]->KT() == true) {
			sumtk = sumtk + mangSach[i]->thanhTien();
		}
		else
		{
			sumgk = sumgk + mangSach[i]->thanhTien();
		}
	}
	cout << "Tong Thanh Tien TK: " << sumtk << endl;
	cout << "Tong Thanh Tien GK: " << sumgk << endl;
}
void menu() {
	cout << "\t\t____________*MENU*_____________" << endl;
	cout << "1. Tinh tong thanh tien " << endl;
	cout << "2. Tinh trung binh don gia cua cac sach tham khao" << endl;
	cout << "3. Xuat cac sach giao khoa cua nha xuat ban K " << endl;

}

int main() {
	vector<Sach*> mangSach;
	int luaChon;
	int tieptuc = 1;
	do{
		cout << "------CHON CHUC NANG------" << endl;
		cout << "- 1. Nhap cung           -" << endl;
		cout << "- 2. Nhap mem            -" << endl;
		cout << "--------------------------" << endl;
		cout << "Chon: ";
		cin >> luaChon;
		if (luaChon == 1) {
			int ch;
			nhapCung(mangSach);
			menu();
			cout << "Chon: ";
			cin >> ch;
			switch (ch)
			{
			case 1:
				xuat(mangSach);
				cout << "1. Tiep tuc            2. Thoat" << endl;
				cout << "Chon: ";
				cin >> tieptuc;
				break;
			case 2:
				tinhTrungBinhDonGia(mangSach);
				cout << "1. Tiep tuc            2. Thoat" << endl;
				cout << "Chon: ";
				cin >> tieptuc;
				break;
			case 3:
				kiemTraNhaXuatBan(mangSach);
				cout << "1. Tiep tuc            2. Thoat" << endl;
				cout << "Chon: ";
				cin >> tieptuc;
				break;
			default:
				break;
			}
		}
		else if (luaChon == 2)
		{
			nhapMem(mangSach);
			int chn;
			menu();
			cout << "Chon: ";
			cin >> chn;
			switch (chn)
			{
			case 1:
				xuat(mangSach);
				cout << "1. Tiep tuc            2. Thoat" << endl;
				cout << "Chon: ";
				cin >> tieptuc;
				break;
			case 2:
				tinhTrungBinhDonGia(mangSach);
				cout << "1. Tiep tuc            2. Thoat" << endl;
				cout << "Chon: ";
				cin >> tieptuc;
				break;
			case 3:
				kiemTraNhaXuatBan(mangSach);
				cout << "1. Tiep tuc            2. Thoat" << endl;
				cout << "Chon: ";
				cin >> tieptuc;
				break;
			default:
				break;
			}
		}
	} while (tieptuc == 1);
	cout << "Chuong trinh ket thuc !!!" << endl;
}

