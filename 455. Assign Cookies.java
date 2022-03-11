class Solution {
    public int findContentChildren(int[] g, int[] s) {
        int result = 0;
        Arrays.sort(g);
        Arrays.sort(s);
        int minPosOfG = 0;
        int minPosOfS = 0;
        while(minPosOfG < g.length && minPosOfS < s.length) {
            if(s[minPosOfS] >= g[minPosOfG]) {
                minPosOfG++;
                minPosOfS++;
                result++;
            } else {
                minPosOfS++;
            }
        }
        return result;
    }
}