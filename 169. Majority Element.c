void merge_sort(int *arr, int left, int right);
void merge(int *arr, int left_1, int right_1, int left_2, int right_2);

void print_arr(int *arr, int size);

int majorityElement(int* nums, int numsSize) {

    merge_sort(nums, 0, numsSize - 1);

    return nums[numsSize / 2];
}

void merge_sort(int *arr, int left, int right)  {
    if (left >= right) {
        return;
    }

    int mid = (left + right) / 2;

    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);

    merge(arr, left, mid, mid + 1, right); 
}

void merge(int *arr, int left_1, int right_1, int left_2, int right_2) {
    int merged_size = right_2 - left_1 + 1;
    int merged_start = left_1;
    
    // allocate auxiliary array for merging
    int merged[merged_size];
    
    // merge the halves, effectively sorting the subarray
    for (int i = 0; i < merged_size; i++) {
        if (left_1 > right_1) {
            merged[i] = arr[left_2++];
        }
        else if (left_2 > right_2) {
            merged[i] = arr[left_1++];
        }
        else {
            merged[i] = arr[left_1] < arr[left_2] ? arr[left_1++] : arr[left_2++];
        }
    }
    
    // copy merged values back into the original array
    for (int i = 0; i < merged_size; i++) {
        arr[merged_start++] = merged[i];
    }
}
