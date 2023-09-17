#ifndef UNTITLED_LIBRARY_H
#define UNTITLED_LIBRARY_H

#include <variant>

template <typename T, typename E>
struct Result {

    explicit Result(T t) : result_{t} {}
    explicit Result(E e) : result_{e} {}

    [[nodiscard]]
    auto isErr() const noexcept {
        return std::holds_alternative<T>(result_);
    }

    [[nodiscard]]
    auto isResult() const noexcept {
        return std::holds_alternative<E>(result_);
    }

    [[nodiscard]]
    auto getError() const {
        if (!isErr()) {
            throw std::bad_variant_access();
        }
        return std::get<E>(result_);
    }

    [[nodiscard]]
    auto& getResult() const {
        if (!isResult()) {
            throw std::bad_variant_access();
        }
        return std::get<T>(result_);
    }


    std::variant<T, E> result_;
};

#endif //UNTITLED_LIBRARY_H
