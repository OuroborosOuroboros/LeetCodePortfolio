void merge(int array[], int temp[], int l, int m, int r) {
	int i = l;
	int j = m+1;
	int k = l;
	//while we haven't reached the end of either sub array
	while ((i<=m) && (j<= r)){
		//compare and place the smallest element in temp at pos k
		//then increment k and j or k and i
		if (array[i] <= array[j]){
			temp[k]= array[i];
			k++;
			i++;}
		else{
			temp[k]= array[j];
			k++;
			j++;
		}
	}
	//next two while loops take care of the condition where one array has been fully iterated through but the other still has elements in it
	while (i<= m){
		temp[k] = array[i];
		k++;
		i++;
		}
	while (j<= r){
		temp[k] = array[j];
		k++;
		j++;
	}
	//this for loop copies the elements in the sorted 'temp' array' back into 'array'	
	for (i= l; i<= r; i++){
		array[i] = temp[i];
	}
}

void mergeSort(int array[], int temp [], int l, int r){
	if (r >l){
		int m =l+(r-l)/2;//adding l to r-1 prevents overflow
		mergeSort(array, temp, l, m);
		mergeSort(array, temp, m+1,r);
		merge(array, temp, l,m,r);
	}
}

void sortIntegers(int* array, unsigned int size){
	int temp [size];
	mergeSort(array,temp, 0 , size-1);	
}

int maxSatisfaction(int* satisfaction, int satisfactionSize) {
    if (satisfactionSize == 0){
        return 0;
    }

    sortIntegers(satisfaction, satisfactionSize);
    
    int totalSatisfaction = 0;
    int incrementalSatisfaction = 0;

    int i; 
    
    for (i= satisfactionSize-1; i >= 0; i--){
        incrementalSatisfaction += satisfaction[i];
        if(incrementalSatisfaction > 0){
            totalSatisfaction += incrementalSatisfaction;
        } else {
            break;
        }
    }

    return totalSatisfaction; 
    
}
