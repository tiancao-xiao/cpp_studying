// base16.cpp 
/////////////////////////////////////////////////////////////////////////////
//// 第四章批量处理任务开始了
/////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include<string>
#include <vector>
using namespace std;



//编码表
static const string base16_enc_tab{"0123456789ABCDEF"};

int main()
{
	string teststr = "测试用于base16的字符串";
	cout << "ori:\t" << teststr << endl;
	string base16str; //base16编码后字符串
	for (unsigned char c : teststr)
	{
		//一个字节拆分为两个数字=>转为base16字符
		//0100 0001 >>4 = 0000 0100  =>4 =>'5'
		char h = c >> 4;
		//0100 0001 & 0000 1111 => 0000 0001 =>1 =>'1'
		char l = c &0b00001111;
		base16str += base16_enc_tab[h];
		base16str += base16_enc_tab[l];
	}
	cout << "Base16:\t" << base16str << endl;
	string ostr;// base16解码后数据


	//'A' = > 65  '0'=>48
	const vector<char> base16_dec_tab{
		-1,-1,-1,-1,-1 ,-1,-1,-1,-1,-1, //0~9
		-1,-1,-1,-1,-1 ,-1,-1,-1,-1,-1, //10~19
		-1,-1,-1,-1,-1 ,-1,-1,-1,-1,-1, //20~29
		-1,-1,-1,-1,-1 ,-1,-1,-1,-1,-1, //30~39
		-1,-1,-1,-1,-1 ,-1,-1,-1,       //40~47
		0,1,2,3,4,5,6,7,8,9,            //48~57
		-1,-1,-1,-1,-1, -1,-1,          //58~64
		10,11,12,13,14,15               //65~70
	};
	for (int i = 0; i < base16str.size(); i += 2)
	{
		//base16编码
		char ch = base16str[i]; 
		char cl = base16str[i + 1];

		//原数据二进制 'A' => 10
		unsigned char h = base16_dec_tab[ch];
		unsigned char l = base16_dec_tab[cl];
		//h 0100 << 4 = 0100 0000
		//l 0001 | 0100 0000 = 0100 0001

		ostr += (h << 4 | l);
	}
	cout << "Base16Decode:" << ostr << endl;


}
