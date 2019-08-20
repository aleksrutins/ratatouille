namespace Ratatouille::Curry {

    template<class TRet, class TParm1, class TParm2>
    auto curry(TRet (*fn)(TParm1, TParm2), TParm1 firstParam) {
        return [=](TParm2 param) {return fn(firstParam, param);};
    }
}