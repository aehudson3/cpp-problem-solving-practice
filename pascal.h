#ifndef PRACTICE_PASCAL_H
#define PRACTICE_PASCAL_H

#include <queue>
#include <string>
#include <vector>

using std::queue;
using std::string;
using std::vector;


size_t calc_center(size_t size) {
  return size / 2;
}

using std::to_string;

string to_string(queue<size_t>& q) {
  string str{};
  for (size_t i{}; i < q.size(); ++i) {
    str += std::to_string(q.front());
    if (i < (q.size() - 1)) {
      str += " ";
    }
    q.pop();
  }
  return str;
}

string insert_centering_whitespace(size_t size) {
  string text{};
  for (size_t i{}; i < calc_center(size); ++i) { text += " "; }
  return text;
}

string pascal_text_representation(vector<string> row_strings) {
  string text{};
  for (const auto& string: row_strings) {
    text += insert_centering_whitespace(string.size());
    text += (string == row_strings.back()) ? "\n" : "";
  }
}

string generate_pascal_triangle(size_t row_number) {
  queue<size_t> above_q{};
  queue<size_t> current_q{};
  queue<size_t> output_q{};
  vector<string> text_rows{};

  for (size_t i{}; i < row_number; ++i) {

    current_q.push(current_q.empty());
    above_q.push(row_number - 1);




    //extract current row convert row values to text
    text_rows.emplace_back(to_string(current_q));
    //prepare data structures for next row
    above_q =
    for (size_t j{}; j < current_q.size(); ++j) {
      output_q.push(current_q.front());
      current_q.pop();
    }
  }
  //return the textual form of Pascal's triangle
  return pascal_text_representation(text_rows);
}

size_t calculate_pascal_number()


#endif //PRACTICE_PASCAL_H
