void merge(int *a, int low, int mid, int high) //�鲢����  
{  
    int k, begin1, begin2, end1, end2;  
    begin1 = low;  
    end1 = mid;  
    begin2 = mid + 1;  
    end2 = high;  
    int *temp = (int *) malloc((high - low + 1) * sizeof(int));  
    for(k = 0; begin1 <= end1 && begin2 <= end2; k++) //��С��������  
    {  
        if(a[begin1] <= a[begin2])  
            temp[k] = a[begin1++];  
        else  
            temp[k] = a[begin2++];  
    }  
    if(begin1 <= end1) //��ʣ  
        memcpy(temp + k, a + begin1, (end1 - begin1 + 1) * sizeof(int));  
    else //��ʣ  
        memcpy(temp + k, a + begin2, (end2 - begin2 + 1) * sizeof(int));  
    memcpy(a + low, temp, (high - low + 1) * sizeof(int)); //������Ƶ�ԭ����  
    free(temp); //�ͷſռ�  
}  
void merge_sort(int *a, unsigned int begin, unsigned int end)  
{  
    int mid;  
    if(begin < end)  
    {  
        mid=begin+(end-begin)>>1;  
        //mid = (end + begin) / 2;  ��ֹ���ݼӷ����  
        merge_sort(a, begin, mid); //����  
        merge_sort(a, mid + 1, end); //����  
        merge(a, begin, mid, end);  //�ϲ����������������  
    }  
}  

