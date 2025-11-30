#include <stdio.h>
#include <stdlib.h>

int hargaWeekday = 70000;  // Senin – Jumat
int hargaWeekend = 100000; // Sabtu – Minggu

int hargaPaketKeluarga = 320000; // paket 5 orang
int hargaPaketPasangan = 150000; // paket 2 orang

// VALIDASI INPUT
int inputAngka(char *pesan)
{
  int angka;
  char cek;

  while (1)
  {
    printf("%s", pesan);
    if (scanf("%d%c", &angka, &cek) != 2 || cek != '\n' || angka < 0)
    {
      printf("Input tidak valid! Masukkan angka positif.\n");
      while (getchar() != '\n')
        ;
    }
    else
    {
      return angka;
    }
  }
}

// MENAMPILKAN HARGA AWAL
void tampilHarga()
{
  system("cls");
  printf("============== DAFTAR HARGA TIKET ANCOL ==============\n");
  printf("TIKET REGULER:\n");
  printf("  - Senin s/d Jumat  : %d\n", hargaWeekday);
  printf("  - Sabtu & Minggu   : %d\n", hargaWeekend);
  printf("\nPAKET HARGA:\n");
  printf("  - Paket Keluarga (5 org) : %d\n", hargaPaketKeluarga);
  printf("  - Paket Pasangan (2 org) : %d\n", hargaPaketPasangan);
  printf("=======================================================\n\n");
  printf("Tekan Enter untuk melanjutkan...");
  getchar();
  getchar();
}

// CETAK FILE
void cetakKeFile(int reg, int hari, int pk, int ps, int total)
{
  FILE *f = fopen("struk_tiket_ancol.txt", "w");

  fprintf(f, "======= STRUK PEMBELIAN TIKET ANCOL =======\n");

  if (hari == 1)
    fprintf(f, "Tiket Reguler (Weekday) : %d x %d = %d\n", reg, hargaWeekday, reg * hargaWeekday);
  else
    fprintf(f, "Tiket Reguler (Weekend) : %d x %d = %d\n", reg, hargaWeekend, reg * hargaWeekend);

  if (pk > 0)
    fprintf(f, "Paket Keluarga          : %d x %d = %d\n", pk, hargaPaketKeluarga, pk * hargaPaketKeluarga);

  if (ps > 0)
    fprintf(f, "Paket Pasangan          : %d x %d = %d\n", ps, hargaPaketPasangan, ps * hargaPaketPasangan);

  fprintf(f, "---------------------------------------------\n");
  fprintf(f, "TOTAL BAYAR = %d\n", total);

  fclose(f);
  printf("\nStruk berhasil disimpan ke: struk_tiket_ancol.txt\n");
}

// PEMESANAN TIKET
void pesanTiket()
{
  system("cls");

  printf("=== PEMESANAN TIKET ANCOL ===\n\n");

  printf("Pilih hari kunjungan:\n");
  printf("1. Weekday (Senin - Jumat)\n");
  printf("2. Weekend (Sabtu - Minggu)\n");
  int hari = inputAngka("Masukkan pilihan (1/2): ");

  int hargaReg = (hari == 1) ? hargaWeekday : hargaWeekend;

  int reguler = inputAngka("Masukkan jumlah Tiket Reguler : ");

  int paketKeluarga = 0;
  int paketPasangan = 0;

  int tambahPaket = inputAngka("Apakah ingin membeli paket juga? (1=Ya / 0=Tidak): ");

  if (tambahPaket == 1)
  {
    paketKeluarga = inputAngka("Masukkan jumlah Paket Keluarga  : ");
    paketPasangan = inputAngka("Masukkan jumlah Paket Pasangan  : ");
  }

  // Hitung total
  int total = (reguler * hargaReg) +
              (paketKeluarga * hargaPaketKeluarga) +
              (paketPasangan * hargaPaketPasangan);

  system("cls");

  printf("======= STRUK PEMBELIAN =======\n");
  if (hari == 1)
    printf("Tiket Reguler (Weekday) : %d x %d = %d\n", reguler, hargaWeekday, reguler * hargaWeekday);
  else
    printf("Tiket Reguler (Weekend) : %d x %d = %d\n", reguler, hargaWeekend, reguler * hargaWeekend);

  if (paketKeluarga > 0)
    printf("Paket Keluarga          : %d x %d = %d\n", paketKeluarga, hargaPaketKeluarga, paketKeluarga * hargaPaketKeluarga);

  if (paketPasangan > 0)
    printf("Paket Pasangan          : %d x %d = %d\n", paketPasangan, hargaPaketPasangan, paketPasangan * hargaPaketPasangan);

  printf("---------------------------------\n");
  printf("TOTAL BAYAR = %d\n", total);

  cetakKeFile(reguler, hari, paketKeluarga, paketPasangan, total);

  printf("\nTekan Enter untuk kembali...");
  getchar();
  getchar();
}

// MENU UTAMA
int main()
{
  int pilihan;

  while (1)
  {
    tampilHarga();

    system("cls");
    printf("===== PROGRAM PEMESANAN TIKET ANCOL =====\n");
    printf("1. Pesan Tiket\n");
    printf("2. Lihat Daftar Harga\n");
    printf("3. Keluar\n");
    printf("=========================================\n");

    pilihan = inputAngka("Pilih menu: ");

    switch (pilihan)
    {
    case 1:
      pesanTiket();
      break;
    case 2:
      tampilHarga();
      break;
    case 3:
      printf("Terima kasih telah menggunakan Sistem Tiket Ancol!\n");
      return 0;
    default:
      printf("Pilihan tidak valid!\n");
      getchar();
    }
  }
}
