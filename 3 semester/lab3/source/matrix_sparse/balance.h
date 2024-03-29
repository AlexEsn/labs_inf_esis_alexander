#pragma once
#include "pair.h"

template<typename T>
int height(node<T> *curr) {
    int h = 0;

    if (curr != NULL) {
        int l_height = height(curr->M_LEFT);
        int r_height = height(curr->M_RIGHT);
        int max_height = std::max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

template<typename T>
int diff(node<T> *curr) {
    int l_height = height(curr->M_LEFT);
    int r_height = height(curr->M_RIGHT);
    int b_factor = l_height - r_height;
    return b_factor;
}

template<typename T>
node<T> *ll_rotation(node<T> *curr) {
    node<T> *temp;
    temp = curr->M_LEFT;
    curr->M_LEFT = temp->M_RIGHT;
    temp->M_RIGHT = curr;
    return temp;
}

template<typename T>
node<T> *rr_rotation(node<T> *curr) {
    node<T> *temp;
    temp = curr->M_RIGHT;
    curr->M_RIGHT = temp->M_LEFT;
    temp->M_LEFT = curr;
    return temp;
}


template<typename T>
node<T> *lr_rotation(node<T> *curr) {
    node<T> *temp;
    temp = curr->M_LEFT;
    curr->M_LEFT = rr_rotation(temp);
    return ll_rotation(curr);
}


template<typename T>
node<T> *rl_rotation(node<T> *curr) {
    node<T> *temp;
    temp = curr->M_RIGHT;
    curr->M_RIGHT = ll_rotation(temp);
    return rr_rotation(curr);
}

template<typename T>
node<T> *balance(node<T> *temp) {
    int bal_factor = diff(temp);
    if (bal_factor > 1) {
        if (diff(temp->M_LEFT) > 0)
            temp = ll_rotation(temp);
        else
            temp = lr_rotation(temp);
    } else if (bal_factor < -1) {
        if (diff(temp->M_RIGHT) > 0)
            temp = rl_rotation(temp);
        else
            temp = rr_rotation(temp);
    }
    return temp;
}

