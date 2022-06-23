/**
 *  ───────────────────────────────────────────────────────────────────────────────────────────────
 *  ─██████──────────██████─██████████─██████████████████─██████████████─██████──██████─██████████─
 *  ─██░░██████████████░░██─██░░░░░░██─██░░░░░░░░░░░░░░██─██░░░░░░░░░░██─██░░██──██░░██─██░░░░░░██─
 *  ─██░░░░░░░░░░░░░░░░░░██─████░░████─████████████░░░░██─██░░██████░░██─██░░██──██░░██─████░░████─
 *  ─██░░██████░░██████░░██───██░░██───────────████░░████─██░░██──██░░██─██░░██──██░░██───██░░██───
 *  ─██░░██──██░░██──██░░██───██░░██─────────████░░████───██░░██──██░░██─██░░██──██░░██───██░░██───
 *  ─██░░██──██░░██──██░░██───██░░██───────████░░████─────██░░██──██░░██─██░░██──██░░██───██░░██───
 *  ─██░░██──██████──██░░██───██░░██─────████░░████───────██░░██──██░░██─██░░██──██░░██───██░░██───
 *  ─██░░██──────────██░░██───██░░██───████░░████─────────██░░██──██░░██─██░░██──██░░██───██░░██───
 *  ─██░░██──────────██░░██─████░░████─██░░░░████████████─██░░██████░░██─██░░██████░░██─████░░████─
 *  ─██░░██──────────██░░██─██░░░░░░██─██░░░░░░░░░░░░░░██─██░░░░░░░░░░██─██░░░░░░░░░░██─██░░░░░░██─
 *  ─██████──────────██████─██████████─██████████████████─██████████████─██████████████─██████████─
 *  ───────────────────────────────────────────────────────────────────────────────────────────────
 * 
 *  Copyright (C) 2021 Mizosoft, All Rights Reserved.
 *  Written by Hamza EL KAICHE <fewdiefie@hotmail.com>
 */

#ifndef MIZOWINDOW_H
#define MIZOWINDOW_H

#include <string>
#include "MizoBitmap.h"

namespace MizoUI
{
    class MizoWindow
    {
    public:
        MizoWindow(const std::string& Title, int Width, int Height);
        ~MizoWindow();

        void SetCallback(void(*callback)());
        int Run();

        void Alert(const std::string& Message);
        void SetShouldClose(bool ShouldClose);
        void SetMinimized(bool Minimized);
        void SetBackgroundColor(unsigned char Red, unsigned char Green, unsigned char Blue);

        void HorizentalLine(int x, int y, int Width, unsigned char Red, unsigned char Green, unsigned char Blue);
        void VerticalLine(int x, int y, int Height, unsigned char Red, unsigned char Green, unsigned char Blue);
        void Text(int x, int y, const std::string& text, unsigned char Red, unsigned char Green, unsigned char Blue);
        void Bitmap(int x, int y, const MizoBitmap* Bitmap);
        bool Button(int x, int y, const std::string& label, unsigned char BackgroundRed, unsigned char BackgroundGreen, unsigned char BackgroundBlue, unsigned char TextRed, unsigned char TextGreen, unsigned char TextBlue, int iWidth = -1, int iHeight = -1);
        bool ClickableText(int x, int y, const std::string& Text, unsigned char Red, unsigned char Green, unsigned char Blue);
        void TextInput(int x, int y, int Width, std::string& Text, unsigned char Red, unsigned char Green, unsigned char Blue);
        void ProgressBar(int x, int y, int Width, int Height, int Progress, unsigned char Red, unsigned char Green, unsigned char Blue, unsigned char ProgressRed, unsigned char ProgressGreen, unsigned char ProgressBlue);

        class MizoWindowImpl;
    private:
        MizoWindowImpl* m_pImpl;
    };
}

#endif