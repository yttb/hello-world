 void mian()/*˳�����*/
 {
  for(i=0;i<n;i++)
  {
  if(T[i]==x)
  printf("%d",i);
  else
  printf("j=0");
  }
 }
 void main()/*���ֲ���*/
 {
   int key,low,height;
   low=0;
   high=n-1;
   while(low<high) {
        key=(low+high)/2;
        if(a[key]==x) {
            return key;
        } else if(a[key]>x) {
            high=key-1;
        } else {
            low=key+1;
        }
    }
    return -1;
 }

