#给定两个整型数，一个代表分子numerator，一个代表分母denominator，
#以小数的形式返回它们的结果result，当有循环小数时，以括号形式表示。比如5/3=1.666666...以“1.(6)”的形式返回，返回的类型是字符串。
class Solution:
    def fractionToDecimal(self, numerator, denominator):
        n, remainder = divmod(abs(numerator), abs(denominator))
        sign = '-' if numerator*denominator < 0 else ''
        result = [sign+str(n), '.']
        stack = []
        while remainder not in stack:
            stack.append(remainder)
            n, remainder = divmod(remainder*10, abs(denominator))
            result.append(str(n))

        idx = stack.index(remainder)
        result.insert(idx+2, '(')
        result.append(')')
        return ''.join(result).replace('(0)', '').rstrip('.')

s = Solution()
print(s.fractionToDecimal(1,6))