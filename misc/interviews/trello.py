import math

LETTERS = 'acdegilmnoprstuw'


def hash(s):
  """
  Hashes the given string `s`
  """
  h = 7
  for l in s:
    h = (h * 37 + LETTERS.find(l))
  return h


def calculate_string_from_hex(hex_value):
    """
    Calculates a string using each hex digit as an index into `LETTERS`.
    """
    # return [ LETTERS[ int(l, 16) ] for l in format(hex_value, 'x') ]
    s = ''
    for l in format(hex_value, 'x'):
        s += LETTERS[ int(l, 16) ]
    return s


def compute_hash(hex_value):
    """
    Calculates string from `hex_value` to calculate it's hash
    """
    s = calculate_string_from_hex(hex_value)
    print s
    return (hash(s), s)


def compute_curr(lo, hi):
    """
    computes the `current` value for a binary search
    """
    return int( math.ceil( (hi + lo * 1.0) / 2 ) )


def bin_search(max_value, target_hash, compute_fn):
    """
    performs a standard binary search between 0 and `max_value`. It uses
    `compute_fn` to check for a match.
    """
    lo = 0
    hi = max_value
    curr = compute_curr(lo, hi)

    while lo <= hi:
        val, strr = compute_fn(curr)

        # use `compute_fn` to compute guess
        if target_hash == val:
            return strr
        elif val < target_hash:
            # move limits up
            lo = curr + 1
            curr = compute_curr(lo, hi)
        elif val > target_hash:
            # move limits down
            hi = curr - 1
            curr = compute_curr(lo, hi)

    return None

# 0xFFFFFFFFF == 68719476735
print bin_search(0xFFFFFFFFF, 930846109532517, compute_hash)
