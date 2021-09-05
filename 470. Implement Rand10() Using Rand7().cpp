// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        //防止生成的num为21
        while(true){
        //生成1-49等概率的数字
        int num = (rand7()-1)*7 + rand7();
        //1-40等概率出现，直接使用
        if(num <= 40){
            return num % 10 + 1;
        }
        //出现41-49的数字，相当于rand9(),使其生成7*9=63等概率数字
        num = (num - 40 -1)*7 + rand7();
        //1-60等概率出现，直接使用
        if(num <=60){
            return num%10 + 1;
        }
        //出现61-63的数字，相当于rand3(),使其生成7*3=21等概率数字
        num = (num - 60 - 1)*7 + rand7();
        //1-20等概率出现，直接使用
        if(num <= 20){
            return num%10 + 1;
        }
        }
    }
};