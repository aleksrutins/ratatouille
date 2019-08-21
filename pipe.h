#include <functional>
namespace Ratatouille::Pipe {
    template<class T>
    class Piper {
        T value;
        public:
        Piper(T val) {
            value = val;
        }
        Piper *pipe(std::function<T(T)> fn) {
            value = fn(value);
            return this;
        }
        Piper *callMemberFn(void (*fn)(T)) {
            fn(value);
            return this;
        }
        T ret() {
            T val = value;
            delete this;
            return val;
        }
    };
}