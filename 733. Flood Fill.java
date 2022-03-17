class Solution {
    void bfs(int[][] image, int sr, int sc,int oldColor, int newColor) {
        if(image[sr][sc] == newColor || image[sr][sc] != oldColor) {
            return;
        }
        image[sr][sc] = newColor;
        if(sr - 1 >= 0) {
            bfs(image, sr - 1, sc, oldColor, newColor);
        }
        if(sr + 1 < image.length) {
            bfs(image, sr + 1, sc, oldColor, newColor);
        }
        if(sc - 1 >= 0) {
            bfs(image, sr, sc - 1, oldColor, newColor);
        }
        if(sc + 1 < image[0].length) {
            bfs(image, sr, sc + 1, oldColor, newColor);
        }
    }

    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor) {
            return image;
        }
        bfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
}