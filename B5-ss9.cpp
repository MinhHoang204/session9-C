#include <stdio.h>
#include <stdbool.h>

// Ham kiem tra so nguyen to
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Ham hien thi menu
void displayMenu() {
    printf("\nMENU\n");
    printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
    printf("2. In ra gia tri cac phan tu dang quan ly\n");
    printf("3. In ra gia tri cac phan tu chan va tinh tong\n");
    printf("4. In ra gia tri lon nhat va nho nhat trong mang\n");
    printf("5. In ra cac phan tu la so nguyen to trong mang va tinh tong\n");
    printf("6. Nhap vao mot so va thong ke trong mang co bao nhieu phan tu do\n");
    printf("7. Them mot phan tu vao vi tri chi dinh\n");
    printf("8. Thoat\n");
    printf("Lua chon cua ban: ");
}

// Ham chinh
int main() {
    int arr[100], n = 0, choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // Nhap so phan tu va gia tri cac phan tu
                printf("Nhap so phan tu (toi da 100): ");
                scanf("%d", &n);
                if (n < 1 || n > 100) {
                    printf("So phan tu khong hop le.\n");
                    n = 0;
                } else {
                    for (int i = 0; i < n; i++) {
                        printf("Nhap phan tu thu %d: ", i);
                        scanf("%d", &arr[i]);
                    }
                    printf("Da nhap mang thanh cong.\n");
                }
                break;
            }
            case 2: {
                // In ra gia tri cac phan tu dang quan li
                if (n == 0) {
                    printf("Mang chua co phan tu nao.\n");
                } else {
                    printf("Cac phan tu trong mang: ");
                    for (int i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;
            }
            case 3: {
                // In ra gia tri cac phan tu chan va tinh tong
                if (n == 0) {
                    printf("Mang chua co phan tu nao.\n");
                } else {
                    int sum = 0;
                    printf("Cac phan tu chan: ");
                    for (int i = 0; i < n; i++) {
                        if (arr[i] % 2 == 0) {
                            printf("%d ", arr[i]);
                            sum += arr[i];
                        }
                    }
                    printf("\nTong cac phan tu chan: %d\n", sum);
                }
                break;
            }
            case 4: {
                // In ra gia tri lon nhat va nho nhat trong mang
                if (n == 0) {
                    printf("Mang chua co phan tu nao.\n");
                } else {
                    int max = arr[0], min = arr[0];
                    for (int i = 1; i < n; i++) {
                        if (arr[i] > max) max = arr[i];
                        if (arr[i] < min) min = arr[i];
                    }
                    printf("Gia tri lon nhat: %d\n", max);
                    printf("Gia tri nho nhat: %d\n", min);
                }
                break;
            }
            case 5: {
                // In ra cac phan tu la so nguyen to trong mang va tinh tong
                if (n == 0) {
                    printf("Mang chua co phan tu nao.\n");
                } else {
                    int sum = 0;
                    printf("Cac phan tu la so nguyen to: ");
                    for (int i = 0; i < n; i++) {
                        if (isPrime(arr[i])) {
                            printf("%d ", arr[i]);
                            sum += arr[i];
                        }
                    }
                    printf("\nTong cac so nguyen to: %d\n", sum);
                }
                break;
            }
            case 6: {
                // Nhap vao mot so va thong ke trong mang co bao nhieu phan tu do
                if (n == 0) {
                    printf("Mang chua co phan tu nao.\n");
                } else {
                    int x, count = 0;
                    printf("Nhap mot so: ");
                    scanf("%d", &x);
                    for (int i = 0; i < n; i++) {
                        if (arr[i] == x) count++;
                    }
                    printf("So phan tu bang %d trong mang: %d\n", x, count);
                }
                break;
            }
            case 7: {
                // Them mot phan tu vao vi tri chi dinh
                if (n >= 100) {
                    printf("Mang da day. Khong the them phan tu moi.\n");
                } else {
                    int value, position;
                    printf("Nhap gia tri can them: ");
                    scanf("%d", &value);
                    printf("Nhap vi tri can them (tu 0 den %d): ", n);
                    scanf("%d", &position);

                    if (position < 0 || position > n) {
                        printf("Vi tri khong hop le.\n");
                    } else {
                        for (int i = n; i > position; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[position] = value;
                        n++;
                        printf("Da them phan tu thanh cong.\n");
                    }
                }
                break;
            }
            case 8: {
                printf("Thoat chuong trinh.\n");
                break;
            }
            default: {
                printf("Lua chon khong hop le. Vui long chon lai.\n");
            }
        }
    } while (choice != 8);

    return 0;
}

