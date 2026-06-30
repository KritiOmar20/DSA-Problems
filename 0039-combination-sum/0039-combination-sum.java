class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        backtrack(0, candidates, target, new ArrayList<>(), res);
        return res;
    }

    void backtrack(int start, int[] arr, int target, List<Integer> curr, List<List<Integer>> res) {
        if (target == 0) {
            res.add(new ArrayList<>(curr));
            return;
        }
        for (int i = start; i < arr.length; i++) {
            if (arr[i] > target) continue;
            curr.add(arr[i]);
            backtrack(i, arr, target - arr[i], curr, res);
            curr.remove(curr.size() - 1);
        }
    }
}