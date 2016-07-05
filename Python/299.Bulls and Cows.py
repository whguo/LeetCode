#A代表两个字符串相同位置有相同的字符，B代表相同字符出现在不同位置
#"1807"和"7810"，返回1A3B。
#在不同位置只计数一次，"1123"和"0111"返回1A1B
class Solution(object):
    def getHint(self, secret, guess):
        l , A , B = len(secret) , 0 , 0
        se , gu = [0] * 10 , [0]*10
        for i in range(l):
            if secret[i] == guess[i]:   A+=1
            else:
                se[int(secret[i])] += 1
                gu[int(guess[i])] += 1
        for i in range(10):
            if gu[i]!=0 and se[i]!=0:   B+=min(gu[i],se[i])
        return str(A)+"A"+ str(B)+"B"

s = Solution()
print(s.getHint("1807","7810"))
print(s.getHint("1807","7888"))
print(s.getHint("1122","2211"))
