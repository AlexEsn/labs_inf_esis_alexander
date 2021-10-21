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
    int left = 0, right = base.GetLength() - 1;
    bool is_no_sorted = true;
    while (is_no_sorted) {

        is_no_sorted = false;

        for (int i = left; i < right; ++i) {
            if (comp(base[i + 1], base[i])) {
                swap(base[i], base[i + 1]);
                is_no_sorted = true;
            }
        }
        if (!is_no_sorted)
            break;

        is_no_sorted = false;

        --right;

        for (int i = right - 1; i >= left; --i) {
            if (comp(base[i + 1], base[i])) {
                swap(base[i], base[i + 1]);
                is_no_sorted = true;
            }
        }
        ++left;
    }
}

template<typename T>
void InsertionSort(Sequence<T> &base, bool (&comp)(T &left, T &right)) {
    for (int i = 1, j; i < base.GetLength(); i++) {
        T key = base[i];
        j = i - 1;
        while (j >= 0 && comp(key, base[j])) {
            base[j + 1] = base[j];
            j = j - 1;
        }
        base[j + 1] = key;
    }
}

template<typename T>
void SelectionSort(Sequence<T> &base, bool (&comp)(T &left, T &right)) {
    for (int i = 0; i < base.GetLength(); ++i) {
        size_t min = i;
        for (int j = i; j < base.GetLength(); ++j) {
            if (comp(base[j], base[min]))
                min = j;
        }
        swap(base[i], base[min]);
    }

}

template<typename T>
void QuickSort(Sequence<T> &base, bool (&comp)(T &left, T &right), int left, int right) {
    if (right <= 0)
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
    if (right <= 0)
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