#include "analyzer.h"

LexicalAnalyzer::LexicalAnalyzer(std::ifstream& file) :source_file(file) {}

LexicalAnalyzer::~LexicalAnalyzer() {
    source_file.close();
}

void LexicalAnalyzer::run_analyzer() {
    read_in_starting_state();
}


bool  LexicalAnalyzer::char_is_character(const char& ch) const {
    if (std::find(this->letter.begin(), this->letter.end(), ch) != this->letter.end()) {
        std::cout << ch;
        
        return true;
    }
   
    return false;
}


bool LexicalAnalyzer::char_is_num(const char& ch) const {
    if (std::find(this->number.begin(), this->number.end(), ch) != this->number.end()) {
        return true;
    }

    return false;
}

void LexicalAnalyzer::error(std::string error_message) const {
    std::cerr << error_message << std::endl;
    this->~LexicalAnalyzer();
    exit(-1);
}



void LexicalAnalyzer::read_in_starting_state() {
    current_character = this->source_file.get();


    if (char_is_character(current_character))
        read_in_identifier();

    else if (char_is_num(current_character))
        read_in_number();

    else if (current_character == '{')
        read_in_comment();

    else if (current_character == '}')
        error("There was no opening '{'");

    else if (current_character == '(')
        read_in_found_opening_paranthesis();

    else if (current_character == '*')
        error("Unexpected '*'");

    else if (current_character == ')')
        error("Opening '(' missing");

    else if (current_character == ':')
        read_in_punct();

    else if (current_character == '=')
        error("Unexpected '='");

    else if (current_character == '<')
        read_in_less_then();

    else if (current_character == '>')
        read_in_bigger_then();

    else if (current_character == ' ')
        read_in_starting_state();

    else if (current_character == '$')
        read_in_end_of_program();

    else
        error("Char is forbidden here");

}


void LexicalAnalyzer::read_in_identifier() {
    current_character = source_file.get();
    
    if (char_is_character(current_character))
        read_in_identifier();

    else if (char_is_num(current_character))
        read_in_identifier();

    else if (current_character == '{')
        read_in_end_of_identifier();

    else if (current_character == '}')
        read_in_end_of_identifier();

    else if (current_character == '(')
        read_in_end_of_identifier();

    else if (current_character == '*')
        read_in_end_of_identifier();

    else if (current_character == ')')
        read_in_end_of_identifier();

    else if (current_character == ':')
        read_in_end_of_identifier();

    else if (current_character == '=')
        read_in_end_of_identifier();

    else if (current_character == '<')
        read_in_end_of_identifier();

    else if (current_character == '>')
        read_in_end_of_identifier();

    else if (current_character == ' ')
        read_in_end_of_identifier();

    else if (current_character == '$')
        read_in_end_of_identifier();

    else
        read_in_end_of_identifier();
}


void LexicalAnalyzer::read_in_end_of_identifier() {
    std::cout << " is an identifier" << std::endl;
    if (current_character==':')
    {
        read_in_punct();
    }
    if (!current_character=='{' || current_character=='}')
    {
       std::cout << std::endl; std::cout << current_character;
    }
    source_file.putback(current_character);
    
    read_in_starting_state();
}


void LexicalAnalyzer::read_in_number() {
    current_character = source_file.get();
    std::cout << current_character << std::endl;

    if (char_is_character(current_character))
        read_in_end_of_number();

    else if (char_is_num(current_character))
        read_in_number();

    else if (current_character == '{')
        read_in_end_of_number();

    else if (current_character == '}')
        read_in_end_of_number();

    else if (current_character == '(')
        read_in_end_of_number();

    else if (current_character == '*')
        read_in_end_of_number();

    else if (current_character == ')')
        read_in_end_of_number();

    else if (current_character == ':')
        read_in_end_of_number();

    else if (current_character == '=')
        read_in_end_of_number();

    else if (current_character == '<')
        read_in_end_of_number();

    else if (current_character == '>')
        read_in_end_of_number();

    else if (current_character == ' ')
        read_in_end_of_number();

    else if (current_character == '$')
        read_in_end_of_number();

    else
        read_in_end_of_number();
}

