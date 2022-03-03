#include <iostream>
#include <string>
#include <map>

class Code
{
	public:
	    Code();
		std::string code_text(std::string);
	    std::string decode_text(std::string);

	private:
	    void set_map();
		std::map<char, char> mmap;
};


Code::Code()
{
    set_map();
}

std::string Code::code_text(std::string text)
{
    for(int i = 0; i < text.size(); ++i)
    {
       if((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        text[i] = mmap[text[i]];
    }
    
    return text;
    
}

void Code::set_map()
{
    for(char ch = 'a'; ch != 'd'; ++ch)
    {
        mmap.emplace(ch, ch + 23);
    }
    
    for(char ch = 'A'; ch != 'D'; ++ch)
    {
        mmap.emplace(ch, ch + 23);
    }
    
    
    for(char ch = 'd'; ch != 123; ++ch)
    {
        mmap.emplace(ch, ch - 3);
    }
    
    for(char ch = 'D'; ch != 123; ++ch)
    {
        mmap.emplace(ch, ch - 3);
    }
    
}

std::string Code::decode_text(std::string text)
{
    for(int i = 0; i < text.size(); ++i)
        {
            
        for(auto it = mmap.begin(); it != mmap.end(); ++it)
            {
                if(it -> second == text[i])
                    {
                        if((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
                            {
                                text[i] = it -> first;
                                break;
                            }
                            
                    }
            }
    }
    return text;
}


int main()
{
    Code code;
    std::string coded_text = code.code_text("THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG");
    std::cout << coded_text << std::endl;
    std::string decoded_text = code.decode_text(coded_text);
    std::cout << decoded_text;
}