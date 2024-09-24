class Solution {
public:
typedef struct{
    int m[2][2];
}matrix;

matrix mul(matrix a, matrix b)
{
    matrix c = {{
        {0,0},
        {0,0}
    }};
    for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
    for(int k = 0; k < 2; k++)
    c.m[i][j] += a.m[i][k] * b.m[k][j];

    return c;
}

matrix mpow(matrix a, int b)
{
    matrix I = {{
        {1, 0},
        {0, 1}
    }};
    if(b == 0) return I;

    matrix ans = mpow(a, b/2);
    ans = mul(ans, ans);
    if(b % 2 != 0)
    ans = mul(ans, a);

    return ans;
}


    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        int y = 1;
        int x = 1;

        matrix a = {{
            {1, 1},
            {1, 0}
        }};

        matrix p = mpow(a, n - 1);

        return p.m[0][0] + p.m[0][1];

        
    }
};