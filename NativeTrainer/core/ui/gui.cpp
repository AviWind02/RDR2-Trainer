#include "pch.h"
#include <stdio.h>

namespace base {
    namespace GUI {

        namespace colours
        {
            Colour optionText = { 255, 255, 255, 255 };
            Colour optionRect = { 0, 0, 0, 225 };
            Colour scrollerColor = { 255, 223, 0, 175 };
            Colour hoverColor = { 100, 100, 100, 190 };
            Colour toggleOff = { 255, 0, 0, 255 };
            Colour toggleOn = { 0, 255, 0, 255 };
            Colour footerRect = { 0, 0, 0, 255 };
            Colour headerRect = { 0, 0, 0, 255 };
        }


        int maxOption = 10;

        Vector2 menuPos = { 0.15f, 0.125f };
        Vector2 optionSize = { 0.17f, 0.025f };
        Vector2 optionOffets = { 0.f, 0.010f };
        Vector2 headerSize = { optionSize.x, 0.045f };
        Vector2 headerTextOffset = { optionSize.x, 0.065f};
        Vector2 footerSize = { optionSize.x, 0.025f };

        Vector2 textOffset = { 0.08f, 0.0025f };
        Vector2 rightTextOffset = { 0.015f, 0.005f };
        Vector2 FootertextOffset = { 0.08f, 0.0025f };
        Vector2 spriteOffset = { 0.07f, 0.00f };

        float scrollerY = menuPos.y + 0.125f;
        float scrollerSpeed = 0.10f;
        float textScale = 0.25f;


        bool SetOption(const char* leftText, const char* centerText, const char* rightText)
        {
            controls::optionCount++;


            int startOption = (controls::currentOption - 1) / maxOption * maxOption + 1;
            int endOption = startOption + maxOption - 1;

            if (controls::optionCount >= startOption && controls::optionCount <= endOption)
            {
                float yPos = (optionSize.y * (controls::optionCount - startOption + 1) + optionOffets.y) + menuPos.y;

                static float smoothScrollYPosition = yPos;
                float scrollSpeed = 0.10f;

                Vector2 smoothTextPos = { menuPos.x, smoothScrollYPosition };

                draw::Rect(colours::optionRect, { menuPos.x, yPos }, optionSize);

                bool isCurrentOption = controls::currentOption == controls::optionCount;

                if (leftText != NULL)
                {
                    Vector2 leftTextPos = { menuPos.x - textOffset.x, yPos - optionSize.y / 2.00f + textOffset.y };
                    draw::Text(leftText, colours::optionText, leftTextPos, { textScale, textScale }, false);
                }

                if (centerText != NULL)
                {
                    Vector2 centerTextPos = { menuPos.x, yPos - optionSize.y / 2.00f + textOffset.y };
                    draw::Text(centerText, colours::optionText, centerTextPos, { textScale, textScale }, true);
                }

                if (rightText != NULL)
                {
                    Vector2 rightTextPos = { (menuPos.x + textOffset.x) + rightTextOffset.x, yPos - optionSize.y / 2.00f + textOffset.y };
                    draw::RightAlignedText(rightText, colours::optionText, rightTextPos, { textScale, textScale }, 1.00f, 1.00f);
                }

                if (isCurrentOption)
                {
                    smoothScrollYPosition += (yPos - smoothScrollYPosition) * scrollSpeed;
                    draw::Rect(colours::scrollerColor, { menuPos.x, smoothScrollYPosition }, optionSize);

                    if (controls::selectPressed)
                    {
                        return true;
                    }
                }
            }

            return false;
        }

  

        void Title()
        {
            const char* titleText = "Avi";

            Vector2 titlePos = { menuPos.x, menuPos.y };
            draw::Rect(colours::headerRect, titlePos, headerSize);

            Vector2 textPos = { (menuPos.x + (headerSize.x - headerTextOffset.x)) , (menuPos.y + (headerSize.y - headerTextOffset.y)) };
            draw::Text(titleText, colours::optionText, textPos, { 0.65, 0.65 }, true);
        }

        void End()
        {
            int currentPage = (controls::currentOption - 1) / maxOption + 1;
            int startOption = (currentPage - 1) * maxOption + 1;
            int displayedOptions = controls::optionCount - startOption + 1;
            displayedOptions = (displayedOptions > maxOption) ? maxOption : displayedOptions;


            float targetYPosition = (optionSize.y * displayedOptions + optionSize.y + optionOffets.y) + menuPos.y;
            
            static float currentYPosition = targetYPosition;
            float speed = .1f;
            currentYPosition += (targetYPosition - currentYPosition) * speed;

            Vector2 endPos = { menuPos.x, currentYPosition };

            draw::Rect(colours::footerRect, endPos, footerSize);

            int totalPages = (controls::optionCount + maxOption - 1) / maxOption;
            char footerText[32];
            snprintf(footerText, sizeof(footerText), "Page %d/%d", currentPage, totalPages);

            Vector2 leftTextPos = { menuPos.x - FootertextOffset.x, endPos.y - optionSize.y / 2.00f + FootertextOffset.y };
            draw::Text("Avi's Trainer | v1.0.0", colours::optionText, leftTextPos, {textScale, textScale}, false);
            Vector2 rightTextPos = { menuPos.x + FootertextOffset.x, endPos.y - optionSize.y / 2.00f + FootertextOffset.y };
            draw::RightAlignedText(footerText, colours::optionText, rightTextPos, { textScale, textScale }, 1.00f, 1.00f);
        }







