#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

const std::string INFILE = "201 RAW.txt";
const std::string OUTFILE= "201 ready.txt";
struct IpMac{
    std::string ip;
    std::string mac;
    int emptySymbol;

} ipmac{
    " ",
    " ",
    0
};
int countSpacesBetweenWords(const std::string& _str, const std::string& _ip, const std::string& _mac) {
    size_t pos1 = _str.find(_ip);
    size_t pos2 = _str.find(_mac, pos1 + _ip.length());
    if (pos1 == std::string::npos || pos2 == std::string::npos) {
        return -1; 
    }
    int spaceCount = 0;
    for (size_t i = pos1 + _ip.length(); i < pos2; ++i) {
        if (_str[i] == ' ') {
            spaceCount++;
        }
    }
    return spaceCount;
}
int main()
{
    std::ifstream in(INFILE);
    std::ofstream out(OUTFILE);
    std::string line;
    if(in.is_open())
    {
       while(std::getline(in, line))
       {
            if(!line.empty())
            {
                std::stringstream ss;
                ss << line;
                ss >> ipmac.ip >> ipmac.mac;
                ipmac.emptySymbol = countSpacesBetweenWords(line, ipmac.ip, ipmac.mac);
                if(out.is_open())
                {   
                    out << ipmac.mac << std::string(ipmac.emptySymbol, ' ') << ipmac.ip << std::endl;
                }
            }else{
                out << std::string(ipmac.ip.length() + ipmac.emptySymbol + ipmac.mac.length(), ' ') << std::endl;
            }

       }
       in.close();  
       out.close(); 
    }
    else if(in.fail() && out.fail())
    {
        std::cerr << "IN AND OUT FILE: fail open";
    }
    in.close();
    return 0;
}