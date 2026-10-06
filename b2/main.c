#include <stdio.h>

int main() {
    // ===== 1. DU LIEU DAU VAO: 4 benh nhan dang ky kham =====
    // Mang tuoi cua tung benh nhan (chi so 0..3 ung voi benh nhan 1..4)
    int tuoi_benh_nhan[4] = {75, 45, 150, 30};

    // Mang trang thai BHYT: 1 = Co BHYT, 0 = Khong co BHYT
    // Gia tri 2 tai vi tri index 3 la du lieu sai quy chuan (dung de test)
    int co_bao_hiem[4] = {1, 0, 1, 2};

    // Mang luu phi kham thuc te phai thu cua tung benh nhan (se duoc tinh ra)
    int phi_kham[4];

    // ===== 2. HANG SO NGHIEP VU =====
    const int PHI_GOC = 200000;      // Phi kham goc tieu chuan (VND)
    const double TY_LE_CON_LAI_BHYT = 0.20; // Co BHYT chi tra 20% gia goc

    // ===== 3. BIEN TONG HOP CA TRUC =====
    long tong_doanh_thu = 0;
    int so_ca_uu_tien = 0;

    printf("--- BAO CAO TIEP NHAN & XEP HANG KHAM BENH - MEDCARE CLINIC ---\n\n");

    // ===== 4. XU LY TUAN TU TUNG BENH NHAN (index 0 -> 3) =====
    for (int i = 0; i < 4; i++) {
        int tuoi = tuoi_benh_nhan[i];
        int bh = co_bao_hiem[i];

        printf("Benh nhan %d (Index %d):\n", i + 1, i);

        // --- Loi thuong gap 2: chuan hoa trang thai BHYT sai quy chuan ---
        // Chi chap nhan 0 hoac 1. Gia tri khac (VD: 2, -1) -> ep ve 0.
        if (bh != 0 && bh != 1) {
            printf("  [Canh bao] Trang thai BHYT khong hop le (%d) -> tu dong dieu chinh ve 0 (Khong BHYT)\n", bh);
            bh = 0;
            co_bao_hiem[i] = 0; // cap nhat lai du lieu goc trong mang
        }

        // --- Loi thuong gap 1: kiem tra do tuoi di biet ---
        if (tuoi <= 0 || tuoi > 120) {
            // Du lieu tuoi bat hop le: gan phi kham = 0, ghi nhan LOI DU LIEU
            phi_kham[i] = 0;
            printf("  Do tuoi: %d -> KHONG HOP LE\n", tuoi);
            printf("  Phi kham: %d VND\n", phi_kham[i]);
            printf("  Luong xu ly: LOI DU LIEU (khong tinh vao so ca uu tien)\n");
        } else {
            // Tinh phi kham theo chinh sach BHYT
            if (bh == 1) {
                phi_kham[i] = (int)(PHI_GOC * TY_LE_CON_LAI_BHYT); // 200000 * 20% = 40000
            } else {
                phi_kham[i] = PHI_GOC; // 200000
            }

            printf("  Do tuoi: %d\n", tuoi);
            printf("  BHYT: %s\n", (bh == 1) ? "Co" : "Khong");
            printf("  Phi kham: %d VND\n", phi_kham[i]);

            if (tuoi > 70) {
                printf("  Luong xu ly: UU TIEN\n");
                so_ca_uu_tien++;
            } else {
                printf("  Luong xu ly: THUONG\n");
            }
        }

        tong_doanh_thu += phi_kham[i];

        printf("\n");
    }

    printf("--- TONG HOP CA TRUC ---\n");
    printf("Tong doanh thu thu phi kham: %ld VND\n", tong_doanh_thu);
    printf("Tong so ca thuoc luong UU TIEN: %d\n", so_ca_uu_tien);

    return 0;
}