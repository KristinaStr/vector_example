#include <iostream>
#include <sstream>
#include <utility>

template <typename T>
class queue_t
{
private:
    struct data_t
    {
        data_t* next;
        T value;
    };
private:
    data_t* head;
    data_t* tail;

public:
    queue_t()
    {
        head = nullptr;
        tail = nullptr;
    }

    data_t * head_r() const {
        return head;
    }
    data_t * tail_r() const {
        return tail;
    }
    T taill(data_t const* tail) const {
        return tail->value;
    }

    T headl(data_t const* head) const {
        return head->value;
    }

    queue_t(queue_t<T> const & other): queue_t ()
    {
        data_t* data = other.head_r();
        while(data != nullptr){
            push(data->value);
            data = data->next;
        }

    }

    queue_t<T> & operator=(queue_t<T> & other)
    {
        if(other.head_r() != nullptr){
            this->~queue_t();
        }

        data_t* data = other.head_r();
        while(data != nullptr){
            push(data->value);
            data = data->next;
        }
        return *this;
    }

    ~queue_t()
    {
        if (head != nullptr)
        {
            del (head);
        }
    }

    void del(data_t* run_)
    {
        if (run_ != nullptr)
        {
            if (run_->next != nullptr)
            {
                del(run_->next);
            }
            delete run_;
        }
    }

    void push(T val ){
        if (head == nullptr)
        {
            head = new data_t;
            head->value = val;
            head->next = nullptr;
            tail = head;
        }
        else
        {
            tail->next = new data_t;
            tail = tail->next;
            tail->value = val;
            tail->next = nullptr;
        }
    }
    T pop (){
        if(head != nullptr){
            T previoushead = head->value;
            data_t* node = head->next;
            delete head;
            head=node;
            return previoushead;
            delete node;
        }
        else {
            throw std::logic_error("Error");
        }
    }
};
