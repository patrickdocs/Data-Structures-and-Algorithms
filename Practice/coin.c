#include <stdio.h>

int n;
int S;
int v[100];
int F[100];

int main()
{
    // Nhập số lượng đồng xu và giá trị tổng S
    scanf("%d", &n);
    scanf("%d", &S);

    // Nhập khối lượng của từng đồng xu
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &v[i]);
    }

    // Khởi tạo F[0] = 0, nghĩa là không cần đồng xu nào để đạt tổng 0
    F[0] = 0;

    // Đặt giá trị mặc định cho các giá trị F khác
    for (int i = 1; i <= S; i++)
    {
        F[i] = 10e6; // Một giá trị lớn để sau đó tìm giá trị nhỏ nhất
    }

    // Tính giá trị F[i] cho từng i từ 1 đến S
    for (int i = 1; i <= S; i++)
    {
        int existed = 0; // Đặt lại biến existed cho mỗi i
        for (int j = 1; j <= n; j++)
        {
            if (v[j] <= i && F[i - v[j]] != 10e6)
            {
                if (F[i - v[j]] + 1 < F[i])
                {
                    F[i] = F[i - v[j]] + 1;
                }
                existed = 1; // Có ít nhất một đồng xu có thể tạo ra tổng i
            }
        }

        // Nếu không có đồng xu nào có thể tạo ra tổng i, đặt F[i] = -1
        if (existed == 0)
        {
            F[i] = -1;
        }
    }

    // Nếu F[S] vẫn bằng -1 nghĩa là không có cách nào đạt tổng S
    if (F[S] == -1 || F[S] == 10e6)
    {
        printf("-1\n"); // Không thể tạo được tổng S
    }
    else
    {
        printf("%d\n", F[S]); // In ra số lượng đồng xu nhỏ nhất
    }

    return 0;
}
