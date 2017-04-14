template<class T>
// call this function to find the median of a vector of values of any kind of arithmetic type
T median(vector<T> v){
    typedef typename vector<T>::size_type vec_sz;
    
    vec_sz size = v.size();
    if (size == 0)
        throw domain_error("median of an empty vector");
        
    sort(v.begin(), v.end());
    
    vec_sz mid = size/2;
    
    return size % 2 == 0 ? (v[mid] + v[mid -1])/2:v[mid];
}

template<class R>
// call this function to find the median of a vector of values of any kind of arithmetic type
R median_by_iter(vector<R>::iterator beg, vector<R>::iterator end){
    typedef vector<R>::iterator iter
    bool is_there (end > beg);
    
    // this part might not work
    if (!is_there)
        throw domain_error("median of an empty vector");
        
        
    iter size = end- beg;
    
    sort(beg, end);
    
    iter mid = size/2;
    
    return size % 2 == 0 ? *((mid + (mid - 1))/2) : *mid;
}


//generic find function. supports input iterators
template<class In, class X>
In find(In begin, In end, const X& x){
    while (begin != end && *begin != x)
        ++begin;
    return begin;
}

// generic copy function. supports output iterators
template<class In, class Out>
Out copy(In begin, In end, Out dest){
    while (begin != end)
        *dest++ = *begin++;
    return dest;
}

// generic replace function. supports forward iterators
// This function examines the elements in the range [beg, end) and replaces every element that is equal to x by y
template<class For, class X>
void replace(For beg, For end, const X& x, const X& y){
    while (beg != end){
        if (*beg == x)
            *beg = y;
            ++beg;
    }
}

// generic reverse function. Supports bidirectional iterator
template<class Bi>
void reverse(Bi begin, Bi end){
    while (begin != end){
        --end;
        if (begin != end)
            swap(*begin++, *end);
    }
}

// generic binary_search function.  supports random-access iterators
template<class Rand, class X>
bool binary_search(Rand begin, Ran end, const X& x){
    while (begin < end){
        // find the midpoint of the range
        Ran mid = begin + (end - begin) / 2;
        // see which part of the range contains x; keep looking in that part
        if (x < *mid)
            end = mid;
        else if (* mid < x)
            begin = mid + 1;
        // if we got here then *mid == x so we're done
        else return true;
    }
    return false;
}


// generic split function that works on all types of containers
template <class Out>    // changed
void split(const string& str, Out os){
    
    typedef string::const_iterator iter;
    
    iter i = str.begin();
    while(i != str.end()){
        // ignore leading blanks
        i = find_if(i, str.end(), not_space);
        
        // find end of next word
        iter j = find_if(i, str.end(), space);
        
        // copy the characters in [i, j)
        if (i != str.end())
            *os++ = string(i, j); // changed
            
        i = j;
    }
}