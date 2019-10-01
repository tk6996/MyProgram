#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
void ex1(FILE *in)
{
    char *fdigits[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    char *tendigits[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    char *sdigits[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety", "One Hundred"};
    int n;
    fscanf(in, "%d", &n);
    if (n / 10 == 0)
        printf("%s", fdigits[n % 10]);
    else if (n / 10 == 1)
        printf("%s", tendigits[n % 10]);
    else
        printf("%s%c%s", sdigits[n / 10], (n % 10) ? '-' : '\0', (n % 10) ? fdigits[n % 10] : "");
}
void ex2(FILE *in)
{
    void printComma(int n)
    {
        if (n / 1000)
        {
            printComma(n / 1000);
            printf(",");
            printf("%03d", abs(n % 1000));
        }
        else
            printf("%d", n % 1000);
    };
    int n;
    fscanf(in, "%d", &n);
    printComma(n);
}
void ex3(FILE *in)
{
#define PI 3.141592f
    int n, m;
    fscanf(in, "%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        float a;
        fscanf(in, "%f", &a);
        printf("%f\n", a * 180 / PI);
    }
    for (int i = 0; i < m; i++)
    {
        float b;
        fscanf(in, "%f", &b);
        printf("%f\n", b / 180 * PI);
    }
#undef PI
}
void ex4(FILE *in)
{
    int a;
    float b;
    char c[11];
    fscanf(in, "%d %e %s", &a, &b, c);
    printf("%s %d %e", c, a, b);
}
void ex5(FILE *in)
{
    void printBinary(unsigned int n)
    {
        if (!n)
        {
            printf("0");
            return;
        }
        bool start = false;
        for (int i = 31; i >= 0; i--)
        {
            if (n >> i & 0b1)
            {
                if (!start)
                    start = true;
                printf("1");
            }
            else
            {
                if (start)
                    printf("0");
            }
        }
    };
    unsigned int num;
    fscanf(in, "%u", &num);
    printBinary(num);
    printf("\n%o\n%x", num, num);
}
void ex6(FILE *in)
{
#define castBase(c) (c <= '9') ? c - '0' : c - 'a' + 10
    const char *backcast = "0123456789abcdefghijklmnopqrstuvwxyz";
    int baseA, baseB;
    char bufBefore[11];
    char bufAfter[53];
    unsigned long long decimal = 0ULL;
    fscanf(in, "%d %s %d", &baseA, bufBefore, &baseB);
    if (baseA == baseB)
    {
        printf("%s", bufBefore);
        return;
    }
    int aLength = strlen(bufBefore) - 1;
    for (int i = aLength; i >= 0; --i)
        decimal += (castBase(bufBefore[i])) * (unsigned long long)pow(baseA, aLength - i);
    if (decimal == 0 || baseB == 10)
        printf("%llu", decimal);
    else
    {
        int row = 0;
        while (decimal)
        {
            bufAfter[row++] = backcast[decimal % baseB];
            decimal /= baseB;
        }
        for (int i = row - 1; i >= 0; --i)
            putchar(bufAfter[i]);
    }
#undef castBase
}
void ex7(FILE *in)
{
    int i;
    fscanf(in, "%d", &i);
    for (int j = 0, cal; j <= i; j++)
    {
        if (j == 0 || i == 0)
            cal = 1;
        else
            cal = cal * (i - j + 1) / j;
        printf("%d ", cal);
    }
    printf("\n");
}
void ex8(FILE *in)
{
    int b, e, m;
    fscanf(in, "%d %d %d", &b, &e, &m);
    int c = 1;
    for (int ep = 0; ep < e; ep++)
        printf("%d\n", (c = (c * b) % m));
}
void ex9(FILE *in)
{
    // Solving the Diophantine equation 1/x + 1/y = 1/n.
    int z;
    fscanf(in, "%d", &z);
    for (int i = 1; i <= z * z; ++i)
        if ((z * z) % i == 0)
            printf("%d %d\n", z + i, z + (z * z) / i);
}
void ex10(FILE *in)
{
    double a, b, c, discriminant;
    fscanf(in, "%lf %lf %lf", &a, &b, &c);
    discriminant = (b * b) - (4 * a * c);
    if (discriminant > 0)
    {
        printf("%lf\n%lf", (-b - sqrt(discriminant)) / (2 * a), (-b + sqrt(discriminant)) / (2 * a));
    }
    else if (discriminant == 0)
    {
        printf("%lf", (-b) / (2 * a));
    }
    else
    {
        printf("%lf+%lfi\n%lf-%lfi", (-b) / (2 * a), sqrt(-discriminant) / (2 * a), (-b) / (2 * a), sqrt(-discriminant) / (2 * a));
    }
}
void ex11(FILE *in)
{
    char meg[101];
    fgets(meg, 101, in);
    int start, end;
    if (meg[strlen(meg) - 1] == '\n')
        meg[strlen(meg) - 1] = '\0';
    meg[strlen(meg) - 1] = '\0';
    for (start = 1; start < strlen(meg); start++)
        if (meg[start] != ' ')
            break;
    for (end = strlen(meg); end > start; end--)
        if (meg[end - 1] != ' ')
            break;
    meg[end] = '\0';
    printf("\"%s\"", &meg[start]);
}
void ex12(FILE *in)
{
    char meg[1001];
    fgets(meg, 1000, in);
    for (int i = strlen(meg); i >= 0; i--)
        if (meg[i] != '\0' && meg[i] != '\n')
            putchar(meg[i]);
}
void ex13(FILE *in)
{
    bool checkPattern(char *st, char *word)
    {
        for (int i = 0; i < strlen(word); i++)
            if (st[i] != word[i])
                return false;
        return true;
    };
    char meg[1001];
    char word[11];
    int keep[1000];
    int size = 0;
    fgets(meg, 1000, in);
    fscanf(in, "%s", word);
    if (meg[strlen(meg) - 1] == '\n')
        meg[strlen(meg) - 1] = '\0';
    meg[strlen(meg) - 1] = '\0';
    for (int i = strlen(meg) - strlen(word); i > 0; i--)
    {
        if (checkPattern(&meg[i], word))
        {
            keep[size++] = i;
        }
    }
    if (size)
    {
        printf("%d", size);
        for (int i = size - 1; i >= 0; i--)
        {
            printf("\n%d", keep[i]);
        }
    }
    else
        printf("Not Found");
}
void ex14(FILE *in)
{
    char s[10001];
    fscanf(in, "%s", s);
    int p = 0, b = 0, c = 0, capacity = 16, size = 0;
    char *stack = malloc(capacity);
    for (int i = 0; i < strlen(s); i++)
    {
        if (strchr("([{", (int)s[i]))
        {
            if (size == capacity)
                stack = realloc(stack, capacity <<= 1);
            stack[size++] = s[i];
        }
        else
        {
            if (!size)
            {
                free(stack);
                printf("false");
                return;
            }
            switch (s[i])
            {
            case ')':
                if (stack[--size] != '(')
                {
                    free(stack);
                    printf("false");
                    return;
                }
                break;
            case ']':
                if (stack[--size] != '[')
                {
                    free(stack);
                    printf("false");
                    return;
                }
                break;
            case '}':
                if (stack[--size] != '{')
                {
                    free(stack);
                    printf("false");
                    return;
                }
                break;
            default:
                break;
            }
        }
    }
    free(stack);
    printf("%s", (size) ? "false" : "true");
    return;
}
void ex15(FILE *in)
{
    FILE *out = fopen("out.txt","w");
    char s[10001];
    fscanf(in, "%s", s);
    int sLength = strlen(s);
    for (int i = 0; i < 128; i++)
    {
        for (int j = 0; j < sLength; j++)
        {
            if (s[j] == (char)i)
                fputc(s[j],out);
        }
    }
    fclose(out);
}
void ex16(FILE *in)
{
    int n;
    fscanf(in, "%d%*c", &n);
    for (int i = 0; i < n; i++)
    {
        bool frist = true;
        char chr;
        while ((chr = fgetc(in)) >= 0)
        {
            if (chr == '\n')
                break;
            if (frist)
            {
                putchar((chr) >= 'a' && (chr) <= 'z' ? chr - 'a' + 'A' : chr);
                frist = false;
            }
            else
                putchar((chr) >= 'A' && (chr) <= 'Z' ? chr - 'A' + 'a' : chr);
        }
        putchar(' ');
    }
}
void ex17(FILE *in)
{
    /*struct TreeNode
    {
        struct TreeNode *lnext; 
        struct TreeNode *rnext;
        int data; 
    };
    typedef struct TreeNode* TreeNode;
    TreeNode addTree(TreeNode this,int data)
    {
        if(this)
        {
            if(data < this->data){
                this->lnext = addTree(this->lnext,data);
            }
            else if(data > this->data)
            {
                this->rnext = addTree(this->rnext,data);
            }
            return this;
        }
        else
        {
            TreeNode newT = calloc(1,sizeof(*newT));
            newT->data = data;
            return newT;
        }
    };
    void traversalTree(TreeNode this)
    {
        if(this == NULL) return;
        traversalTree(this->lnext);
        printf("%d ",this->data);
        traversalTree(this->rnext);
        free(this);
    };
    TreeNode tree = NULL;
    int num;
    fscanf(in,"%d",&num);
    while (num > -1)
    {
        tree = addTree(tree,num);
        fscanf(in,"%d",&num);
    }
    traversalTree(tree);*/
    int num;
    bool arr[1000001] = {[0 ... 1000000] = 0};
    fscanf(in, "%d", &num);
    while (num > -1)
    {
        arr[num] = true;
        fscanf(in, "%d", &num);
    }
    for (int i = 0; i < 1000000; i++)
    {
        if (arr[i])
            printf("%d ", i);
    }
}
void ex18(FILE *in)
{
    char bigNum1[101], sign[2], bigNum2[101], ans[102] = {[0 ... 101] = 0};
    fscanf(in, "%100s %1s %100s", bigNum1, sign, bigNum2);
    int row1 = strlen(bigNum1) - 1, row2 = strlen(bigNum2) - 1, rowa = 0;
    bool d = false;
    if (sign[0] == '+')
    {
        while (row1 > -1 || row2 > -1)
        {
            ans[rowa] = '0';
            if (row1 > -1)
                ans[rowa] += bigNum1[row1--] - '0';
            if (row2 > -1)
                ans[rowa] += bigNum2[row2--] - '0';
            if (d)
                ans[rowa] += 1;
            if (ans[rowa] > '9')
            {
                ans[rowa] -= 10;
                d = true;
            }
            else
                d = false;
            rowa++;
        }
        if (d)
            ans[rowa] = '1';
    }
    else if (sign[0] == '-')
    {
        //////////////
        bool lower = row1 < row2;
        if (row1 == row2)
            lower = strcmp(bigNum1, bigNum2) <= -1;
        if (lower)
        {
            char temp[101];
            strcpy(temp, bigNum1);
            strcpy(bigNum1, bigNum2);
            strcpy(bigNum2, temp);
            row1 = strlen(bigNum1) - 1;
            row2 = strlen(bigNum2) - 1;
        }
        /////////////
        while (row1 > -1 || row2 > -1)
        {
            ans[rowa] = '0';
            if (row1 > -1)
                ans[rowa] += bigNum1[row1--] - '0';
            if (row2 > -1)
                ans[rowa] -= bigNum2[row2--] - '0';
            if (d)
                ans[rowa] -= 1;
            if (ans[rowa] < '0')
            {
                ans[rowa] += 10;
                d = true;
            }
            else
                d = false;
            rowa++;
        }
        if (lower)
            ans[rowa] = '-';
    }
    bool pass = false;
    for (int i = strlen(ans) - 1; i > 0; --i)
    {
        if (pass || ans[i] == '-' || ((ans[i] >= '1' && ans[i] <= '9') ? pass = true : false))
            putchar(ans[i]);
    }
    putchar(ans[0]);
}
void ex19(FILE *in)
{
    struct Box
    {
        double cenx;
        double ceny;
        double width;
        double height;
    } a, b;
    fscanf(in, "%lf %lf", &(a.width), &(a.height));
    fscanf(in, "%lf %lf", &(b.width), &(b.height));
    fscanf(in, "%lf %lf", &(a.cenx), &(a.ceny));
    fscanf(in, "%lf %lf", &(b.cenx), &(b.ceny));
    double minX_A = a.cenx - a.width / 2;
    double maxX_A = a.cenx + a.width / 2;
    double minX_B = b.cenx - b.width / 2;
    double maxX_B = b.cenx + b.width / 2;
    double minY_A = a.ceny - a.height / 2;
    double maxY_A = a.ceny + a.height / 2;
    double minY_B = b.ceny - b.height / 2;
    double maxY_B = b.ceny + b.height / 2;
    if (minX_B <= maxX_A && minX_A <= maxX_B && minY_B <= maxY_A && minY_A <= maxY_B)
        printf("Collision");
    else
        printf("Not Collision");
}
void ex20(FILE *in)
{
    int determinant(int *mat, int n)
    {
        if (n == 1)
            return *mat;
        else
        {
            int det = 0;
            int *sub_mat = malloc(sizeof(int) * (n - 1) * (n - 1));
            for (int i = 0; i < n; i++)
            {
                int *ptr = sub_mat;
                for (int j = n; j < n * n; j++)
                {
                    if (j % n == i)
                        continue;
                    (*ptr++) = mat[j];
                }
                det += ((i % 2) ? -1 : 1) * (determinant(sub_mat, n - 1)) * mat[i];
            }
            free(sub_mat);
            return det;
        }
    };
    int n, *matrix;
    fscanf(in, "%d", &n);
    matrix = malloc(sizeof(int) * n * n);
    for (int i = 0; i < n * n; i++)
        fscanf(in, "%d", matrix + i);
    printf("%d", determinant(matrix, n));
    free(matrix);
}
#define Gen false
#define TEST 1
#if (!Gen)
int main(void)
{
    FILE *in = fopen("in.txt", "r");
    for (size_t i = 0; i < TEST; i++)
    {
        ex20(in);
        printf("\n\n\n");
    }
    fclose(in);
    return 0;
}
#endif
#if (Gen)
int main(void)
{
    FILE *in = fopen("in.txt", "w");
    srand(time(NULL));
    for (size_t i = 0; i < 10000; i++)
    {
        fputc(33+(rand()%(126-33)),in);    
    }
    fclose(in);
    return 0;
}
#endif