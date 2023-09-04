#include <bits/stdc++.h>
#include <climits>
#include <stdlib.h>
#include <chrono>
#include <thread>

#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>

using namespace std;

string floatBin(float f)
{
    string s = bitset<32>(*reinterpret_cast<unsigned long *>(&f)).to_string();
    return s.substr(0, 1) + " " + s.substr(1, 8) + " " + s.substr(9, 23);
};

string doubleBin(double f)
{
    string s = bitset<64>(*reinterpret_cast<unsigned long long *>(&f)).to_string();
    return s.substr(0, 1) + " " + s.substr(1, 11) + " " + s.substr(12, 52);
};

string longDoubleBin(long double f)
{
    string s = bitset<80>(*reinterpret_cast<unsigned long long *>(&f)).to_string();
    return s.substr(0, 1) + " " + s.substr(1, 15) + " " + s.substr(16, 64);
};

// std::string longDoubleBin(long double ld) {
//     unsigned char* it = reinterpret_cast<unsigned char*>(&ld);
//     std::string binaryString;
//     for (std::size_t i = 0; i < sizeof(ld); i++) {
//         binaryString += std::bitset<CHAR_BIT>(it[i]).to_string();
//     }
//     binaryString = binaryString.substr(0, 1) + " " + binaryString.substr(1, 15) + " " + binaryString.substr(16, 64);
//     return binaryString;
// }

void printBanner(){
    // Banner part
    cout << "Hello! Welcome to the Binary Converter\n\n";

    cout << R"(
 ________  ___  ________   ___       ________  ________        
|\   __  \|\  \|\   ___  \|\  \     |\   __  \|\   __  \       
\ \  \|\ /\ \  \ \  \\ \  \ \  \    \ \  \|\  \ \  \|\ /_      
 \ \   __  \ \  \ \  \\ \  \ \  \    \ \   __  \ \   __  \     
  \ \  \|\  \ \  \ \  \\ \  \ \  \____\ \  \ \  \ \  \|\  \    
   \ \_______\ \__\ \__\\ \__\ \_______\ \__\ \__\ \_______\   
    \|_______|\|__|\|__| \|__|\|_______|\|__|\|__|\|_______|   
                                                               
                                                               
)"
         << "\n\n";
}

void printInstructions(){
    cout << "Enter the datatype and the data to be converted \n";
    cout << "For space separated datatypes use a '-' between them. e.g long-long 76 \n";
    cout << "For help/h enter help\n";
    cout << "Enter clear to clear/cls the screen\n";
    cout << "Enter exit/quit/q to exit\n\n";
}

