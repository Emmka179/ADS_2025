PSEUDOCODE:
FUNCTION mergeSort(arr, left, right):
    IF left < right:
        mid = (left + right) / 2
        CALL mergeSort(arr, left, mid)
        CALL mergeSort(arr, mid+1, right)
        CALL merge(arr, left, mid, right)

FUNCTION merge(arr, left, mid, right):
    n1 = mid - left + 1
    n2 = right - mid
    
    CREATE leftArr of size n1
    CREATE rightArr of size n2
    
    FOR i FROM 0 TO n1-1:
        leftArr[i] = arr[left + i]
    FOR j FROM 0 TO n2-1:
        rightArr[j] = arr[mid + 1 + j]
    
    i = 0, j = 0, k = left
    
    WHILE i < n1 AND j < n2:
        IF leftArr[i] <= rightArr[j]:
            arr[k] = leftArr[i]
            i = i + 1
        ELSE:
            arr[k] = rightArr[j]
            j = j + 1
        k = k + 1
    
    WHILE i < n1:
        arr[k] = leftArr[i]
        i = i + 1
        k = k + 1
    
    WHILE j < n2:
        arr[k] = rightArr[j]
        j = j + 1
        k = k + 1