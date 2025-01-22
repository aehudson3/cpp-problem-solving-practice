#include <iostream>
#include "linear.h"
#include <string>
#include <stack>
#include <memory>

int sum_from_to(int start, int stop) {
  return (start != stop) ? start + sum_from_to(start + 1, stop) : stop;
}

bool is_valid_parenthesis(const std::string& string_) {
  std::stack<std::string> stack_;
  for (const auto character: string_) {
    if (character == '(') {
      stack_.emplace("(");
    } else {
      if (character == ')') {
        if (stack_.empty()) {
          return false;
        } else {
          stack_.pop();
        }
      }
    }
  }
  return stack_.empty();
}

int main() {
  auto dl_node{std::make_shared<Double_Linked_Node<char>>('b')};
  auto prior_dl_node{std::make_shared<Double_Linked_Node<char>>('a')};
  auto next_dl_node{std::make_shared<Double_Linked_Node<char>>('c')};
  dl_node->set_prior(prior_dl_node);
  dl_node->set_next(next_dl_node);
  std::cout << dl_node->get_data() << "\n"
            << dl_node->get_prior()->get_data() << "\n"
            << dl_node->get_next()->get_data() << "\n"
            << dl_node->get_children().first->get_data() << "\n"
            << dl_node->get_children().second->get_data() << std::endl;

  auto tree_node{std::make_shared<Tree_Node<char>>('e')};
  auto left_tree_node{std::make_shared<Tree_Node<char>>('d')};
  auto right_tree_node{std::make_shared<Tree_Node<char>>('f')};
  tree_node->set_left(left_tree_node);
  tree_node->set_right(right_tree_node);
  std::cout << tree_node->get_data() << "\n"
            << tree_node->get_left()->get_data() << "\n"
            << tree_node->get_right()->get_data() << "\n"
            << tree_node->get_children().first->get_data() << "\n"
            << tree_node->get_children().second->get_data() << std::endl;
  return EXIT_SUCCESS;
}
