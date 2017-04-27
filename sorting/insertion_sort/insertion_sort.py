def insertion_sort(l):
    for i in xrange(1, len(l)):
        j = i

        while j > 0 and l[j-1] > l[j]:
            l[j-1], l[j] = l[j], l[j-1]
            j -= 1

    return l

if __name__ == '__main__':
    assert insertion_sort([1,2,3]) == [1,2,3]
    assert insertion_sort([4,3,2,1]) == [1,2,3,4]
    assert insertion_sort([9,1,8,2,7,3,6,4,5]) == [1,2,3,4,5,6,7,8,9]
