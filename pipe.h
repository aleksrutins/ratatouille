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
        Piper *callMemberFn(void (T::*fn)()) {
            value.*fn();
            return this;
        }
        T ret() {
            T val = value;
            delete this;
            return val;
        }
    };
}