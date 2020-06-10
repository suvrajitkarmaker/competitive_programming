int upperBound(int a[], int n, int x) {
    int l = 0, h = n, mid;
    while (l < h) {
        mid =  l + (h - l) / 2;
        if (x >= a[mid]) {
            l = mid + 1;
        } else {
            h = mid;
        }
    }
    return l;
}
