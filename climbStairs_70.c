/* recursive*/
/*
int climbStairs(int n){
    // f(n) = f(n-1) + f(n-2)
    // f(1) = 1 , f(2) = 2
    
    if (n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 2;
    }
    else return climbStairs(n-1) + climbStairs(n-2);
}
*/

/* circulation*/
/*
int climbStairs(int n){
    int a = 1, b = 2, c = 0;
    if (n == 1) return a;
    else if (n == 2) return b;
    else
        for (;n > 2;n--) {
            c = a + b;
            a = b;
            b = c;
        }
    return c;

}
*/

/*traversal algorithum
* each step have two choice
*/
/*
int climbStairs(int n){
    if (n == 0) {
        return 1;
    }
    else if (n < 0) {
        return 0;
    }
    else {
        return climbStairs(n-1)+climbStairs(n-2);
    }
}
*/

/* recursive + memo array*/

/*
struct memo_t{
    char exit;
    int value;
};
int climbStairs(int n){
    // f(n) = f(n-1) + f(n-2)
    // f(1) = 1 , f(2) = 2
    //struct memo_t memo[n];
    struct memo_t *memo = (struct memo_t *)malloc((n+1) * sizeof(struct memo_t));
    memset(memo, 0, (n+1)*sizeof(struct memo_t));
    if (n == 1) {
        memo[1].exit = 1;
        memo[1].value = 1;
        return 1;
    }
    if (n == 2) {
        memo[1].exit = 1;
        memo[1].value = 2;
        return 2;
    }

    if (memo[n].exit) return memo[n].value;
    else {
        memo[n].exit = 1;
        memo[n].value = climbStairs(n-1) + climbStairs(n-2);
        return memo[n].value;
    }
}

*/

/*
* DP
*/

int climbStairs(int n){
    int *dp = (int *)malloc((n+1)*sizeof(int));
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n + 1; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];    
}
