class Codec:
    delimiter = "&"
    def encode(self, strs: List[str]) -> str:
        """Encodes a list of strings to a single string.
        """
        ans = ""
        for i in strs:
            while(self.delimiter in i):
                test = self.delimiter
                choice = random.choice(string.printable) 
                while(choice in i):
                    choice = random.choice(string.printable) 
                self.delimiter+= choice 
                test = self.delimiter

        for i in strs:
            ans+=i+self.delimiter
        return ans

    def decode(self, s: str) -> List[str]:
        """Decodes a single string to a list of strings.
        """
        ans = s.split(self.delimiter)
        ans= ans[:-1]#last character is an extra
        return ans
        


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(strs))