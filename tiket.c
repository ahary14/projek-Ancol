#include <stdio.h>
#include <stdlib.h>

int hargaAncolWeekday = 30000;  // Senin – Jumat
int hargaAncolWeekend = 35000; // Sabtu – Minggu

int hargaPaketKeluarga = 280000; // paket 5 orang
int hargaPaketPasangan = 55000; // paket 2 orang

// harga awal
void tampilHarga()
{
  system("cls");
  printf("============== DAFTAR HARGA TIKET ANCOL ==============\n");
  printf("TIKET REGULER:\n");
  printf("  - Senin s/d Jumat  : %d\n", hargaAncolWeekday);
  printf("  - Sabtu & Minggu   : %d\n", hargaAncolWeekend);
  printf("\nPAKET HARGA:\n");
  printf("  - Paket Keluarga (5 org) : %d\n", hargaPaketKeluarga);
  printf("  - Paket Pasangan (2 org) : %d\n", hargaPaketPasangan);
  printf("=======================================================\n\n");
  printf("Tekan Enter untuk melanjutkan...");
  getchar();
}

  int main()
  {
    char nama[50];
    int menu;

    int hari, tipe, wahana, kendaraan;

    tampilHarga();

    printf("\nMasukkan nama customer: ");
    fgets(nama, sizeof(nama), stdin);

    // menu nya nih 
    printf("\n======== MENU UTAMA ========\n");
    printf("1. Pesan Tiket\n");
    printf("2. Lihat Pesanan\n");
    printf("3. Ubah pesanan\n");
    printf("4. Hapus pesanan \n");
    printf("pilih menu : ");
    scanf("%d", &menu);

    if(menu == 1)
    {
      printf("\nPilih hari: \n");
      printf("1. weekday\n");
      printf("2. weekend\n");
      printf("pilihan: ");
      scanf("%d", &hari);

      printf("\nPilih tipe tiket: \n");
      printf("1. personal\n");
      printf("2. couple\n");
      printf("3. family\n");
      printf("pilihan: ");
      scanf("%d", &tipe);

      printf("\nPilih wahana: \n");
      printf("1. ancol only\n");
      printf("2. dufan\n");
      printf("3. atlantis\n");
      printf("4. samudra\n");
      printf("5. seaworld\n");
      printf("pilihan: ");
      scanf("%d", &wahana);

      printf("\nPilih kendaraan: \n");
      printf("1. motor\n");
      printf("2. mobil\n");
      printf("3. tanpa kendaraan");
      printf("4. bus\n");
      printf("pilihan: ");
      scanf("%d", &kendaraan);

  
    }
    return 0;
  }