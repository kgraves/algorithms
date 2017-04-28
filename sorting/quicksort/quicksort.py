def partition(l, lo, hi):
    pivot = lo

    for i in xrange(lo+1, hi+1):
        if l[i] <= l[lo]:
            pivot += 1
            l[i], l[pivot] = l[pivot], l[i]

    l[lo], l[pivot] = l[pivot], l[lo]

    return pivot

def quicksort(l, lo, hi):
    if lo >= hi:
        return l

    p = partition(l, lo, hi)
    quicksort(l, lo, p - 1)
    quicksort(l, p+1, hi)

    return l

def insertion_sort(l):
    for i in xrange(1, len(l)):
        j = i

        while j > 0 and l[j-1] > l[j]:
            l[j-1], l[j] = l[j], l[j-1]
            j -= 1

    return l

if __name__ == '__main__':
    assert quicksort([1], 0, 0) == [1]
    assert quicksort([5,4,3,2,1], 0, 4) == [1,2,3,4,5]
    assert insertion_sort([5,2,3,1,4]) == [1,2,3,4,5]