        void DebuGUI()
        {
            button::Float("Menu Position X", &menuPos.x, 0.0f, 1.0f, 0.01f);
            button::Float("Menu Position Y", &menuPos.y, 0.0f, 1.0f, 0.01f);

            button::Float("Option Width", &optionSize.x, 0.0f, 1.0f, 0.01f);
            button::Float("Option Height", &optionSize.y, 0.0f, 0.5f, 0.005f);
            button::Float("Option Offets Y", &optionOffets.x, 0.0f, 0.5f, 0.005f);
            button::Float("Option Offets Y", &optionOffets.y, 0.0f, 0.5f, 0.005f);

            button::Float("Header Text Offets Y", &headerTextOffset.x, -0.5f, 0.5f, 0.005f);
            button::Float("Header Text Offets Y", &headerTextOffset.y, -0.5f, 0.5f, 0.005f);
            button::Float("Header Width", &headerSize.x, 0.0f, 1.0f, 0.01f);
            button::Float("Header Height", &headerSize.y, 0.0f, 0.5f, 0.005f);

            button::Float("Footer Text Offset X", &FootertextOffset.x, 0.0f, 1.0f, 0.01f);
            button::Float("Footer Text Offset Y", &FootertextOffset.y, 0.0f, 0.5f, 0.005f);
            button::Float("Footer Width", &footerSize.x, 0.0f, 1.0f, 0.01f);
            button::Float("Footer Height", &footerSize.y, 0.0f, 0.5f, 0.0005f);

            button::Float("Text Offset X", &textOffset.x, 0.0f, 1.0f, 0.01f);
            button::Float("Text Offset Y", &textOffset.y, 0.0f, 0.5f, 0.005f);
            button::Float("Right Text Offset X", &rightTextOffset.x, 0.0f, 0.5f, 0.005f);
            
            button::Float("Sprite Offset X", &spriteOffset.x, 0.0f, 1.0f, 0.01f);
            button::Float("Sprite Offset Y", &spriteOffset.y, 0.0f, 0.5f, 0.005f);

            button::Float("Scroller Y", &scrollerY, 0.0f, 1.0f, 0.01f);
            button::Float("Scroller Speed", &scrollerSpeed, 0.0f, 1.0f, 0.01f);
            button::Float("Text Scale", &textScale, 0.0f, 1.0f, 0.01f);

        }







        //Mouse Control from old GTA 5 base
        Vector2 GetScreenCoords(float normalizedX, float normalizedY) {
            Vector2 screenCoords{ 0, 0 };//Need to eeplace a dynamic resolution height and width
            screenCoords.x = normalizedX * 1920.0f;
            screenCoords.y = normalizedY * 1080.0f;
            return screenCoords;
        }
        bool IsMouseInBounds(float x, float y, float width, float height) {
            float mouseX = CONTROLS::GET_CONTROL_NORMAL(0, INPUT_CURSOR_X);
            float mouseY = CONTROLS::GET_CONTROL_NORMAL(0, INPUT_CURSOR_Y);

            Vector2 mouseCoords = GetScreenCoords(mouseX, mouseY);

            x = x - width / 2;
            y = y - height / 2;

            Vector2 topLeft = GetScreenCoords(x, y);
            Vector2 bottomRight = GetScreenCoords(x + width, y + height);

            return (mouseCoords.x >= topLeft.x && mouseCoords.x <= bottomRight.x) &&
                (mouseCoords.y >= topLeft.y && mouseCoords.y <= bottomRight.y);
        }

        int hoveredOption;
        void CheckMouseInput(float startX, float startY, float optionWidth, float optionHeight) {
            CURSOR::_SHOW_CURSOR_THIS_FRAME();
            CURSOR::_SET_CURSOR_SPRITE(2);

            //Get mouse position
            float mouseX = CONTROLS::GET_CONTROL_NORMAL(0, INPUT_CURSOR_X);
            float mouseY = CONTROLS::GET_CONTROL_NORMAL(0, INPUT_CURSOR_Y);
            Vector2 mouseCoords = GetScreenCoords(mouseX, mouseY);

            //Loop through visible options to check for hover or click
            for (int i = 0; i < controls::optionCount; ++i) {
                float y = startY + optionHeight * i;

                //Check if option is within the visible range
                if (IsMouseInBounds(startX, y, optionWidth, optionHeight)) {
                    //If mouse is hovering over this option, mark it
                    hoveredOption = i + 1;

                    if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, INPUT_CURSOR_ACCEPT)) {
                        controls::currentOption = hoveredOption;
                        controls::selectPressed = true;
                        break;
                    }
                }
            }
        }

        void DebugTick() {
            float mouseX = CONTROLS::GET_CONTROL_NORMAL(0, INPUT_CURSOR_X);
            float mouseY = CONTROLS::GET_CONTROL_NORMAL(0, INPUT_CURSOR_Y);


            char debugBuffer[128];
            snprintf(debugBuffer, sizeof(debugBuffer), "Raw MouseX: %.2f, Raw MouseY: %.2f", mouseX, mouseY);
            Vector2 debugTextPosition = { 0.05f, 0.10f };
            draw::Text(debugBuffer, { 255, 255, 255, 255 }, debugTextPosition, { 0.35f, 0.35f }, false);

            Vector2 mouseCoords = GetScreenCoords(mouseX, mouseY);

            char buffer[128];
            snprintf(buffer, sizeof(buffer), "Mouse Pos: (%.2f, %.2f)", mouseCoords.x, mouseCoords.y);
            Vector2 textPosition = { 0.05f, 0.05f };
            draw::Text(buffer, { 255, 255, 255, 255 }, textPosition, { 0.35f, 0.35f }, false);
        }

    } // namespace GUI
} // namespace Base