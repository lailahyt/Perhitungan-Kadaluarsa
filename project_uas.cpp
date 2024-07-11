#include <iostream>
#include <string>
#include <limits>
#include <ctime>
#include <conio.h>

struct Produk
{
    std::string nama_produk;
    int tanggal_beli, bulan_beli, tahun_beli;
    int tanggal_kadaluarsa, bulan_kadaluarsa, tahun_kadaluarsa;
};

void intro()
{
    system("cls");
    std::cout << "===================================" << std::endl;
    std::cout << "     Program Kadaluarsa Produk  " << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "Tekan Enter untuk melanjutkan..." << std::endl;
    std::cin.get();
}

void showMenu()
{
    system("cls");
    std::cout << "\n=== Menu ===" << std::endl;
    std::cout << "1. Biodata Kelompok" << std::endl;
    std::cout << "2. Menghitung Kadaluarsa" << std::endl;
    std::cout << "3. Keluar" << std::endl;
    std::cout << "Pilih opsi: ";
}

void biodataKelompok()
{
    system("cls");
    std::cout << "\n=== Biodata Kelompok ===" << std::endl;
    std::cout << "Nama Kelompok: Kelompok 3" << std::endl;
    std::cout << "Anggota: \n1. Laila Hayati\n2. Asyaika Zahrah\n3. Trindah Agustina \n4. Siti Amaliya" << std::endl;
    getch();
}

int hitungSelisihHari(int tgl1, int bln1, int thn1, int tgl2, int bln2, int thn2)
{
    std::tm tm_beli = {0, 0, 0, tgl1, bln1 - 1, thn1 - 1900};
    std::tm tm_kadaluarsa = {0, 0, 0, tgl2, bln2 - 1, thn2 - 1900};
    std::time_t time_beli = std::mktime(&tm_beli);
    std::time_t time_kadaluarsa = std::mktime(&tm_kadaluarsa);
    double difference = std::difftime(time_kadaluarsa, time_beli) / (60 * 60 * 24);
    return static_cast<int>(difference);
}

void menghitungKadaluarsa()
{
    system("cls");
    Produk produk;

    std::cout << "\n=== Menghitung Kadaluarsa ===" << std::endl;
    std::cin.ignore(); // Mengkonsumsi karakter newline yang tertinggal di buffer
    std::cout << "Apa Nama Produk Anda \t: ";
    std::getline(std::cin, produk.nama_produk);

    std::cout << "Kapan Anda Membeli " << produk.nama_produk << " (dd mm yyyy)\t: ";
    std::cin >> produk.tanggal_beli >> produk.bulan_beli >> produk.tahun_beli;

    std::cout << "Kapan Tanggal Kadaluarsa Produk " << produk.nama_produk << " (dd mm yyyy)\t: ";
    std::cin >> produk.tanggal_kadaluarsa >> produk.bulan_kadaluarsa >> produk.tahun_kadaluarsa;

    int sisa_hari = hitungSelisihHari(produk.tanggal_beli, produk.bulan_beli, produk.tahun_beli, produk.tanggal_kadaluarsa, produk.bulan_kadaluarsa, produk.tahun_kadaluarsa);

    std::cout << "\n=== Hasil Perhitungan ===" << std::endl;
    std::cout << "Produk\t\t: " << produk.nama_produk << std::endl;
    std::cout << "Sisa Hari\t: " << sisa_hari << " hari" << std::endl;
    if (sisa_hari > 0)
    {
        std::cout << "Status\t\t: Aman" << std::endl;
    }
    else
    {
        std::cout << "Status\t\t: Tidak Aman" << std::endl;
    }
    getch();
}
