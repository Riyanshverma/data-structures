void merge(int arr[], int low, int high){
    int i=low;
    int mid=(low+high)/2;
    int j=mid+1;
    int temp[high-1];
    int k=0;
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }
    while (i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=high){
        temp[k++]=arr[j++];
    }
    k=0;
    for(int i=low;i<=high;i++){
        arr[i]=temp[k++];
    }
    return;
}
void mergeSort(int arr[], int low, int high){
    if(low>=high){
        return ;
    }
    int mid=(low+high)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, high);
}