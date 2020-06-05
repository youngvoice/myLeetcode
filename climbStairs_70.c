/* recursive*/
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