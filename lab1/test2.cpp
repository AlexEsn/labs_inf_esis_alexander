void sort(Array* array, int (*comp)(const void *left, const void *right)) {
    qsort(array->first_element, array->size, array->size_type, comp);
}