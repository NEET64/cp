#pragma once
#include <bits/stdc++.h>
#include <unistd.h>
#pragma GCC push_options
#pragma GCC optimize("O0")

namespace dbg {

inline const bool color = [] {
    auto set = [](const char* v) { const char* e = std::getenv(v); return e && *e; };
    return !set("NO_COLOR") && (set("FORCE_COLOR") || isatty(2));
}();

inline const char *NAME = "253;151;31", *EQUAL = "249;38;114", *NUMBER = "174;129;255",
                  *TEXT = "230;219;116", *LABEL = "166;226;46", *GREY = "117;113;94";

inline std::string paint(const char* rgb, const std::string& s) {
    return color ? std::string("\x1b[38;2;") + rgb + "m" + s + "\x1b[0m" : s;
}

inline size_t width(const std::string& s) {
    size_t n = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == '\x1b') i = s.find('m', i);
        else n++;
    }
    return n;
}

template <class T>
concept range = requires(const T& x) { std::begin(x); std::end(x); };

template <class T>
concept text = std::is_convertible_v<const T&, std::string_view>;

template <class T>
concept adapter = requires(T q) { q.pop(); q.empty(); };

template <class T>
concept seq = range<T> && !text<T> && !requires { typename T::mapped_type; };

template <class T>
using elem = std::remove_cvref_t<decltype(*std::begin(std::declval<const T&>()))>;

template <class T>
concept table = seq<T> && seq<elem<T>>;

struct any {
    template <class T>
    operator T() const;
};

template <class T, class... A>
constexpr size_t fields() {
    if constexpr (requires { T{A{}..., any{}}; }) return fields<T, A..., any>();
    else return sizeof...(A);
}

template <class T>
std::string str(const T& x);

template <class... F>
std::string join(const F&... f) {
    std::string s;
    ((s += (s.empty() ? "" : ", ") + str(f)), ...);
    return s;
}

template <class T>
std::string str(const T& x) {
    if constexpr (text<T>) {
        return paint(TEXT, '"' + std::string(std::string_view(x)) + '"');
    } else if constexpr (std::is_same_v<T, char>) {
        return paint(TEXT, std::string("'") + x + "'");
    } else if constexpr (std::is_same_v<T, bool>) {
        return paint(NUMBER, x ? "true" : "false");
    } else if constexpr (std::is_same_v<T, __int128>) {
        return x < 0 ? "-" + str(-(unsigned __int128)x) : str((unsigned __int128)x);
    } else if constexpr (std::is_same_v<T, unsigned __int128>) {
        std::string s;
        auto v = x;
        do s += char('0' + v % 10); while (v /= 10);
        return paint(NUMBER, {s.rbegin(), s.rend()});
    } else if constexpr (std::is_floating_point_v<T>) {
        char buf[64];
        return paint(NUMBER, {buf, std::to_chars(buf, buf + 64, x).ptr});
    } else if constexpr (std::is_arithmetic_v<T>) {
        return paint(NUMBER, std::to_string(x));
    } else if constexpr (adapter<T>) {
        T q = x;
        std::vector<typename T::value_type> v;
        for (; !q.empty(); q.pop()) {
            if constexpr (requires { q.top(); }) v.push_back(q.top());
            else v.push_back(q.front());
        }
        return str(v);
    } else if constexpr (range<T>) {
        std::string s;
        for (const auto& e : x) {
            if (!s.empty()) s += ", ";
            if constexpr (seq<T>) s += str(e);
            else s += str(e.first) + ": " + str(e.second);
        }
        if constexpr (requires { typename T::key_type; }) return "{" + s + "}";
        else return "[" + s + "]";
    } else if constexpr (requires { std::tuple_size<T>::value; }) {
        return "(" + std::apply([](const auto&... e) { return join(e...); }, x) + ")";
    } else if constexpr (requires(std::ostream& o) { o << x; }) {
        std::ostringstream o;
        o << x;
        return o.str();
    } else if constexpr (std::is_aggregate_v<T> && fields<T>() == 1) {
        const auto& [a] = x;
        return "{" + join(a) + "}";
    } else if constexpr (std::is_aggregate_v<T> && fields<T>() == 2) {
        const auto& [a, b] = x;
        return "{" + join(a, b) + "}";
    } else if constexpr (std::is_aggregate_v<T> && fields<T>() == 3) {
        const auto& [a, b, c] = x;
        return "{" + join(a, b, c) + "}";
    } else if constexpr (std::is_aggregate_v<T> && fields<T>() == 4) {
        const auto& [a, b, c, d] = x;
        return "{" + join(a, b, c, d) + "}";
    } else if constexpr (std::is_aggregate_v<T> && fields<T>() == 5) {
        const auto& [a, b, c, d, e] = x;
        return "{" + join(a, b, c, d, e) + "}";
    } else {
        return paint(GREY, "<?>");
    }
}

