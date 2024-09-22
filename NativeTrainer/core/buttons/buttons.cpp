#include "pch.h"


namespace base {
    namespace GUI {
        namespace button {
            
            bool Option(const char* Opiton)
            {
                return SetOption(Opiton, NULL, NULL);
            }

            bool Option(const char* Opiton, bool *value)//Used for those method only for a tick
            {
                bool clicked = SetOption(Opiton, NULL, NULL);
                if (clicked) {
                    *value = true;
                }
                return clicked;
            }

            bool Option(const char* Option, void (*func)()) { //This one runs a void function
                bool clicked = SetOption(Option, NULL, NULL);
                if (clicked) {
                    func(); 
                }
                return clicked;
            }

            bool Sub(const char* Opiton, pages::SubMenu menu)
            {
                bool clicked = SetOption(Opiton, NULL, ">");//To lazy to adjust a Sprite here
                if (clicked) {
                    controls::NextSubmenu(menu);
                }
                return clicked;
            }

            bool Toggle(const char* option, bool *value) {

             
                bool clicked = SetOption(option, NULL, *value ? "[True]" : "[False]");

                if (clicked) {
                    *value = !*value;
                }

                return clicked;
            }


            bool Int(const char* option, int* value, int min, int max, int step) {

                bool clicked = false;

                char valueTextBuffer[128];
                snprintf(valueTextBuffer, sizeof(valueTextBuffer), "[%d/%d]", *value, max);

                clicked = SetOption(option, NULL, valueTextBuffer);



                if (controls::currentOption == controls::optionCount) {

                    if (controls::rightPressed) {
                        *value += step;
                        if (*value > max) *value = min;
                    }
                    else if (controls::leftPressed) {
                        *value -= step;
                        if (*value < min) *value = max;
                    }
                }

                return clicked;
            }

  
            bool Float(const char* option, float* value, float min, float max, float step) {
                bool clicked = false;
                char valueTextBuffer[128];


                if (step >= 1.0f) {
                    snprintf(valueTextBuffer, sizeof(valueTextBuffer), "[%.0f/%.0f]", *value, max);
                }
                else if (step >= 0.1f) {
                    snprintf(valueTextBuffer, sizeof(valueTextBuffer), "[%.1f/%.1f]", *value, max);
                }
                else if (step >= 0.01f) {
                    snprintf(valueTextBuffer, sizeof(valueTextBuffer), "[%.2f/%.2f]", *value, max);
                }
                else {
                    snprintf(valueTextBuffer, sizeof(valueTextBuffer), "[%.3f/%.3f]", *value, max);
                }

                clicked = SetOption(option, NULL, valueTextBuffer);

                if (controls::currentOption == controls::optionCount) {

                    if (controls::rightPressed) {
                        *value += step;
                        if (*value > max) *value = min;
                    }
                    else if (controls::leftPressed) {
                        *value -= step;
                        if (*value < min) *value = max;
                    }
                }

                return clicked;
            }
     
            bool Int(const char* option, int* value, int min, int max, int step, void (*func)())
            {
                bool clicked = Int(option, value, min, max, step);
                if (clicked) {
                    func();
                }
                return clicked;
            }

            bool Float(const char* option, float* value, float min, float max, float step, void (*func)())
            {
                bool clicked = Float(option, value, min, max, step);
                if (clicked) {
                    func();
                }
                return clicked;
            }

            bool StringArray(const char* option, int& currentIndex, const std::vector<std::string>& options)
            {
                if (options.empty())
                    return false;

                char valueTextBuffer[128];
                snprintf(valueTextBuffer, sizeof(valueTextBuffer), "[%s]", options[currentIndex]);
                bool cliked = SetOption(option, NULL, valueTextBuffer);

                if (controls::currentOption == controls::optionCount)
                {
                    if (controls::rightPressed)
                    {
                        currentIndex = (currentIndex + 1) % options.size();
                        return true;
                    }
                    else if (controls::leftPressed)
                    {
                        currentIndex = (currentIndex - 1 + options.size()) % options.size();
                        return true;
                    }
                    return cliked;
                }
                return false;
            }

        }// BUTTON
    }// GUI
}// BASE




