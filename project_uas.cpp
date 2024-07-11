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
