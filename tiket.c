#include <stdio.h>
#include <stdlib.h>

int hargaAncolWeekday = 30000; // Senin – Jumat
int hargaAncolWeekend = 35000; // Sabtu – Minggu

int hargaPaketKeluarga = 280000; // paket 5 orang
int hargaPaketPasangan = 55000;  // paket 2 orang

// fungsi untuk mapping nomor ke nama wahana
const char *getNamaWahana(int kode)
{
    switch (kode)
    {
    case 1:
        return "Ancol Only";
    case 2:
        return "Dufan";
    case 3:
        return "Atlantis";
    case 4:
        return "Samudra";
    case 5:
        return "Seaworld";
    default:
        return "Tidak Dikenal";
    }
}

// tampil daftar harga
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
    int hargaDasar = 0;

    int hari, tipe, kendaraan;
    int daftarWahana[10];
    int jumlahWahana = 0;
    char tambahan;

    tampilHarga();

    // input nama
    printf("\nMasukkan nama customer: ");
    fgets(nama, sizeof(nama), stdin);

    // menu utama
    printf("\n======== MENU UTAMA ========\n");
    printf("1. Pesan Tiket\n");
    printf("2. Lihat Pesanan\n");
    printf("3. Ubah Pesanan\n");
    printf("4. Hapus Pesanan\n");
    printf("Pilih menu (1-4): ");
    scanf("%d", &menu);

    if (menu == 1)
    {
        // pilih hari
        printf("\nPilih hari:\n");
        printf("1. Weekday\n");
        printf("2. Weekend\n");
        printf("Pilihan (1-2): ");
        scanf("%d", &hari);

        // pilih tipe tiket
        printf("\nPilih tipe tiket:\n");
        printf("1. Personal\n");
        printf("2. Couple\n");
        printf("3. Family\n");
        printf("Pilihan (1-3): ");
        scanf("%d", &tipe);

        do
        {
            printf("jumlah ticket: ");
            scanf("%d", &tipe);
        } while (tipe == 1);

        // ======== PILIH WAHANA BISA TAMBAH BERULANG ========
        do
        {
            printf("\nPilih wahana:\n");
            printf("1. Ancol Only\n");
            printf("2. Dufan\n");
            printf("3. Atlantis\n");
            printf("4. Samudra\n");
            printf("5. Seaworld\n");
            printf("Pilihan: ");
            scanf("%d", &daftarWahana[jumlahWahana]);
            jumlahWahana++;

            // buang newline sisa input
            getchar();

            printf("Tambah wahana lagi? (y/n): ");
            scanf("%c", &tambahan);

            // buang newline
            getchar();

        } while (tambahan == 'y');

        // pilih kendaraan
        printf("\nPilih kendaraan:\n");
        printf("1. Motor\n");
        printf("2. Mobil\n");
        printf("3. Tanpa kendaraan\n");
        printf("4. Bus\n");
        printf("Pilihan: ");
        scanf("%d", &kendaraan);

        // harga dasar dari wahana pertama (opsional)
        switch (daftarWahana[0])
        {
        case 1:
            hargaDasar = 250000;
            break;
        case 2:
            hargaDasar = 150000;
            break;
        case 3:
            hargaDasar = 200000;
            break;
        case 4:
            hargaDasar = 180000;
            break;
        case 5:
            hargaDasar = 160000;
            break;
        default:
            printf("Wahana tidak valid! Default Ancol Only.\n");
            hargaDasar = 250000;
            daftarWahana[0] = 1;
            break;
        }

        // =========== TAMPILKAN RINGKASAN PESANAN ===========
        printf("\n=== Pesanan Berhasil Dibuat ===\n");
        printf("Nama: %s", nama);

        printf("Wahana yang dipilih:\n");
        for (int i = 0; i < jumlahWahana; i++)
        {
            printf("  - %s\n", getNamaWahana(daftarWahana[i]));
        }
        int total = hargaDasar *

                    printf("\nTerima kasih telah memesan!\n");
    }

    // check out ticket

    return 0;
}
