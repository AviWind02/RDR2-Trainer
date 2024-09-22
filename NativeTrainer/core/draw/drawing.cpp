#include "pch.h"

namespace base {
    namespace GUI {
        namespace draw {

            // Draw Text
            void Text(const char* text, Colour rgbaf, Vector2 position, Vector2 size, bool center) {
                UI::SET_TEXT_SCALE(size.x, size.y);
                UI::_SET_TEXT_COLOR(rgbaf.r, rgbaf.g, rgbaf.b, rgbaf.a);
                UI::SET_TEXT_CENTRE(center);
                UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
                auto str = UI::_CREATE_VAR_STRING(10, "LITERAL_STRING", text);
                UI::_DRAW_TEXT(str, position.x, position.y);
            }

            const float BaseFontHeight = 0.035f;
            float GetTextScaleHeight(float W, float H, float screenWidth, float screenHeight) {
                float normalizedHeight = BaseFontHeight * H * screenHeight;
                float normalizedWidth = BaseFontHeight * W * screenWidth;
                return normalizedHeight;
            }

            void RightAlignedText(const char* text, Colour rgbaf, Vector2 position, Vector2 size, float screenWidth, float screenHeight) {
                float textHeight = GetTextScaleHeight(size.x, size.y, screenWidth, screenHeight);
                float textWidth = textHeight * strlen(text) * 0.5f;
                float adjustedX = position.x - textWidth;

                UI::SET_TEXT_SCALE(size.x, size.y);
                UI::_SET_TEXT_COLOR(rgbaf.r, rgbaf.g, rgbaf.b, rgbaf.a);
                UI::SET_TEXT_DROPSHADOW(1, 0, 0, 0, 0);

                auto str = UI::_CREATE_VAR_STRING(10, "LITERAL_STRING", text);
                UI::_DRAW_TEXT(str, adjustedX, position.y);
            }

            void Rect(Colour rgba, Vector2 position, Vector2 size) {
                GRAPHICS::DRAW_RECT(position.x, position.y, size.x, size.y, rgba.r, rgba.g, rgba.b, rgba.a, NULL, NULL);
            }

            void Sprite(char* textureDict, char* textureName, float x, float y, float width, float height, float rotation, Colour rgba) {
                if (!TEXTURE::HAS_STREAMED_TEXTURE_DICT_LOADED(textureDict)) {
                    TEXTURE::REQUEST_STREAMED_TEXTURE_DICT(textureDict, false);
                }
                else {
                    GRAPHICS::DRAW_SPRITE(textureDict, textureName, x, y, width, height, rotation, rgba.r, rgba.g, rgba.b, rgba.a, NULL);
                }
            }

        } // namespace Draw
    } // namespace GUI
} // namespace Base