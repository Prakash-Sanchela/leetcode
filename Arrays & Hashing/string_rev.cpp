void reverseString(vector<char>& vec, int start, int end){
    
    if (start >= end)
        return;

    swap(vec[start], vec[end]);
    
    reverseString(vec, start + 1, end - 1);
}