void LexicalAnalyzer::read_in_end_of_number() {
    source_file.putback(current_character);
    std::cout << current_character << std::endl;
    read_in_starting_state();
}

void LexicalAnalyzer::read_in_comment() {
    current_character = source_file.get();
    

    if (char_is_character(current_character))
        read_in_comment();

    else if (char_is_num(current_character))
        read_in_comment();

    else if (current_character == '{')
        read_in_comment();

    else if (current_character == '}')
        read_in_end_of_comment();

    else if (current_character == '(')
        read_in_comment();

    else if (current_character == '*')
        read_in_comment();

    else if (current_character == ')')
        read_in_comment();

    else if (current_character == ':')
        read_in_comment();

    else if (current_character == '=')
        read_in_comment();

    else if (current_character == '<')
        read_in_comment();

    else if (current_character == '>')
        read_in_comment();

    else if (current_character == ' ')
        read_in_comment();

    else if (current_character == '$')
        read_in_comment();

    else
        read_in_comment();
}


void LexicalAnalyzer::read_in_end_of_comment() {
    std::cout << " is a comment" << std::endl;
    read_in_starting_state();
}


void LexicalAnalyzer::read_in_found_opening_paranthesis() {
    current_character = source_file.get();

    if (char_is_character(current_character))
        read_in_correcting();

    else if (char_is_num(current_character))
        read_in_correcting();

    else if (current_character == '{')
        read_in_correcting();

    else if (current_character == '}')
        read_in_correcting();

    else if (current_character == '(')
        read_in_correcting();

    else if (current_character == '*')
        read_in_big_comment();

    else if (current_character == ')')
        read_in_correcting();

    else if (current_character == ':')
        read_in_correcting();

    else if (current_character == '=')
        read_in_correcting();

    else if (current_character == '<')
        read_in_correcting();

    else if (current_character == '>')
        read_in_correcting();

    else if (current_character == ' ')
        read_in_correcting();

    else if (current_character == '$')
        error("End of program is forbidden after '('");

    else
        read_in_correcting();
}

void LexicalAnalyzer::read_in_big_comment() {
    current_character = source_file.get();

    if (char_is_character(current_character))
        read_in_big_comment();

    else if (char_is_num(current_character))
        read_in_big_comment();

    else if (current_character == '{')
        read_in_big_comment();

    else if (current_character == '}')
        read_in_big_comment();

    else if (current_character == '(')
        read_in_big_comment();

    else if (current_character == '*')
        read_in_star_in_big_comment();

    else if (current_character == ')')
        read_in_big_comment();

    else if (current_character == ':')
        read_in_big_comment();

    else if (current_character == '=')
        read_in_big_comment();

    else if (current_character == '<')
        read_in_big_comment();

    else if (current_character == '>')
        read_in_big_comment();

    else if (current_character == ' ')
        read_in_big_comment();

    else if (current_character == '$')
        read_in_big_comment();

    else
        read_in_big_comment();
}

void LexicalAnalyzer::read_in_star_in_big_comment() {
    current_character = source_file.get();

    if (char_is_character(current_character))
        read_in_big_comment();

    else if (char_is_num(current_character))
        read_in_big_comment();

    else if (current_character == '{')
        read_in_big_comment();

    else if (current_character == '}')
        read_in_big_comment();

    else if (current_character == '(')
        read_in_big_comment();

    else if (current_character == '*')
        read_in_star_in_big_comment();

    else if (current_character == ')')
        read_in_end_of_big_comment();

    else if (current_character == ':')
        read_in_big_comment();

    else if (current_character == '=')
        read_in_big_comment();

    else if (current_character == '<')
        read_in_big_comment();

    else if (current_character == '>')
        read_in_big_comment();

    else if (current_character == ' ')
        read_in_big_comment();

    else if (current_character == '$')
        read_in_big_comment();

    else
        read_in_big_comment();
}


