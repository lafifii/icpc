const int N = 200;
int A[N][N];
void PascalTriangle(int n) 
{ 
    for (int line = 0; line < n; line++) 
    { 
        for (int i = 0; i <= line; i++) 
        { 
          if (line == i || i == 0) 
            A[line][i] = 1; 
          else
            A[line][i] = A[line - 1][i - 1] + A[line - 1][i]; 
        } 
    } 
}
