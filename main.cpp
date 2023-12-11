#include <functional>
#include <thread>

static bool callNativeC(se::State& state) {
    const auto& args = state.args();
    const int argc = (int)args.size();

    if (argc != 1) {
        SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 1);
        return false;
    }

    se::Value cb = args[0];

    if (!cb.isObject() || !cb.toObject->isFunction()) {
        SE_REPORT_ERROR("Wrong argument, must be a function")
        return false;
    }

    std::thread([cbCopy = cb]() {
        // some work
        std::this_thread::sleep_for(std::chrono::seconds(2))
        cbCopy.toObject()->call({}, nullptr);
    }).detach();

    return true;
}

SE_BIND_FUNC(callNativeC)

