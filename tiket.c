#include <stdio.h>
// tess
// Maksimal 50 pesanan
int hariList[50];
int bundlingList[50];
int jumlahList[50];
int wahanaList[50];
int kategoriList[50];
int kendaraanList[50];
int totalList[50];

int main() {
    char nama[100];
    int pilihan, metode, count = 0;

    printf("Masukkan nama pembeli: ");
    scanf(" %[^\n]", nama);

    while (1) {
        printf("\n======================================\n");
        printf("            MENU PEMESANAN\n");
        printf("======================================\n");
        printf("1. Tambah Pesanan (CREATE)\n");
        printf("2. Lihat Semua Pesanan (READ)\n");
        printf("3. Ubah Pesanan (UPDATE)\n");
        printf("4. Hapus Pesanan (DELETE)\n");
        printf("5. Checkout dan Bayar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        // =========================================
        // 1. CREATE
        // =========================================
        if (pilihan == 1) {
            int hari, bundling, jumlahTiket, wahana, kategori, kendaraan;
            int hargaDasar = 0;

            printf("\n--- Tambah Pesanan Baru ---\n");

            // Input Hari
            printf("Pilih Hari (1-7): ");
            scanf("%d", &hari);

            // Jenis Tiket
            printf("Jenis tiket: 1.Biasa 2.Couple 3.Family : ");
            scanf("%d", &bundling);

            if (bundling == 2) jumlahTiket = 2;
            else if (bundling == 3) {
                printf("Jumlah orang (>=4): ");
                scanf("%d", &jumlahTiket);
            } else {
                printf("Jumlah tiket: ");
                scanf("%d", &jumlahTiket);
            }

            // Wahana
            printf("Wahana: 1.Dufan 2.SeaWorld 3.Atlantis 4.Samudra : ");
            scanf("%d", &wahana);

            // Kategori
            printf("Kategori: 1.Pelajar 2.Dewasa 3.Anak : ");
            scanf("%d", &kategori);

            // Kendaraan
            printf("Kendaraan: 0.Tidak ada 1.Motor 2.Mobil : ");
            scanf("%d", &kendaraan);

            // Harga Dasar Wahana
            if (wahana == 1) hargaDasar = 250000;
            else if (wahana == 2) hargaDasar = 150000;
            else if (wahana == 3) hargaDasar = 200000;
            else hargaDasar = 180000;

            // Diskon kategori
            if (kategori == 1) hargaDasar -= 30000;
            if (kategori == 3) hargaDasar -= 20000;

            // Penyesuaian hari
            if (hari == 1) hargaDasar -= 20000;
            else if (hari == 5) hargaDasar += 15000;
            else if (hari == 6 || hari == 7) hargaDasar += 30000;

            // Diskon bundling
            if (bundling == 2) hargaDasar *= 0.85;
            if (bundling == 3) hargaDasar *= 0.75;

            // Harga kendaraan
            int hargaKendaraan = (kendaraan == 1 ? 25000 : kendaraan == 2 ? 50000 : 0);

            // Total per pesanan
            int total = (hargaDasar * jumlahTiket) + (jumlahTiket * 30000) + hargaKendaraan;

            // Simpan ke array
            hariList[count] = hari;
            bundlingList[count] = bundling;
            jumlahList[count] = jumlahTiket;
            wahanaList[count] = wahana;
            kategoriList[count] = kategori;
            kendaraanList[count] = kendaraan;
            totalList[count] = total;
            count++;

            printf("\nPesanan berhasil ditambahkan!\n");
        }

        // =========================================
        // 2. READ
        // =========================================
        else if (pilihan == 2) {
            printf("\n=============== DAFTAR PESANAN ===============\n");
            if (count == 0) printf("Belum ada pesanan.\n");
            for (int i = 0; i < count; i++) {
                printf("%d. Wahana %d | Tiket %d orang | Total: Rp %d\n",
                       i + 1, wahanaList[i], jumlahList[i], totalList[i]);
            }
        }

        // =========================================
        // 3. UPDATE
        // =========================================
        else if (pilihan == 3) {
            int idx;
            printf("Masukkan nomor pesanan yang ingin diubah: ");
            scanf("%d", &idx);
            idx--;

            if (idx < 0 || idx >= count) {
                printf("Nomor tidak valid!\n");
                continue;
            }

            printf("Pesanan %d sedang diubah...\n", idx + 1);

            printf("Masukkan jumlah tiket baru: ");
            scanf("%d", &jumlahList[idx]);

            printf("Jumlah tiket berhasil diperbarui!\n");
        }

        // =========================================
        // 4. DELETE
        // =========================================
        else if (pilihan == 4) {
            int idx;
            printf("Masukkan nomor pesanan yang ingin dihapus: ");
            scanf("%d", &idx);
            idx--;

            if (idx < 0 || idx >= count) {
                printf("Nomor tidak valid!\n");
                continue;
            }

            // Geser array ke kiri
            for (int i = idx; i < count - 1; i++) {
                hariList[i] = hariList[i + 1];
                bundlingList[i] = bundlingList[i + 1];
                jumlahList[i] = jumlahList[i + 1];
                wahanaList[i] = wahanaList[i + 1];
                kategoriList[i] = kategoriList[i + 1];
                kendaraanList[i] = kendaraanList[i + 1];
                totalList[i] = totalList[i + 1];
            }

            count--;
            printf("Pesanan berhasil dihapus!\n");
        }

        // =========================================
        // 5. CHECKOUT + SIMPAN STRUK
        // =========================================
        else if (pilihan == 5) {
            int totalAkhir = 0;
            for (int i = 0; i < count; i++) totalAkhir += totalList[i];

            printf("\n============================================\n");
            printf("                CHECKOUT\n");
            printf("============================================\n");
            printf("Nama   : %s\n", nama);
            printf("Total  : Rp %d\n", totalAkhir);

            printf("Pilih metode pembayaran:\n1. QRIS\n2. e-Wallet\n");
            scanf("%d", &metode);

            printf("\nPembayaran Berhasil. Terima Kasih!\n");

            // ========= SIMPAN STRUK KE FILE =========
            FILE *file = fopen("struk_pemesanan.txt", "w");

            if (file == NULL) {
                printf("Gagal membuat file struk!\n");
                return 0;
            }

            fprintf(file, "=========== STRUK PEMESANAN ==========\n");
            fprintf(file, "Nama Pembeli : %s\n", nama);
            fprintf(file, "---------------------------------------\n");

            for (int i = 0; i < count; i++) {
                fprintf(file,
                    "Pesanan %d:\n"
                    " - Wahana      : %d\n"
                    " - Bundling    : %d\n"
                    " - Jumlah      : %d orang\n"
                    " - Kategori    : %d\n"
                    " - Kendaraan   : %d\n"
                    " - Total       : Rp %d\n"
                    "---------------------------------------\n",
                    i + 1,
                    wahanaList[i],
                    bundlingList[i],
                    jumlahList[i],
                    kategoriList[i],
                    kendaraanList[i],
                    totalList[i]
                );
            }

            fprintf(file, "TOTAL AKHIR : Rp %d\n", totalAkhir);
            fprintf(file, "=======================================\n");
            fclose(file);

            printf("Struk berhasil disimpan ke file: struk_pemesanan.txt\n");

            break;
        }

        else {
            printf("Menu tidak valid!\n");
        }
    }

    return 0;
}
