int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    //base cases
    if (trust == NULL){
        return -1;
    }
    else if (trustSize == 0 && n == 1){
        return n;
    }
    else if (trustSize == 0 && n!= 1){
        return -1;
    }
    
    //create arrays for storing the inDegree and outDegree of each person
    int* inDegree = (int*)malloc((n+1)*sizeof(int));
    int* outDegree = (int*)malloc((n+1)*sizeof(int));

    int i;
    //initialize inDegree and outDegree arrays to 0
    for (i = 0; i <= n; i++){
        inDegree[i] = 0;
        outDegree[i] = 0;
    }

    //populate the inDegree and outDegree arrays based on the relationships in the trust array
    for (i = 0; i < trustSize; i++){
        inDegree[trust[i][1]]++;
        outDegree[trust[i][0]]++;
    }

    //if there's a person who everyone trusts && trusts no one, return that person as the judge
    for (i = 1; i <= n; i++){
        if(inDegree[i] == n-1 && outDegree[i] == 0){
            free(inDegree);
            free(outDegree);
            return i;
        }
    }

    // release memory
    free(inDegree);
    free(outDegree);
    return -1;
    }   

