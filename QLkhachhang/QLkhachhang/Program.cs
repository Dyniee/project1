using System;
using System.Collections.Generic;


class KhachHang
{
    public string MaKhachHang { get; set; }
    public string HoTen { get; set; }
    public string DiaChi { get; set; }
    public int SoLuong { get; set; } // Số KW tiêu thụ
    public double DonGia { get; set; }

    public virtual double TinhThanhTien()
    {
        return SoLuong * DonGia;
    }

    public virtual void NhapThongTin()
    {
        Console.Write("Ma khach hang: ");
        MaKhachHang = Console.ReadLine();
        Console.Write("Ho ten: ");
        HoTen = Console.ReadLine();
        Console.Write("Dia chi: ");
        DiaChi = Console.ReadLine();
        Console.Write("So luong KW tieu thu: ");
        SoLuong = int.Parse(Console.ReadLine());
        Console.Write("Don gia: ");
        DonGia = double.Parse(Console.ReadLine());
    }

    public virtual void XuatThongTin()
    {
        Console.WriteLine($"Ma khach hang: {MaKhachHang}");
        Console.WriteLine($"Ho ten: {HoTen}");
        Console.WriteLine($"Dia chi: {DiaChi}");
        Console.WriteLine($"So luong KW tieu thu: {SoLuong}");
        Console.WriteLine($"Don gia: {DonGia}");
    }
}
class KhachHangVietNam : KhachHang
{
    public string DoiTuongKhachHang { get; set; }
    public int DinhMuc { get; set; }

    public override void NhapThongTin()
    {
        base.NhapThongTin();
        Console.Write("Doi tuong khach hang (Sinh hoat/Kinh doanh/San xuat): ");
        DoiTuongKhachHang = Console.ReadLine();
        Console.Write("Dinh muc: ");
        DinhMuc = int.Parse(Console.ReadLine());
    }

    public override double TinhThanhTien()
    {
        if (SoLuong <= DinhMuc)
        {
            return SoLuong * DonGia;
        }
        else
        {
            return DinhMuc * DonGia + (SoLuong - DinhMuc) * DonGia * 2.5;
        }
    }

    public override void XuatThongTin()
    {
        base.XuatThongTin();
        Console.WriteLine($"Doi tuong khach hang: {DoiTuongKhachHang}");
        Console.WriteLine($"Dinh muc: {DinhMuc}");
        Console.WriteLine($"Thanh tien: {TinhThanhTien()}");
    }
}
class KhachHangNuocNgoai : KhachHang
{
    public string QuocTich { get; set; }

    public override void NhapThongTin()
    {
        base.NhapThongTin();
        Console.Write("Quoc tich: ");
        QuocTich = Console.ReadLine();
    }

    public override void XuatThongTin()
    {
        base.XuatThongTin();
        Console.WriteLine($"Quoc tich: {QuocTich}");
        Console.WriteLine($"Thanh tien: {TinhThanhTien()}");
    }
}
class QuanLyHoaDon
{
    public List<KhachHang> danhSachKhachHang = new List<KhachHang>();

    public void NhapDanhSach()
    {
        Console.Write("Nhap so luong khach hang: ");
        int n = int.Parse(Console.ReadLine());
        for (int i = 0; i < n; i++)
        {
            Console.WriteLine($"Nhap thong tin cho khach hang thu {i + 1}:");
            Console.Write("Loai khach hang (1 - Viet Nam, 2 - Nuoc Ngoai): ");
            int loai = int.Parse(Console.ReadLine());

            KhachHang kh;
            if (loai == 1)
            {
                kh = new KhachHangVietNam();
            }
            else
            {
                kh = new KhachHangNuocNgoai();
            }
            kh.NhapThongTin();
            danhSachKhachHang.Add(kh);
        }
    }

    public void XuatDanhSach()
    {
        foreach (var kh in danhSachKhachHang)
        {
            kh.XuatThongTin();
            Console.WriteLine("---------------------");
        }
    }

    public double TongSoLuongKWTieuThu(string loaiKhachHang)
    {
        double tong = 0;
        foreach (var kh in danhSachKhachHang)
        {
            if ((loaiKhachHang == "VietNam" && kh is KhachHangVietNam) ||
                (loaiKhachHang == "NuocNgoai" && kh is KhachHangNuocNgoai))
            {
                tong += kh.SoLuong;
            }
        }
        return tong;
    }

    public double TinhTrungBinhThanhTienKhachNuocNgoai()
    {
        double tongThanhTien = 0;
        int soLuongKhachNuocNgoai = 0;
        foreach (var kh in danhSachKhachHang)
        {
            if (kh is KhachHangNuocNgoai)
            {
                tongThanhTien += kh.TinhThanhTien();
                soLuongKhachNuocNgoai++;
            }
        }
        if (soLuongKhachNuocNgoai > 0)
            return tongThanhTien / soLuongKhachNuocNgoai;
        else
            return 0;
    }
}
class Program
{
    static void Main(string[] args)
    {
        QuanLyHoaDon quanLyHoaDon = new QuanLyHoaDon();

        quanLyHoaDon.NhapDanhSach();
        quanLyHoaDon.XuatDanhSach();

        double tongKWTieuThuVietNam = quanLyHoaDon.TongSoLuongKWTieuThu("VietNam");
        Console.WriteLine($"Tong so luong KW tieu thu cua khach hang Viet Nam: {tongKWTieuThuVietNam}");

        double tongKWTieuThuNuocNgoai = quanLyHoaDon.TongSoLuongKWTieuThu("NuocNgoai");
        Console.WriteLine($"Tong so luong KW tieu thu cua khach hang Nuoc Ngoai: {tongKWTieuThuNuocNgoai}");

        double trungBinhThanhTienNuocNgoai = quanLyHoaDon.TinhTrungBinhThanhTienKhachNuocNgoai();
        Console.WriteLine($"Trung binh thanh tien cua khach hang Nuoc Ngoai: {trungBinhThanhTienNuocNgoai}");
    }
}

//namespace QLkhachhang
//{
//    internal class Program
//    {
//        static void Main(string[] args)
//        {
//        }


//    }
//}
