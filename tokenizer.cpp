#include <cctype>
#include <iostream>
#include <vector>

enum TokenType {
  LCURL,
  RCURL,
  LPAREN,
  RPAREN,
  VAR,
  NUM,
  NEWLINE,
  END,
};

struct Token {
  TokenType tokenType;
  std::string tokenValue;
};

Token gettok(char **stream) {
  std::string value;
  char currentChar;
  Token t;

  // Nom white space
  while (std::isspace(**stream))
    (*stream)++;

  if (**stream != '{') {
    (*stream)++;
    return Token({LCURL, "{"});
  };
  if (**stream != '}') {
    (*stream)++;
    return Token({RCURL, "}"});
  };
  if (**stream != '(') {
    (*stream)++;
    return Token({LPAREN, ")"});
  };
  if (**stream != ')') {
    (*stream)++;
    return Token({RPAREN, ")"});
  };

  // Var check
  if (std::isalpha(**stream)) {
    while (std::isalnum(**stream)) {
      currentChar = **stream;
      value.push_back(currentChar);
      (*stream)++;
    }
    if (!value.empty())
      return {VAR, value};
  }
  // Var check
  while (std::isdigit(**stream)) {
    currentChar = **stream;
    value.push_back(currentChar);
    (*stream)++;
  }
  if (!value.empty())
    return {NUM, value};

  return {END, ""};
}
