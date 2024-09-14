#include<iostream>
#include<sstream>
#include<string>
#include<fstream>

const std::string INFILE = "201 RAW.txt";
const std::string OUTFILE = "201.dhcpd.txt";

struct Hosts{
    std::string ip;
    std::string mac;
    int count;
    void Print(){
        std::cout << "ip: " << ip << "      mac: " << mac << std::endl;
    }
}host{
    " ",
    " ",
    0
};

int main()
{
    std::ifstream in(INFILE);
    std::ofstream out(OUTFILE);
    std::string line;
    
    if(in.is_open())
    {
        while(std::getline(in, line))
        {
            std::stringstream ss;
            ss << line;
            ss >> host.ip >> host.mac;
            host.count += 1;
            if(out.is_open())
            {
                out << "host-" << host.count << std::endl;
                out << "{" << '\n' 
                    << '\t' << "hardware ethernet" << std::right << std::setw(25) << host.mac <<";\n" 
                    << '\t' << "fixed-address" << std::right << std::setw(26) << host.ip << ";" << '\n' 
                    << "}" << std::endl;
                out << std::endl;
            }
        }
        in.close();
        out.close();
    }else
    {
        std::cerr << "In Out File: can't open or file not found" << std::endl;
    }

    return 0;
}