template <class T>
std::string block(const std::string& name, const T& x) {
    if (std::empty(x)) return paint(NAME, name) + paint(EQUAL, " = ") + str(x) + "\n";
    std::string s;
    if constexpr (table<elem<T>>) {
        size_t i = 0;
        for (const auto& e : x) s += block(name + "[" + std::to_string(i++) + "]", e);
        return s;
    } else {
        size_t w = 0;
        for (const auto& row : x) {
            for (const auto& e : row) w = std::max(w, width(str(e)));
        }
        bool set = requires { typename elem<T>::key_type; };
        for (const auto& row : x) {
            std::string r;
            for (const auto& e : row) {
                std::string cell = str(e);
                r += (r.empty() ? "" : ", ") + std::string(w - width(cell), ' ') + cell;
            }
            s += set ? "  {" + r + "}\n" : "  [" + r + "]\n";
        }
        return paint(NAME, name) + paint(EQUAL, " =") + "\n" + s;
    }
}

inline std::vector<std::string> split(std::string_view names) {
    std::vector<std::string> v(1);
    int depth = 0;
    char quote = 0;
    for (size_t i = 0; i < names.size(); i++) {
        char c = names[i];
        if (c == ',' && !depth && !quote) {
            v.emplace_back();
            continue;
        }
        if (c == ' ' && v.back().empty()) continue;
        v.back() += c;
        if (quote) {
            if (c == '\\') v.back() += names[++i];
            else if (c == quote) quote = 0;
        } else if (c == '"' || c == '\'') {
            quote = c;
        } else if (c == '(' || c == '[' || c == '{') {
            depth++;
        } else if (c == ')' || c == ']' || c == '}') {
            depth--;
        }
    }
    return v;
}

template <class... T>
void print(const char* names, const T&... xs) {
    auto name = split(names);
    std::string out, line;
    size_t i = 0;
    [[maybe_unused]] auto add = [&](const auto& x) {
        using X = std::remove_cvref_t<decltype(x)>;
        const std::string& n = name[i++];
        if constexpr ((range<X> && !text<X>) || adapter<X>) {
            if (!line.empty()) out += line + "\n";
            line.clear();
            if constexpr (table<X>) out += block(n, x);
            else out += paint(NAME, n) + paint(EQUAL, " = ") + str(x) + "\n";
        } else {
            if (!line.empty()) line += line.back() == ':' ? " " : ", ";
            if constexpr (text<X>) {
                if (n[0] == '"') {
                    line += paint(LABEL, std::string(std::string_view(x))) + ":";
                    return;
                }
            }
            line += paint(NAME, n) + paint(EQUAL, " = ") + str(x);
        }
    };
    (add(xs), ...);
    if (!line.empty() || out.empty()) out += line + "\n";
    std::cerr << out;
}

}

#pragma GCC pop_options

#define debug(...) dbg::print(#__VA_ARGS__ __VA_OPT__(, ) __VA_ARGS__)
