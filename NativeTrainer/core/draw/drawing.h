#pragma once
namespace base {
    namespace GUI {
        namespace draw {
            extern const float BaseFontHeight;//HMMMMMMM


            void Sprite(char* textureDict, char* textureName, float x, float y, float width, float height, float rotation, Colour rgba);
            void Rect(Colour rgba, Vector2 position, Vector2 size);
            void RightAlignedText(const char* text, Colour rgbaf, Vector2 position, Vector2 size, float screenWidth, float screenHeight);
            float GetTextScaleHeight(float W, float H, float screenWidth, float screenHeight);
            void Text(const char* text, Colour rgbaf, Vector2 position, Vector2 size, bool center);

        } // namespace Draw
    } // namespace GUI
}// namespace Base