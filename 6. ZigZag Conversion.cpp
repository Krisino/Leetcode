class Solution {
public:
    	string convert(string s, int numRows) {
		if (numRows == 1) return s;

		int step = numRows * 2 - 2; // 间距
		int index = 0;// 记录s的下标
		int len = s.length();
		int add = 0; // 真实的间距
		string ret;
		for (int i = 0; i < numRows; i++) // i表示行号
		{
			index = i;
			add = i * 2;
			while (index < len)//超出字符串长度计算下一层
			{
				ret += s[index]; // 当前行的第一个字母
				add = step - add;// 第一次间距是step -2*i，第二次是2*i, 
				index += (i == 0 || i == numRows-1) ? step : add;
			}
		}
		return ret;
	}
};