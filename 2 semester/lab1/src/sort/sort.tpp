template<typename T>
void swap(T &left, T &right) {
    T temp = left;
    left = right;
    right = temp;
}

template<typename T>
void BubbleSort(Sequence<T> &base, bool (&comp)(T &left, T &right)) {
    for (int i = 0; i < base.GetLength(); ++i) {
        for (int j = 1; j < base.GetLength(); ++j) {
            if (!comp(base[j - 1], base[j])) swap(base[j - 1], base[j]);
        }
    }
}

template<typename T>
void ShakerSort(Sequence<T> &base, bool (&comp)(T &left, T &right)) {
    int left = 1, right = base.GetLength() - 1;
    while (left < right) {
        for (int i = right; i >= left; i--)
            if (comp(base[i], base[i - 1])) swap(base[i], base[i - 1]);
        left++;


        for (int i = left; i <= right; i++)
            if (comp(base[i], base[i - 1])) swap(base[i], base[i - 1]);
        right--;
    }
}

template<typename T>
void InsertionSort(Sequence<T> &base, bool (&comp)(T &left, T &right)) {
    for (int i = 1; i < base.GetLength(); ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (comp(base[i], base[j]) && (j == 0 || comp(base[j - 1], base[i]))) {
                T temp = base[i];
                for (int k = i; k > j; --k) {
                    swap(base[k], base[k - 1]);
                }
                base[j] = temp;
            }
        }
    }
}

template<typename T>
void SelectionSort(Sequence<T> &base, bool (&comp)(T &left, T &right)) {
    for (int i = 0; i < base.GetLength(); ++i) {
        T min = base[i];
        size_t min_index = i;
        for (int j = i; j < base.GetLength(); ++j) {
            if (comp(base[j], min)) {
                min = base[j];
                min_index = j;
            }
        }
        swap(base[i], base[min_index]);
    }

}

template<typename T>
void QuickSort(Sequence<T> &base, bool (&comp)(T &left, T &right), int left, int right) {
    if(right <= 0)
        return;
    int l_hold = left;
    int r_hold = right;
    T pivot = base[left];
    while (left < right) {
        while (!comp(base[right], pivot) && (left < right))
            right--;
        if (left != right) {
            base[left] = base[right];
            left++;
        }
        while (comp(base[left], pivot) && (left < right))
            left++;
        if (left != right) {
            base[right] = base[left];
            right--;
        }
    }
    base[left] = pivot;
    int temp = left;
    left = l_hold;
    right = r_hold;

    if (left < temp)
        QuickSort(base, comp, left, temp - 1);
    if (right > temp)
        QuickSort(base, comp, temp + 1, right);
}

template<typename T>
void MergeSort(Sequence<T> &base, bool (&comp)(T &left, T &right), int left, int right) {
    if(right <= 0)
        return;
    if (left == right) return;
    int median = (left + right) / 2;

    MergeSort(base, comp, left, median);
    MergeSort(base, comp, median + 1, right);
    int i = left;
    int j = median + 1;

    T *tmp = new T[right * sizeof(T)];

    for (int step = 0; step < right - left + 1; step++) {
        if ((j > right) || ((i <= median) && comp(base[i], base[j]))) {
            tmp[step] = base[i];
            i++;
        } else {
            tmp[step] = base[j];
            j++;
        }
    }

    for (int step = 0; step < right - left + 1; step++)
        base[left + step] = tmp[step];

    delete[] tmp;
}