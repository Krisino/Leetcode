class Solution {
    public int candy(int[] ratings) {
        int size = ratings.length;
        int candies[] = new int[size];
        for(int i = 0; i < size; i++) {
            candies[i] = 1;
            if(i > 0 && ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        for(int i = size - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i + 1]) {
                candies[i] = Math.max(candies[i], candies[i + 1] + 1);
            }
        }
        int result = 0;
        for(int i = 0; i < size; i++) {
            result += candies[i];
        }
        return result;
    }
}