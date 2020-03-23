void merge(int *a, int low, int mid, int high) //归并操作  
{  
    int k, begin1, begin2, end1, end2;  
    begin1 = low;  
    end1 = mid;  
    begin2 = mid + 1;  
    end2 = high;  
    int *temp = (int *) malloc((high - low + 1) * sizeof(int));  
    for(k = 0; begin1 <= end1 && begin2 <= end2; k++) //自小到大排序  
    {  
        if(a[begin1] <= a[begin2])  
            temp[k] = a[begin1++];  
        else  
            temp[k] = a[begin2++];  
    }  
    if(begin1 <= end1) //左剩  
        memcpy(temp + k, a + begin1, (end1 - begin1 + 1) * sizeof(int));  
    else //右剩  
        memcpy(temp + k, a + begin2, (end2 - begin2 + 1) * sizeof(int));  
    memcpy(a + low, temp, (high - low + 1) * sizeof(int)); //排序后复制到原数组  
    free(temp); //释放空间  
}  
void merge_sort(int *a, unsigned int begin, unsigned int end)  
{  
    int mid;  
    if(begin < end)  
    {  
        mid=begin+(end-begin)>>1;  
        //mid = (end + begin) / 2;  防止数据加法溢出  
        merge_sort(a, begin, mid); //分治  
        merge_sort(a, mid + 1, end); //分治  
        merge(a, begin, mid, end);  //合并两个已排序的数列  
    }  
}  

