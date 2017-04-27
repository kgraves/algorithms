def bubble_sort(l):

    while True:
        curr = 0
        next = 1
        need_swap = False

        while next < len(l):
            if l[next] < l[curr]:
                l[curr], l[next] = l[next], l[curr] # swap elements
                need_swap = True
            
            curr, next = next, next+1

        # condition to break out
        if not need_swap:
            break

    return l

if __name__ == '__main__':
    assert bubble_sort([1,2,3]) == [1,2,3]
    assert bubble_sort([4,3,2,1]) == [1,2,3,4]
    assert bubble_sort([9,1,8,2,7,3,6,4,5]) == [1,2,3,4,5,6,7,8,9]
