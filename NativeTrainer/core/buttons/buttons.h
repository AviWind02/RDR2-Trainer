#pragma once
namespace base {
    namespace GUI {
        namespace button {

            bool Option(const char* Opiton);
            bool Option(const char* Opiton, bool *value);
            bool Option(const char* Option, void (*func)());
            bool Sub(const char* Opiton, pages::SubMenu menu);
            bool Toggle(const char* option, bool *value);
            bool Int(const char* option, int* value, int min, int max, int step);
            bool Int(const char* option, int* value, int min, int max, int step, void (*func)());
            bool Float(const char* option, float* value, float min, float max, float step);
            bool Float(const char* option, float* value, float min, float max, float step, void (*func)());
            bool StringArray(const char* option, int& currentIndex, const std::vector<std::string>& options);

        } // namespace Button
    } // namespace GUI
} // namespace Base
