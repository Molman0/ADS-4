// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value){
 int count = 0;
 for (int i = 0; i < len; ++i){
  for (int j = i + 1; j < len; ++j){
   if (arr[i] + arr[j] == value){
    count++;
   }
  }
 }
 return count;
}
int countPairs3(int* arr, int len, int value){
 int count = 0;
 int left = 0;
 int right = len - 1;
 while (left < right){
  int sum = arr[left] + arr[right];
  if (sum > value){
   right--;
  }
  else if (sum < value){
   left++;
  }
  else{
   if (arr[left] == arr[right]){
    int n = right - left + 1;
    count += n * (n - 1) / 2;
    break;
   }
   int cur_left_val = arr[left];
   int cur_right_val = arr[right];
   int r_count = 0;
   int l_count = 0;
   while (left <= right && arr[left] == cur_left_val){
    l_count++;
    left++;
   }
   while (right >= left && arr[right] == cur_right_val){
    r_count++;
    right--;
   }
   count += r_count * l_count;
  }
 }
 return count;
}

int binSearch(int* arr, int low, int high, int value){
 int f = -1;
 int lb = low;
 int rb = high;
 while (lb <= rb){
  int mid = lb + (rb - lb) / 2;
  if (arr[mid] >= value){
   rb = mid - 1;
   if (arr[mid] == value){
    f = mid;
   }
  }
  else{
   lb = mid + 1;
  }
 }
 if (f == -1){
  return 0;
 }
 int last = f;
 lb = f;
 rb = high;
 while (lb <= rb){
  int mid = lb + (rb - lb) / 2;
  if (arr[mid] <= value){
   lb = mid + 1;
   if (arr[mid] == value){
    last = mid;
   }
  }
  else{
   rb = mid - 1;
  }
 }
 return last - f + 1;
}

int countPairs2(int* arr, int len, int value){
 int c = 0;
 for (int i = 0; i < len; i++){
  c += binSearch(arr, i + 1, len - 1, value - arr[i]);
 }
 return c;
}
