#两个数相乘的结果(输入为两个字符串类型的数，输出为字符串)，要求数可以任意长
class Solution(object):
    def multiply(self, num1, num2):
        if num1=='0' or num2=='0':
            return '0'

        nu1 ,nu2 = num1[::-1] , num2[::-1]
        tmp , result = [] , ''
        for i,ch2 in enumerate(nu2):
            flag , t = 0 , ''
            t += '0'*i
            for ch1 in nu1:
                s = int(ch1)*int(ch2)+flag
                flag = s//10
                t += str(s%10)
            if flag!=0:
                t+=str(flag)

            tmp.append(t)
        #print(tmp)
        flag , l , i = 0 , len(t) , 0
        while i<l or flag!=0:
            s = flag
            for ch in tmp:
                if i<len(ch):
                    s += int(ch[i])

            result += str(s%10)
            flag = s//10
            i += 1
        return result[::-1]

s = Solution()
print(s.multiply('576','120'))
