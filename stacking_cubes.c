#include <stdio.h>
#include <stdlib.h>
int COUNT = 0;

void compare(int N, int a[N][N], int b[N][N])
{
    int c=0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(a[i][j]==b[i][j])
                c++;
        }
    }

    if(c==N*N)
        COUNT++;
}

void matrix_rotate_right(int N, int a[N][N])
{
    for (int i = 0; i < N / 2; i++)
    {
        for (int j = i; j < N - i - 1; j++)
        {
            int temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = temp;
        }
    }
}

void matrix_rotate_left(int n, int arr[n][n])
{
  for(int i=0;i<n/2;i++)
  {
      for(int j=i;j<n-i-1;j++)
      {
          int temp=arr[i][j];
          arr[i][j]=arr[j][n-i-1];
          arr[j][n-i-1]=arr[n-i-1][n-j-1];
          arr[n-i-1][n-j-1]=arr[n-j-1][i];
          arr[n-j-1][i]=temp;
      }
  }
}

void find_rotated_matrix(int N, int a[N], int b[N][N])
{
    int count=0;
    for(int i=0; i<N; i++)
    {
        count=0;
        for(int j=0; j<N; j++)
        {
            if(b[j][i]==1)
                count++;
        }
        a[i] = count;
    }
}

void display_matrix(int N, int a[N][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int t, n;
    int flag = 1, flag1 = 1;

    while(flag1==1)
    {
        printf("Enter the Test Cases: ");
        scanf("%d", &t);

        if(t>0)
        {
            flag1 = 0;
            while(t!=0)
            {
                while(flag==1)
                {
                    COUNT = 0;
                    printf("\nEnter the length: ");
                    scanf("%d", &n);
                    if(n>0&&n<=11)
                    {
                        int a[n][n];
                        for(int i=0; i<n; i++)
                        {
                            for(int j=0; j<n; j++)
                                a[i][j] = 0;
                        }
                        int j=0;
                        for(int i=0; i<n; i++)
                        {
                            j=0;
                            while (1)
                            {
                                scanf("%d", &a[i][j]);
                                if (a[i][j] == 0)
                                {
                                    break;
                                }
                                else
                                {
                                    j++;
                                }
                            }
                        }
                        int zero=0;
                        scanf("%d", &zero);

                        int l[n][n];

                        int result1[n][n], result2[n][n], temp[n], temp1[n];

                        for(int k=0; k<n; k++)
                        {
                            for(int i=0; i<n; i++)
                                for(int j=0; j<n; j++)
                                    l[i][j] = 0;

                            for(int j =0; j<n; j++)
                            {
                                int h = a[k][j];
                                for(int i = n-1; i>=0; i--)
                                {
                                    if(h!=0)
                                        l[i][j] = 1;

                                    else
                                        break;
                                    h--;
                                }

                            }

                            matrix_rotate_left(n, l);
                            find_rotated_matrix(n, temp, l);
                            for(int j=0; j<n; j++)
                            {
                                result1[k][j] = temp[j];
                            }
                        }

                        for(int k=0; k<n; k++)
                        {
                            for(int i=0; i<n; i++)
                                for(int j=0; j<n; j++)
                                    l[i][j] = 0;

                            for(int j =0; j<n; j++)
                            {
                                int h = a[j][k];
                                for(int i = n-1; i>=0; i--)
                                {
                                    if(h!=0)
                                        l[i][j] = 1;

                                    else
                                        break;
                                    h--;
                                }

                            }

                            matrix_rotate_right(n, l);
                            find_rotated_matrix(n, temp1, l);
                            for(int j=0; j<n; j++)
                            {
                                result2[k][j] = temp1[j];
                            }
                        }


                        matrix_rotate_left(n, result1);
                        printf("\n\n");

                        printf("The Left Rotated Matrix: \n");
                        for(int i=0; i<n; i++)
                        {
                            for(int j=0; j<n; j++)
                            {
                                if(result1[i][j]!=0)
                                    printf("%d ", result1[i][j]);
                            }
                            printf("\n");
                        }

                        printf("\n\n");
                        printf("The Right Rotated Matrix: \n");
                        for(int i=0; i<n; i++)
                        {
                            for(int j=0; j<n; j++)
                            {
                                if(result2[i][j]!=0)
                                    printf("%d ", result2[i][j]);
                            }
                            printf("\n");
                        }

                        compare(n, a, result1);
                        compare(n, a, result2);
                        printf("\nNumber of same stacks after rotation: %d", COUNT);
                        flag = 0;
                }
                    else
                        printf("Invalid Input! Enter again!");
            }


                t--;
            }
        }

        else
            printf("Invalid Input for Test-Cases!\n");
    }
    return 0;
}
