#include "..\\..\\stdafx.h"
#include "WindowEx.h"

void WindowEx::callTouchEvent(String eventName, Object sender, FCTouchInfo touchInfo, Object invoke){
	if (touchInfo.m_firstTouch && touchInfo.m_clicks == 1){
        FCView *control = (FCView*)sender;
        String name = control->getName();
        if (name == L"btnMaxOrRestore"){
            maxOrRestore();
        }
        else if (name == L"btnMin"){
            minWindow();
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

WindowEx::WindowEx(){
    m_animateDirection = 0;
    m_animateMoving = false;
    m_animateType = 0;
    m_closeButton = 0;
    m_isChildWindow = false;
    m_maxOrRestoreButton = 0;
    m_minButton = 0;
    m_normalLocation.x = 0;
    m_normalLocation.y = 0;
    m_normalSize.cx = 0;
    m_normalSize.cy = 0;
	m_tick = 0;
    m_timerID =  FCView::getNewTimerID();
	m_useAnimation = true;
    m_windowState = WindowStateA_Normal;
    setBorderColor(FCColor_None);
    setCaptionHeight(25);
    FCFont wFont(L"Default", 16, false, false, false);
    setFont(&wFont);
    setTextColor(FCColor_None);
    //SetOpacity(0);
    setShadowSize(0);
}

WindowEx::~WindowEx(){
    m_animateMoving = false;
    m_closeButton = 0;
    m_maxOrRestoreButton = 0;
    m_minButton = 0;
    stopTimer(m_timerID);
}

bool WindowEx::isAnimateMoving(){
    return m_animateMoving;
}

WindowButton* WindowEx::getCloseButton(){
    return m_closeButton;
}

void WindowEx::setCloseButton(WindowButton* closeButton){
    m_closeButton = closeButton;
}

bool WindowEx::isChildWindow(){
    return m_isChildWindow;
}

void WindowEx::setChildWindow(bool isChildWindow){
    m_isChildWindow = isChildWindow;
}

WindowButton* WindowEx::getMaxOrRestoreButton(){
    return m_maxOrRestoreButton;
}

void WindowEx::setMaxOrRestoreButton(WindowButton *maxOrRestoreButton){
    m_maxOrRestoreButton = maxOrRestoreButton;
}

WindowButton* WindowEx::getMinButton(){
    return m_minButton;
}

void WindowEx::setMinButton(WindowButton *minButton){
    m_minButton = minButton;
}

bool WindowEx::useAnimation(){
	return m_useAnimation;
}

void WindowEx::setUseAnimation(bool useAnimation){
	m_useAnimation = useAnimation;
}

WindowStateA WindowEx::getWindowState(){
    return m_windowState;
}

void WindowEx::setWindowState(WindowStateA windowState){
    m_windowState = windowState;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void WindowEx::animateShow(bool showDialog){
    FCNative *native = getNative();
    FCSize nativeSize = native->getSize();
    int width = getWidth(), height = getHeight(), mx = (nativeSize.cx - width) / 2, my = (nativeSize.cy - height) / 2, x = mx, y = my;
    FCPoint location = {x, y};
    setLocation(location);
    if(showDialog){
        this->showDialog();
    }
    else{
        show();
    }
    update();
}

void WindowEx::maxOrRestore(){
    if (m_windowState == WindowStateA_Normal){
        m_normalLocation = getLocation();
        m_normalSize = getSize();
        setDock(FCDockStyle_Fill);
        m_windowState = WindowStateA_Max;
        FCPoint maxLocation = {0, 0};
        setLocation(maxLocation);
        FCSize maxSize = getNative()->getSize();
        setSize(maxSize);
        m_maxOrRestoreButton->setStyle(WindowButtonStyle_Restore);
        getNative()->update();
        getNative()->invalidate();
    }
    else{
        setDock(FCDockStyle_None);
        m_windowState = WindowStateA_Normal;
        setLocation(m_normalLocation);
        setSize(m_normalSize);
        m_maxOrRestoreButton->setStyle(WindowButtonStyle_Max);
        getNative()->update();
        getNative()->invalidate();
    }
}

void WindowEx::minWindow(){
    m_normalLocation = getLocation();
    m_normalSize = getSize();
    setDock(FCDockStyle_None);
    m_windowState = WindowStateA_Min;
    m_maxOrRestoreButton->setStyle(WindowButtonStyle_Restore);
    FCSize minSize = {150, getCaptionHeight()};
    setSize(minSize);
    getNative()->update();
    getNative()->invalidate();
}

void WindowEx::onAdd(){
    FCView::onAdd();
    if (!m_closeButton){
        m_closeButton = new WindowButton;
        m_closeButton->setName(L"btnClose");
        FCSize buttonSize = {20, 20};
        m_closeButton->setSize(buttonSize);
        addView(m_closeButton);
    }
    if (!m_maxOrRestoreButton){
        m_maxOrRestoreButton = new WindowButton;
        m_maxOrRestoreButton->setName(L"btnMaxOrRestore");
        m_maxOrRestoreButton->setStyle(WindowButtonStyle_Max);
        FCSize buttonSize = {20, 20};
        m_maxOrRestoreButton->setSize(buttonSize);
        addView(m_maxOrRestoreButton);
        m_maxOrRestoreButton->addEvent((FCTouchEventCallBack*)this, FCEventID_Click, this);
    }
    if (!m_minButton){
        m_minButton = new WindowButton;
        m_minButton->setName(L"btnMin");
        m_minButton->setStyle(WindowButtonStyle_Min);
        FCSize buttonSize = {20, 20};
        m_minButton->setSize(buttonSize);
        addView(m_minButton);
        m_minButton->addEvent((FCTouchEventCallBack*)this, FCEventID_Click, this);
    }
	startTimer(m_timerID, 10);
}

void WindowEx::onDragReady(FCPoint *startOffset){
    startOffset->x = 0;
    startOffset->y = 0;
}

void WindowEx::onPaintBackground(FCPaint *paint, const FCRect& clipRect){
    int width = getWidth();
    int height = getHeight();
	FCRect rect = {0, 0, width, height};
	Long backColor = FCColor::rgb(50, 50, 50);
	Long foreColor = FCColor::rgb(255, 255, 255);
    if (paint->supportTransparent()){
		backColor = FCColor::rgb(100, 100, 100);
    }
	Long borderColor = FCColor::rgba(255, 255, 255, 50);
	if(m_tick >= 200){
		borderColor = FCColor::rgba(50, 105, 217, 255 - (m_tick - 200) * 2);
		foreColor = FCColor::rgba(255, 255, 255, 255 - (m_tick - 200) * 2);
	}
	FCPoint points1[6] = {0};
    int dw1 = 30;
    int dw2 = 50;
    int dSize = 10;
    int dSize2 = 20;
	if(m_tick >= 200){
		dw1 += (m_tick - 200) / 6;
		dw2 += (m_tick - 200) / 6;
		dSize += (m_tick - 200) / 6;
		dSize2 += (m_tick - 200) / 6;
	}
	FCPoint p1 = {dSize, dw1 + dSize};
    FCPoint p2 = {dSize + dw1, dSize};
    FCPoint p3 = {width - dSize, dSize};
    FCPoint p4 = {width - dSize, height - dw2 - dSize2};
    FCPoint p5 = {width - dSize - dw2, height - dSize2};
    FCPoint p6 = {dSize, height - dSize2};
	points1[0] = p1;
    points1[1] = p2;
    points1[2] = p3;
    points1[3] = p4;
    points1[4] = p5;
    points1[5] = p6;
	paint->fillGradientPolygon(FCColor::rgb(9, 30, 42), FCColor::rgba(9, 30, 42, 200), points1, 6, m_tick);
	//paint->fillPolygon(FCColor::argb(230, 9, 30, 42), points1, 6);
    paint->drawPolygon(borderColor, 3, 0, points1, 6);
    paint->drawLine(borderColor, 2, 0, width - dSize - 30, 1, width - 1, 1);
    paint->drawLine(borderColor, 2, 0, width - 1, 1, width - 1, dSize * 2);
    paint->drawLine(borderColor, 2, 0, width - dSize - 20, dSize + 5, width - dSize - 5, dSize + 5);
    paint->drawLine(borderColor, 2, 0, width - dSize - 5, dSize + 5, width - dSize - 5, dSize + 20);
	FCPoint points2[4] = {0};
	FCPoint pp1 = {dSize + 10, dSize + dw1 + 30};
	FCPoint pp2 = {dSize + 10, dSize + dw1 + 2};
	FCPoint pp3 = {dSize + dw1 + 2, dSize + 10};
	FCPoint pp4 = {dSize + dw1 + 30, dSize + 10};
	points2[0] = pp1;
    points2[1] = pp2;
    points2[2] = pp3;
    points2[3] = pp4;
    paint->drawPolyline(borderColor, 2, 0, points2, 4);
    paint->drawLine(borderColor, 2, 0, dSize + dw1 + 31, dSize + 10, dSize + dw1 + 50, dSize + 10);
    paint->drawLine(borderColor, 2, 0, dSize + dw1 + 10, dSize + 18, dSize + dw1 + 40, dSize + 18);
    paint->drawLine(borderColor, 2, 0, dSize + 10, height - dSize * 2 - 8, dSize + 60, height - dSize * 2 - 8);
	FCPoint points3[4] = {0};
	FCPoint pc1 = {dSize + 14, height - dSize2 - 8};
	FCPoint pc2 = {dSize + 18, height - dSize2 - 12};
	FCPoint pc3 = {dSize + 30, height - dSize2 - 12};
	FCPoint pc4 = {dSize + 34, height - dSize2 - 8};
	points3[0] = pc1;
    points3[1] = pc2;
    points3[2] = pc3;
    points3[3] = pc4;
    paint->fillPolygon(borderColor, points3, 4);
	FCPoint points4[6] = {0};
	FCPoint pb1 = {dSize, height - dSize2 - 20};
	FCPoint pb2 = {dSize - 8, height - dSize2 - 10};
	FCPoint pb3 = {dSize - 8, height - 4 - dSize};
	FCPoint pb4 = {dSize + 16, height - 4 - dSize};
	FCPoint pb5 = {dSize + 20, height - dSize2};
	FCPoint pb6 = {dSize, height - dSize2};
	points4[0] = pb1;
    points4[1] = pb2;
    points4[2] = pb3;
    points4[3] = pb4;
    points4[4] = pb5;
    points4[5] = pb6;
    paint->fillPolygon(borderColor, points4, 6);
	FCPoint points5[4] = {0};
	FCPoint pe1 = {width - dSize, height - dSize2 - dw2 - 20};
	FCPoint pe2 = {width - dSize - 4, height - dSize2 - dw2 - 16};
	FCPoint pe3 = {width - dSize - 4, height - dSize2 - dw2};
	FCPoint pe4 = {width - dSize, height - dSize2 - dw2};
	points5[0] = pe1;
    points5[1] = pe2;
    points5[2] = pe3;
    points5[3] = pe4;
    paint->fillPolygon(borderColor, points5, 4);
	FCPoint points6[4] = {0};
	FCPoint pg1 = {width - dSize, height - dSize2 - dw2};
    FCPoint pg2 = {width - dSize - 4, height - dSize2 - dw2 - 2};
    FCPoint pg3 = {width - dSize - 22, height - dSize2 - dw2 + 16};
    FCPoint pg4 = {width - dSize - 20, height - dSize2 - dw2 + 22};
    points6[0] = pg1;
    points6[1] = pg2;
    points6[2] = pg3;
    points6[3] = pg4;
    paint->fillPolygon(borderColor, points6, 4);
	FCPoint points7[3] = {0};
	FCPoint ph1 = {width - 1, height - dSize2 - dw2 - 30};
	FCPoint ph2 = {width - 1, height - dSize2 - dw2 + 3};
	FCPoint ph3 = {width - 1 - dw2 + 20, height - dSize2 - 16};
	points7[0] = ph1;
    points7[1] = ph2;
    points7[2] = ph3;
    paint->drawPolyline(borderColor, 2, 0, points7, 3);
	FCPoint points8[3] = {0};
	FCPoint pl1 = {width - 1 - dw2 + 19, height - dSize2 - 15};
	FCPoint pl2 = {width - dSize - dw2 + 1, height - dSize + 3};
	FCPoint pl3 = {width - dSize - dw2 - 25, height - dSize + 3};
	points8[0] = pl1;
    points8[1] = pl2;
    points8[2] = pl3;

    paint->drawPolyline(borderColor, 2, 0, points8, 3);
	FCPoint points9[6] = {0};
	FCPoint pm1 = {width - dSize - dw2 + 1, height - dSize + 3};
	FCPoint pm2 = {width - dSize - dw2 - 14, height - dSize + 3};
	FCPoint pm3 = {width - dSize - dw2 - 10, height - dSize + 8};
	FCPoint pm4 = {width - dSize - dw2 + 3, height - dSize + 8};
	FCPoint pm5 = {width - dSize - dw2 + 16, height - dSize - 6};
	FCPoint pm6 = {width - dSize - dw2 + 16, height - dSize - 14};

	points9[0] = pm1;
    points9[1] = pm2;
    points9[2] = pm3;
    points9[3] = pm4;
    points9[4] = pm5;
    points9[5] = pm6;
    paint->fillPolygon(borderColor, points9, 6);

    int rwidth = width * 3 / 5;
    if (rwidth > width - dSize * 2 - dw2){
        rwidth = width - dSize2 * 2 - dw2;
    }
	FCPoint points10[4] = {0};
	FCPoint pz1 = {rwidth - 8, height - dSize2 - 6};
    FCPoint pz2 = {rwidth - 12, height - dSize2};
    FCPoint pz3 = {rwidth + 12, height - dSize2};
    FCPoint pz4 = {rwidth + 8, height - dSize2 - 6};

	points10[0] = pz1;
    points10[1] = pz2;
    points10[2] = pz3;
    points10[3] = pz4;
    paint->fillPolygon(borderColor, points10, 4);
    rwidth = width * 7 / 10;
    if (rwidth > width - 30){
        rwidth = width - 30;
    }
	FCPoint points11[4] = {0};
    FCPoint py1 = {rwidth - 16, dSize - 6};
    FCPoint py2 = {rwidth - 20, dSize};
    FCPoint py3 = {rwidth + 20, dSize};
    FCPoint py4 = {rwidth + 16, dSize - 6};

	points11[0] = py1;
    points11[1] = py2;
    points11[2] = py3;
    points11[3] = py4;
    paint->fillPolygon(borderColor, points11, 4);
	FCSize tSize = paint->textSize(getText(), getFont(), -1);
	FCDraw::drawText(paint, getText(), borderColor, getFont(), 100, 15);
	if(m_tick > 200){
		int count = (m_tick - 200) / 8 + 1;
		int left = 80;
		for(int i = 0; i < count; i++){
			FCRect pRect = {left, height - 10, left + 8, height - 6};
			paint->fillRect(borderColor, pRect);
			left += 10;
		}
		left = 15;
		int top = 80;
		count = (m_tick - 200) / 10 + 1;
		for(int i = 0; i < count; i++){
			FCRect pRect = {left, top, left + 8, top + 6};
			paint->fillRect(borderColor, pRect);
			top += 10;
		}
	}
}

void WindowEx::onTimer(int timerID){
	FCWindow::onTimer(timerID);
	if(m_useAnimation){
		if(m_animateDirection == 0){
			m_tick+=3;
			if(m_tick > 300){
				m_animateDirection = 1;
			}
		}
		else if(m_animateDirection == 1){
			m_tick-=3;
			if(m_tick < 0){
				m_animateDirection = 0;
			}
		}
		if(m_tick >= 190 && !isDragging()){
			invalidate();
		}
	}
}

void WindowEx::update(){
    FCView::update();
    int width = getWidth();
    if (m_closeButton){
        FCPoint location = {width - 26, 2};
        m_closeButton->setLocation(location);
    }
	if (m_minButton){
        FCPoint location = {width - 48, 2};
        m_minButton->setLocation(location);
		//m_minButton->setEnabled(false);
    }
	 if (m_maxOrRestoreButton){
        FCPoint location = {width - 70, 2};
        m_maxOrRestoreButton->setLocation(location);
		m_maxOrRestoreButton->setVisible(false);
    }
	FCPoint localtion = getLocation();
    FCSize displaySize = getNative()->getSize();
    if(localtion.y <= 0){
        localtion.y = 10;
        setLocation(localtion);
    }
    else if(localtion.y >= displaySize.cy - 30){
        localtion.y = displaySize.cy - 30;
        setLocation(localtion);
    }
    if(localtion.x <= 0){
        localtion.x = 10;
        setLocation(localtion);
    }
    else if(localtion.x >= displaySize.cx - width){
        localtion.x = displaySize.cx - width;
        setLocation(localtion);
    }
}
