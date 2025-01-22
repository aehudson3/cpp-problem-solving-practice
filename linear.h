#ifndef PRACTICE_LINEAR_H
#define PRACTICE_LINEAR_H

#include <memory>

template<typename T>
class Node {
    typedef std::unique_ptr<Node<T>> Node_Ptr;
private:
    T data;
public:
    explicit Node(T value) noexcept
            :data{value} { }

    virtual ~Node() noexcept = default;

    T get_data() noexcept { return data; }

    void set_data(T value) noexcept { this->data = value; }
};

template<typename T>
class Single_Linked_Node : public Node<T> {
    typedef std::shared_ptr<Node<T>> Node_Ptr;
//    typedef std::shared_ptr<Single_Linked_Node<T>> SL_Node_Ptr;
private:
    Node_Ptr next;
public:
    explicit Single_Linked_Node(T value) noexcept
            :Node<T>(value), next(nullptr) { }

    ~Single_Linked_Node() noexcept override = default;

    virtual Node_Ptr get_next() noexcept { return this->next; }

    virtual void set_next(Node_Ptr next_) noexcept { this->next = next_; }
};

template<typename T>
class Double_Linked_Node : public Single_Linked_Node<T> {
    typedef std::shared_ptr<Node<T>> Node_Ptr;
    typedef std::shared_ptr<Double_Linked_Node<T>> DL_Node_Ptr;
private:
    Node_Ptr prior;
public:
    explicit Double_Linked_Node(T value) noexcept
            :Single_Linked_Node<T>(value), prior(nullptr) { }

    ~Double_Linked_Node() noexcept override = default;

    Node_Ptr get_prior() noexcept { return this->prior; }

    void set_prior(DL_Node_Ptr prior_) noexcept { this->prior = prior_; }

    Node_Ptr get_next() noexcept { return Single_Linked_Node<T>::get_next(); }

    void set_next(DL_Node_Ptr next_) noexcept { Single_Linked_Node<T>::set_next(next_); }

    virtual std::pair<Node_Ptr, Node_Ptr> get_children() noexcept { return std::make_pair(get_prior(), get_next()); }
};

template<typename T>
class Tree_Node : private Double_Linked_Node<T> {
    typedef std::shared_ptr<Node<T>> Node_Ptr;
    typedef std::shared_ptr<Tree_Node<T>> Tree_Node_Ptr;
public:
    explicit Tree_Node(T value) noexcept
            :Double_Linked_Node<T>(value) { }

    ~Tree_Node() noexcept override = default;

    Node_Ptr get_left() noexcept { return Double_Linked_Node<T>::get_prior(); }

    void set_left(Tree_Node_Ptr left) noexcept { Double_Linked_Node<T>::set_prior(left); }

    Node_Ptr get_right() noexcept { return Double_Linked_Node<T>::get_next(); }

    void set_right(Tree_Node_Ptr right) noexcept { Double_Linked_Node<T>::set_next(right); }

    virtual std::pair<Node_Ptr, Node_Ptr> get_children() noexcept { return std::make_pair(get_left(), get_right()); }
};

#endif //PRACTICE_LINEAR_H
