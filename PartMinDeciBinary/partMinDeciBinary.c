int minPartitions(char * n){
    int result = 0;
    int length = strlen(n);
    int i;
    for (i=0;i<length;i++){
        if(n[i]>='0' && n[i]<='9'){
            int x = n[i] - '0';
            if (x>result){
                result = x;
            }
        }
    }
    return result;}
