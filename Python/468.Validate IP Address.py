#判断给定的IP地址是否为有效的IPv4地址或者Ipv6地址。
class Solution(object):
    def validIPAddress(self, IP):
        if self.validIPV4(IP):
            return 'IPv4'
        if self.validIPV6(IP):
            return 'IPv6'
        return 'Neither'

    def validIPV4(self, IP):
        parts = IP.split('.')
        if len(parts) != 4: return False
        for part in parts:
            if not part: return False
            if not part.isdigit(): return False
            if part[0] == '0' and len(part) > 1: return False
            if int(part) > 255: return False
        return True

    def validIPV6(self, IP):
        parts = IP.split(':')
        if len(parts) != 8: return False
        for part in parts:
            if not part: return False
            if len(part) > 4: return False
            if any(c not in string.hexdigits for c in part): return False
        return True

s = Solution()
print(s.validIPAddress("2001:0db8:85a3:0000:0000:8a2e:0370:7334"))
