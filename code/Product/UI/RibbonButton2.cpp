#include "..\\..\\stdafx.h"
#include "RibbonButton2.h"
#include "GdiPlusPaintEx.h"

RibbonButton2::RibbonButton2(){
    setBorderColor(FCColor_None);
    setTextColor(USERCOLOR84);
    FCFont tFont(L"Default", 12, false, false, false);
    setFont(&tFont);
    setBackColor(USERCOLOR94);
}

RibbonButton2::~RibbonButton2(){
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void RibbonButton2::onPaint(FCPaint *paint, const FCRect& clipRect){
String text = getText();
    if ((int)text.length() >= 0){
        int width = getWidth(), height = getHeight();
        if(width > 0 && height > 0){
            FCRect drawRect = {1, 1, width - 1, height - 1};
            if (this == m_native->getPushedView())
            {
                paint->fillRoundRect(USERCOLOR82, drawRect, 4);
            }
            else if (this == m_native->getHoveredView())
            {
                paint->fillRoundRect(USERCOLOR81, drawRect, 4);
            }
            else
            {
                paint->fillRoundRect(getPaintingBackColor(), drawRect, 4);
            }
            FCFont *font = getFont();
            FCSize tSize = paint->textSize(text, font, -1);
            FCPoint tPoint ={(width - tSize.cx) / 2, (height - tSize.cy) / 2};
            FCPadding padding = getPadding();
            switch (m_textAlign){
                case FCContentAlignment_BottomCenter:
                    tPoint.y = height - tSize.cy;
                    break;
                case FCContentAlignment_BottomLeft:
                    tPoint.x = padding.left;
                    tPoint.y = height - tSize.cy - padding.bottom;
                    break;
                case FCContentAlignment_BottomRight:
                    tPoint.x = width - tSize.cx - padding.right;
                    tPoint.y = height - tSize.cy - padding.bottom;
                    break;
                case FCContentAlignment_MiddleLeft:
                    tPoint.x = padding.left;
                    break;
                case FCContentAlignment_MiddleRight:
                    tPoint.x = width - tSize.cx - padding.right;
                    break;
                case FCContentAlignment_TopCenter:
                    tPoint.y = padding.top;
                    break;
                case FCContentAlignment_TopLeft:
                    tPoint.x = padding.left;
                    tPoint.y = padding.top;
                    break;
                case FCContentAlignment_TopRight:
                    tPoint.x = width - tSize.cx - padding.right;
                    tPoint.y = padding.top;
                    break;
            }
            FCRect tRect ={tPoint.x, tPoint.y, tPoint.x + tSize.cx, tPoint.y + tSize.cy};
            Long textColor = getPaintingTextColor();
            if(MyColor::getStyle() == 1){
                if(this == m_native->getHoveredView() || this == m_native->getPushedView()){
                    textColor = FCColor::rgb(255, 255, 255);
                }
            }
            if(autoEllipsis() && (tRect.right > clipRect.right || tRect.bottom > clipRect.bottom)){
                if(tRect.right > clipRect.right){
                    tRect.right = clipRect.right;
                }
                if(tRect.bottom > clipRect.bottom){
                    tRect.bottom = clipRect.bottom;
                }
                tRect.top -= 1;
                tRect.bottom -= 1;
                paint->drawTextAutoEllipsis(text, textColor, font, tRect);
            }
            else{
                tRect.top -= 1;
                tRect.bottom -= 1;
                paint->drawText(text, textColor, font, tRect, -1);
            }
        }
    }
}
