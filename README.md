# Ratatouille
## A library that adds currying and pipes to C.

Ratatouille is a library that adds currying and pipes to C.

## Installation

To install Ratatouille (on Linux), run `$ sudo make install`. This will install `pipe.h` and `curry.h` in `/usr/include/ratatouille`.

## Usage

To use Ratatouille in your program, #include `<ratatouille/pipe.h>` and `<ratatouille/curry.h>`. this will include the Ratatouille::Pipe and Ratatouille::Curry namespaces.

## The Library

### `Ratatouille::Pipe`

### the `Piper<T>` class

`Piper(T val)` (constructor) <br/>
This will construct a new instance of the Piper class with an internal value of `val`.<br/>
<br/>
<code>Piper *pipe(std::function&lt;T(T)&gt; fn)</code>
This will pipe the internal value through `fn`, which takes in the current value and returns the changed value, and return `this`. (Yay! Pure functions!)<br/>
<br/>
<code>ret()</code><br/>
This returns the internal value and frees the instance. The `Piper` is not usable after this function call.

### `Ratatouille::Curry`

```c++
template<class TRet, class TParm1, class TParm2>
auto curry(TRet (*fn)(TParm1, TParm2), TParm1 firstParam)
```
This will return a function that is `fn` with the first argument bound to `firstParam`.