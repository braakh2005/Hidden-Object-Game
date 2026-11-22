# Complexity Analysis

Let:
- `N` = number of objects in the room array (10 in this game)
- `K` = number of required objects (5 in this game)
- `A` = maximum number of guesses (10)
- `L` = maximum string length considered by case-normalization/comparison

## Search cost
`linearSearch(arr, size, target)` checks elements sequentially and stops at the first match. In the worst case it checks all `size` elements. Because each comparison normalizes/compares strings, a more detailed character-cost bound is O(size × L); under the usual unit-cost string-comparison simplification, it is O(size).

The game performs a search in the room array. If the object exists, it performs another search in the required array. Thus, one guess costs at most O((N + K) × L), or O(N + K) under unit-cost comparisons.

## Cases
- Best case: the first room element matches; if it is a target, the first target element may also match. Search work is Θ(L) for the relevant comparisons (often written Θ(1) when string comparison is treated as constant).
- Average case: sequential scans inspect a proportional fraction of each searched array, so Θ((N + K) × L) under a typical successful/unsuccessful mixture; under unit-cost comparisons, Θ(N + K).
- Worst case: the room search scans all N items. If found in the room and is a target, the target search may scan all K items. Θ((N + K) × L); unit-cost comparison form Θ(N + K).

## Whole game
At most A guesses are processed, so worst-case total time is O(A × (N + K) × L). `displayRemaining` scans K flags on every loop iteration, adding O(A × K) work. Therefore the combined bound is O(A × (N + K) × L + A × K), simplified to O(A × (N + K) × L).

For the exact fixed game (N=10, K=5, A=10 and bounded object names), the total execution is bounded by a small constant: O(1) with respect to variable external input size.

## Space
The room array uses O(N) string slots, the required array O(K), and the Boolean found array O(K). The scalar variables use O(1). Total storage is O(N + K), excluding the implementation-dependent character storage for the strings. Auxiliary space beyond the arrays is O(1) apart from temporary string copies in `toLowerCase`, which can use O(L).

## Asymptotic notation
For the variable-size generalized search operation:
- Best case: Ω(1) element checks (or Ω(L) character work for a non-empty string comparison).
- Worst-case upper bound: O(N + K) element checks (or O((N+K)L) character work).
- Tight worst-case bound: Θ(N + K) element checks (or Θ((N+K)L) character work).
