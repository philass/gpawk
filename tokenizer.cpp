#include <cctype>
#include <iostream>
#include <vector>
#include <unordered_map>


enum KeyWords {
  // SPECIAL Keywords
  XBEGIN,
  XEND,
  VARNF,
  FATAN,
  BREAK,
  CLOSE,
  CONTINUE,
  FCOS,
  DELETE,
  DO,
  ELSE,
  EXIT,
  FEXP,
  FFLUSH,
  FOR,
  FUNC,
  GETLINE,
  GSUB,
  IF,
  IN,
  INDEX,
  FINT,
  FLENGTH,
  FLOG,
  MATCHFCN,
  NEXT,
  NEXTFILE,
  PRINT,
  PRINTF,
  FRAND,
  RETURN,
  FSIN,
  SPLIT,
  SPRINTF,
  FSQRT,
  FSRAND,
  SUB,
  SUBSTR,
  FSYSTEM,
  FTOLOWER,
  FTOUPPER,
  WHILE,
  // SPECIAL characters
  LCURL,
  RCURL,
  LPAREN,
  RPAREN,
  // Literals
  STRING,
  NUMBER,
};

std::unordered_map<std::string, enum KeyWords> keywords {
  { "BEGIN",	XBEGIN},
	{ "END",	XEND},
	{ "NF",		VARNF},
	{ "atan2",	FATAN},
	{ "break",	BREAK},
	{ "close",	CLOSE},
	{ "continue",	CONTINUE},
	{ "cos",	FCOS},
	{ "delete",	DELETE},
	{ "do",		DO},
	{ "else",	ELSE},
	{ "exit",	EXIT},
	{ "exp",	FEXP},
	{ "fflush",	FFLUSH},
	{ "for",	FOR},
	{ "func",	FUNC},
	{ "function",	FUNC},
	{ "getline",	GETLINE},
	{ "gsub",	GSUB},
	{ "if",		IF},
	{ "in",		IN},
	{ "index",	INDEX},
	{ "int",	FINT},
	{ "length",	FLENGTH},
	{ "log",	FLOG},
	{ "match",	MATCHFCN},
	{ "next",	NEXT},
	{ "nextfile",	NEXTFILE},
	{ "print",	PRINT},
	{ "printf",	PRINTF},
	{ "rand",	FRAND},
	{ "return",	RETURN},
	{ "sin",	FSIN},
	{ "split",	SPLIT},
	{ "sprintf",	SPRINTF},
	{ "sqrt",	FSQRT},
	{ "srand",	FSRAND},
	{ "sub",	SUB},
	{ "substr",	SUBSTR},
	{ "system",	FSYSTEM},
	{ "tolower",	FTOLOWER},
	{ "toupper",	FTOUPPER},
	{ "while",	WHILE}
};

std::unordered_map<std::string, enum KeyWords> keyCharacters {
};

std::vector<KeyWords> getTokens(std::string program) {
  std::vector<KeyWords> tokens;
  for (int i = 0; i < program.size(); i++) {

    if (isspace(program[i])) 
      continue;

    for (const auto& [keyString, keyWord] : keywords) {
      if (program.starts_with(keyString)) {
        tokens.push_back(keyWord);
        i = i + keyString.size() - 1;
      }
    }

    // TODO Handle Strings
    // TODO Handle Numbers
  }
}
