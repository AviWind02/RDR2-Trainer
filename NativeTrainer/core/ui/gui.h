#pragma once
namespace base {
    namespace GUI {

        namespace colours
        {
            extern Colour optionText;
            extern Colour optionRect;
            extern Colour scrollerColor;
            extern Colour hoverColor;
            extern Colour toggleOff;
            extern Colour toggleOn;
            extern Colour footerRect;
            extern Colour headerRect;
        }

        extern int maxOption;
        extern Vector2 menuPos;
        extern Vector2 optionSize;
        extern Vector2 optionOffets;
        extern Vector2 headerSize;
        extern Vector2 headerTextOffset;
        extern Vector2 footerSize;
        extern Vector2 textOffset;
        extern Vector2 rightTextOffset;
        extern Vector2 FootertextOffset;
        extern Vector2 spriteOffset;
        extern float scrollerY;
        extern float scrollerSpeed;
        extern float textScale;
        extern int hoveredOption;

        bool SetOption(const char* leftText, const char* centerText, const char* rightText);
        void Title();
        void End();
        
        
        void DebuGUI();


    } // namespace GUI
} // namespace Base


