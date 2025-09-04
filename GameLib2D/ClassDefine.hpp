#ifndef CLASS_DEFINE_HPP
#define CLASS_DEFINE_HPP

#define CLASS_SINGLETON_BODY(ClassName)              \
private:                                             \
    ClassName() = default;                           \
    ~ClassName() = default;                          \
    ClassName(const ClassName&) = delete;            \
    ClassName(ClassName&&) = delete;                 \
    ClassName& operator=(const ClassName&) = delete; \
    ClassName& operator=(ClassName&&) = delete;      \
public:\
    [[nodiscard]] static ClassName& GetInstance() {  \
        static ClassName instance;     \
        return instance;               \
    }

#define CLASS_NONINSTANCE(ClassName) \
private: \
    ClassName() = delete;                     \
    ~ClassName() = delete;                    \

#endif 
