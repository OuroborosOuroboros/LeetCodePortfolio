#define MAX_FIB 31

int memo[MAX_FIB];

void initMemo(){
    int i;
    memo[0] = 0;
    memo[1] = 1;
    for (i=2; i< MAX_FIB; i++){
        memo[i] = -1;
    }
    return;
}

int fib(int n){
    initMemo();
    if(n >= 0){
        if(memo[n]!= -1){
            return memo[n];
        }
        else{
            if (memo[n-2] == -1) memo[n-2] = fib(n-2);
            if (memo[n-1] == -1) memo[n-1] = fib(n-1);
                memo[n] = memo[n-2]+memo[n-1];
                return memo[n];   
        }
    }
    else{
        return -1;
    }
}
