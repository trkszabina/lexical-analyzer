#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>

#ifndef ANALYZER
#define ANALYZER

class LexicalAnalyzer {

    std::vector<char> stack;
    char current_character;

    std::ifstream& source_file;

    const std::vector<char> number = { '0','1','2','3','4','5','6','7','8','9' };

    const std::vector<char> letter = { 'a','b','c','d','e','f','g','h',
                            'i','j','k','l','m','n','o','p','q',
                            'r','s','t','u','v','w','x','y','z' };


    bool char_is_character(const char& ch) const;
    bool char_is_num(const char& ch) const;

    
    void read_in_starting_state();
    void read_in_identifier();
    void read_in_end_of_identifier();
    void read_in_number();
    void read_in_end_of_number();
    void read_in_comment();
    void read_in_end_of_comment();
    void read_in_found_opening_paranthesis();
    void read_in_big_comment();
    void read_in_star_in_big_comment();
    void read_in_end_of_big_comment();
    void read_in_punct();
    void read_in_punct_equality();
    void read_in_less_then();
    void read_in_less_then_or_equal();
    void read_in_less_then_and_bigger_then();
    void read_in_bigger_then();
    void read_in_bigger_then_or_equal();
    void read_in_end_of_program();
    void read_in_correcting();
    void error(std::string err_msg) const;




public:
    LexxicalAnalyzer(std::ifstream& file);
    ~LexicalAnalyzer();
    void run_analyzer();

};


#endif