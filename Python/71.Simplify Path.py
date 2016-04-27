#简化一个Unix类系统的绝对路径
class Solution(object):
    def simplifyPath(self, path):
        s = path.split('/')
        stack = []
        for i in range(len(s)):
            if s[i]=='.':
                continue
            elif s[i]=='..':
                if stack!=[]:
                    stack.pop()
            elif s[i]!='':
                stack.append(s[i])
        return '/'+'/'.join(stack)

s = Solution()
print(s.simplifyPath("/.../.."))
print(s.simplifyPath("/home/"))
print(s.simplifyPath("/a/./b/../../c/"))