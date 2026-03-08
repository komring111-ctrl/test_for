def twoSum(nums,target):
    num_dict={}
    for i,num in enumerate(nums):
        complement =target-num
        if complement in num_dict:
            return[num_dict[complement],i]
        num_dict[num]=i

    return []
print("===两数之和===")
print("请输入数组元素(用空格分隔,例如:2 7 11 15):")
user_input=input().strip()#去掉字符串首尾的空格和换行符
nums=list(map(int,user_input.split()))
print("请输入目标值target: ")
target=int(input())
result=twoSum(nums,target)
if result:
    i,j=result
    print(f"\n找到答案!")
    print(f"下标[{i},{j}],即nums[{i}]+nums[{j}]={nums[i]}+{nums[j]}={target}")
else:
    print(f"\n未找到和为{target}的两个数")