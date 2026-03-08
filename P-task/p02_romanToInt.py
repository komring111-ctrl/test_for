def romanToInt(s):
    roman_map={
        'I':1,
        'V':5,
        'X':10,
        'L':50,
        'C':100,
        'D':500,
        'M':1000
    }
    result=0
    n=len(s)
    for i in range(n):
        current=roman_map[s[i]]
        if i<n-1 and current<roman_map[s[i+1]]:
            result-=current
        else:
            result+=current
    return result
print("===罗马数字转整数===")
s=input("请输入罗马数字(如: III、IV、MXCMXCIV):").strip().upper()
print(f"\n{s}={romanToInt(s)}")

'''
input("...")   →  获取用户输入（字符串）
    .strip()   →  去掉首尾空格
    .upper()   →  全部转成大写
'''