// take input a string then parse it to porper data type and then pass it to the function
void printBin()
{
    string s;
    bool trigger = true;
    while (trigger)
    {
        // s is a space separated string of 2 parts
        // 1st part is the datatype name
        // 2nd part is the data to be converted

        try
        {
            bool scan = true;
            while (scan)
            {
                getline(cin, s);
                if (cin.eof())
                    continue;
                else if (s == "exit")
                {
                    trigger = false;
                    break;
                }
                else if (cin.good())
                    scan = false;
                else
                    cout << "Invalid input\n";
            }

            // Function part
            if (s == "")
                continue;
            if (s == "exit" || s == "q" || s == "quit") // exit condition
                break;
            if (s == "help" || s == "h")
            {
                cout << "Enter the datatype and the data to be converted \n";
                cout << "Datatypes: \n";
                cout << "bool,\t";
                cout << "int,\t";
                cout << "float,\t";
                cout << "double,\t";
                cout << "char,\t";
                cout << "long,\t";
                cout << "long-long,\t";
                cout << "long-double,\t";
                cout << "unsigned-int,\t";
                cout << "unsigned-long,\t";
                cout << "unsigned-long-long,\t";
                cout << "short,\t";
                cout << "unsigned-short,\t";
                cout << "unsigned-char,\t";
                cout << "BIN,\t";
                cout << "OCT,\t";
                cout << "HEX\t";
                cout << endl << endl;

                // Instructions
                printInstructions();
                continue;
            }
            if(s == "clear" || s == "cls"){
                system("cls");
                printBanner();
                continue;
            }

            string datatype = s.substr(0, s.find(" "));
            transform(datatype.begin(), datatype.end(), datatype.begin(), ::tolower);
            string data = s.substr(s.find(" ") + 1);
            if (datatype == "bool")
            {
                bool d = stoi(data);
                cout << "data size: " << sizeof(bool) << endl;
                cout << "decimal: (" << d << ") bool: " << bitset<1>(d) << endl
                     << endl;
            }
            else

                if (datatype == "int")
            {
                int d = stoi(data);
                cout << "data size: " << 8 * sizeof(int) << endl;
                cout << "decimal: (" << d << ") int: " << bitset<8 * sizeof(int)>(d) << endl
                     << endl;
            }
            else if (datatype == "float")
            {
                float d = stof(data);
                cout << "data size: " << 8 * sizeof(float) << endl;
                cout << "decimal: (" << d << ") float: " << floatBin(d) << endl
                     << endl;
            }
            else if (datatype == "double")
            {
                double d = stod(data);
                cout << "data size: " << 8 * sizeof(double) << endl;
                cout << "decimal: (" << d << ") double: " << doubleBin(d) << endl
                     << endl;
            }
            else if (datatype == "char")
            {
                char d = data[0];
                cout << "data size: " << 8 * sizeof(char) << endl;
                cout << "decimal: (" << d << ") char: " << bitset<8 * sizeof(char)>(d) << endl
                     << endl;
            }
            else if (datatype == "long")
            {
                long d = stol(data);
                cout << "data size: " << 8 * sizeof(long) << endl;
                cout << "decimal: (" << d << ") long: " << bitset<8 * sizeof(long)>(d) << endl
                     << endl;
            }
            else if (datatype == "long-long" || datatype == "longlong" || datatype == "long_long" || datatype == "ll")
            {
                long long d = stoll(data);
                cout << "data size: " << 8 * sizeof(long long) << endl;
                cout << "decimal: (" << d << ") long long: " << bitset<8 * sizeof(long long)>(d) << endl
                     << endl;
            }
            else if (datatype == "long-double" || datatype == "longdouble" || datatype == "long_double" || datatype == "ld"){
                long double d = stold(data);
                cout << "data size: " << 8 * sizeof(long double) << endl;
                cout << "decimal: (" << d << ") long double: " << longDoubleBin(d) << endl
                     << endl;
            }
            else if (datatype == "unsigned-int")
            {
                unsigned int d = stoul(data);
                cout << "data size: " << 8 * sizeof(unsigned int) << endl;
                cout << "decimal: (" << d << ") unsigned int: " << bitset<8 * sizeof(unsigned int)>(d) << endl
                     << endl;
            }
            else if (datatype == "unsigned-long")
            {
                unsigned long d = stoul(data);
                cout << "data size: " << 8 * sizeof(unsigned long) << endl;
                cout << "decimal: (" << d << ") unsigned long: " << bitset<8 * sizeof(unsigned long)>(d) << endl
                     << endl;
            }
            else if (datatype == "unsigned-long-long")
            {
                unsigned long long d = stoull(data);
                cout << "data size: " << 8 * sizeof(unsigned long long) << endl;
                cout << "decimal: (" << d << ") unsigned long long: " << bitset<8 * sizeof(unsigned long long)>(d) << endl
                     << endl;
            }
            else if (datatype == "short")
            {
                short d = stoi(data);
                cout << "data size: " << 8 * sizeof(short) << endl;
                cout << "decimal: (" << d << ") short: " << bitset<sizeof(short)>(d) << endl
                     << endl;
            }
            else if (datatype == "unsigned-short")
            {
                unsigned short d = stoi(data);
                cout << "data size: " << 8 * sizeof(unsigned short) << endl;
                cout << "decimal: (" << d << ") unsigned short: " << bitset<8 * sizeof(unsigned short)>(d) << endl
                     << endl;
            }
            else if (datatype == "unsigned-char")
            {
                unsigned char d = data[0];
                cout << "data size: " << 8 * sizeof(unsigned char) << endl;
                cout << "decimal: (" << d << ") unsigned char: " << bitset<8 * sizeof(unsigned char)>(d) << endl
                     << endl;
            }
            else if (datatype == "bin" || datatype == "binary")
            {
                cout << "Decimal of " << data << " is " << stoull(data, 0, 2) << endl
                     << endl;
                // bitset<8 * sizeof(unsigned long)> bits(data); //to convert binary string to bitset
                // cout << "Decimal of " << data << " is " << bits.to_ulong() << endl
                //      << endl;
            }
            else if (datatype == "oct" || datatype == "octal")
            {
                cout << "Decimal of " << data << " is " << stoull(data, 0, 8) << endl
                     << endl;
            }
            else if (datatype == "hex" || datatype == "hexadecimal")
            {
                cout << "Decimal of " << data << " is " << stoull(data, 0, 16) << endl
                     << endl;
            }
            else
            {
                cout << "Invalid datatype\n\n";
            }
        }
        catch (const std::exception &e)
        {
            // std::cerr << e.what() << '\n';
            cout << "Invalid data \n\n";
        }
    }
}

int main()
{
    
    printBanner();
    // Instruction part
    printInstructions();
    try
    {
        printBin();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        cout << "Invalid input\n";
    }

    cout << "Exiting in 3 seconds\n";
    this_thread::sleep_for(chrono::seconds(3));
    return 0;
}