void LexicalAnalyzer::read_in_end_of_big_comment() {
    std::cout << " is a comment" << std::endl;
    read_in_starting_state();
}

void LexicalAnalyzer::read_in_punct() {
    std::cout << current_character;
    current_character = source_file.get();
    

    if (char_is_character(current_character))
        read_in_correcting();

    else if (char_is_num(current_character))
        read_in_correcting();

    else if (current_character == '{')
        read_in_correcting();

    else if (current_character == '}')
        read_in_correcting();

    else if (current_character == '(')
        read_in_correcting();

    else if (current_character == '*')
        read_in_correcting();

    else if (current_character == ')')
        read_in_correcting();

    else if (current_character == ':')
        read_in_correcting();

    else if (current_character == '=')
        read_in_punct_equality();

    else if (current_character == '<')
        read_in_correcting();

    else if (current_character == '>')
        read_in_correcting();

    else if (current_character == ' ')
        read_in_correcting();

    else if (current_character == '$')
        error("End of program is forbidden after ':'");

    else
        read_in_correcting();
}

void LexicalAnalyzer::read_in_punct_equality() {
    std::cout << current_character;
    std::cout << " is a token" << std::endl;
    read_in_starting_state();
}


void LexicalAnalyzer::read_in_less_then() {
    std::cout << current_character;
    current_character = source_file.get();
    std::cout << current_character;

    if (char_is_character(current_character))
        read_in_correcting();

    else if (char_is_num(current_character))
        read_in_correcting();

    else if (current_character == '{')
        read_in_correcting();

    else if (current_character == '}')
        read_in_correcting();

    else if (current_character == '(')
        read_in_correcting();

    else if (current_character == '*')
        read_in_correcting();

    else if (current_character == ')')
        read_in_correcting();

    else if (current_character == ':')
        read_in_correcting();

    else if (current_character == '=')
        read_in_less_then_or_equal();

    else if (current_character == '<')
        read_in_correcting();

    else if (current_character == '>')
        read_in_less_then_and_bigger_then();

    else if (current_character == ' ')
        read_in_correcting();

    else if (current_character == '$')
        error("End of program is forbidden after '<'");

    else
        read_in_correcting();
}

void LexicalAnalyzer::read_in_less_then_or_equal() {
    std::cout << " is a token" << std::endl;
    read_in_starting_state();
}

void LexicalAnalyzer::read_in_less_then_and_bigger_then() {
    std::cout << " is a token" << std::endl;
    read_in_starting_state();
}

void LexicalAnalyzer::read_in_bigger_then() {
    current_character = source_file.get();

    if (char_is_character(current_character))
        read_in_correcting();

    else if (char_is_num(current_character))
        read_in_correcting();

    else if (current_character == '{')
        read_in_correcting();

    else if (current_character == '}')
        read_in_correcting();

    else if (current_character == '(')
        read_in_correcting();

    else if (current_character == '*')
        read_in_correcting();

    else if (current_character == ')')
        read_in_correcting();

    else if (current_character == ':')
        read_in_correcting();

    else if (current_character == '=')
        read_in_bigger_then_or_equal();

    else if (current_character == '<')
        read_in_correcting();

    else if (current_character == '>')
        read_in_correcting();

    else if (current_character == ' ')
        read_in_correcting();

    else if (current_character == '$')
        error("End of program is forbidden after '>'");

    else
        read_in_correcting();
}


void LexicalAnalyzer::read_in_bigger_then_or_equal() {
    std::cout << " is a token" << std::endl;
    read_in_starting_state();
}


void LexicalAnalyzer::read_in_correcting() {
    source_file.putback(current_character);
    std::cout << std::endl;
    read_in_starting_state();
}


void LexicalAnalyzer::read_in_end_of_program() {
    std::cout << "The input has been analyzed successfully!" << std::endl;
}