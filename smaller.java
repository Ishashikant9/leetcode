 class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] count = new int[102]; 
       
        for (int num : nums) {
            count[num]++;
        }

        
        for (int i = 1; i < count.length; i++) {
            count[i] += count[i - 1];
        }

        
        int[] result = new int[nums.length];
        for (int i = 0; i < result.length; i++) {
            result[i] = (nums[i] == 0) ? 0 : count[nums[i] - 1];
        }

        return result;
    }
}
