#看字符串中括号是否匹配
class Solution(object):
    def isValid(self, s):
        l =len(s)
        stack = []
        for ch in s:
            if ch in ['(','{','[']:
                stack.append(ch)
            elif ch in [')',']','}']:
                if len(stack)==0:
                    return False
                if ch==')' and stack[-1]=='(':
                    stack.pop()
                elif ch==']' and stack[-1]=='[':
                    stack.pop()
                elif ch=='}' and stack[-1]=='{':
                    stack.pop()
                else:
                    return False
            else:
                return False
        if len(stack)==0:
            return True
        else:
            return False


s = Solution()
print(s.isValid('{([()]())}'))
