int lowerBound(vector<int>& a, int x) {
       
        int l = 0, h = a.size(), mid;
        while (l < h) {
            mid =  l + (h - l) / 2;
            if (x <= a[mid]) {
                h = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
        
    }
