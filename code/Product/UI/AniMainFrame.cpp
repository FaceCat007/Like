#include "..\\..\\stdafx.h"
#include "AniMainFrame.h"
#include "AnimalDiv.h"

void AniMainFrame::clickButton(void *sender, FCTouchInfo touchInfo, void *pInvoke){
	if (touchInfo.m_firstTouch && touchInfo.m_clicks == 1){
		AniMainFrame *mainFrame = (AniMainFrame*)pInvoke;
		FCView *control = (FCView*)sender;
		String name = control->getName();
	}
}

void AniMainFrame::registerEvents(FCView *control){
	FCTouchEventCallBack clickEvent = &clickButton;
	ArrayList<FCView*> controls = control->m_views;
	for(int c = 0; c < controls.size(); c++){
		FCView *subControl = controls.get(c);
		FCButton *button = dynamic_cast<FCButton*>(subControl);
		FCCheckBox *checkBox = dynamic_cast<FCCheckBox*>(subControl);
		FCGridColumn *column = dynamic_cast<FCGridColumn*>(subControl);
		FCGrid *grid = dynamic_cast<FCGrid*>(subControl);
        if (column){
			column->setAllowDrag(true);
            column->setAllowResize(true);
			column->setBackColor(FCCOLORS_BACKCOLOR);
			column->setBorderColor(FCCOLORS_LINECOLOR2);
            column->setTextColor(FCCOLORS_FORECOLOR);
        }
		else if(checkBox){
			checkBox->setButtonBackColor(FCCOLORS_BACKCOLOR);
		}
		else if(button){
			button->addEvent(clickEvent, FCEventID::CLICK, this);
		}
		else if(grid){
			grid->setBackColor(FCColor_None);
			grid->setGridLineColor(FCColor_None);
			FCGridRowStyle rowStyle;
			rowStyle.setBackColor(FCColor_None);
			rowStyle.setSelectedBackColor(FCCOLORS_SELECTEDROWCOLOR);
			rowStyle.setHoveredBackColor(FCCOLORS_HOVEREDROWCOLOR);
			FCFont font(L"Arial", 14, false, false, false);
			rowStyle.setFont(&font);
			grid->setRowStyle(&rowStyle);
		}
		else{
			if(subControl->getViewType() == L"Div" || subControl->getViewType() == L"TabView"
				|| subControl->getViewType() == L"TabPage" 
				|| subControl->getViewType() == L"SplitLayoutDiv"){
				subControl->setBackColor(FCColor_None);
			}
		}
		registerEvents(subControl);
	}
}

void AniMainFrame::timerEvent(void *sender, int timerID, void *pInvoke){
	AniMainFrame *mainFrame = (AniMainFrame*)pInvoke;
	mainFrame->onTimerEvent(sender, timerID);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

AniMainFrame::AniMainFrame(HWND hWnd){
	m_host = 0;
	m_hWnd = hWnd;
	m_scaleFactor = 1;
	m_timerID = FCView::getNewTimerID();
}

AniMainFrame::~AniMainFrame(){
	m_host = 0;
	m_hWnd = 0;
}

double AniMainFrame::getScaleFactor(){
	return m_scaleFactor;
}

void AniMainFrame::setScaleFactor(double scaleFactor){
	m_scaleFactor = scaleFactor;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void AniMainFrame::exit(){
}

bool AniMainFrame::isWindowShowing(){
	ArrayList<FCView*> controls = getNative()->getViews();
	for(int c = 0; c < controls.size(); c++){
        FCWindowFrame *frame = dynamic_cast<FCWindowFrame*>(controls.get(c));
        if (frame){
			return true;
		}
	}
	return false;
}

void AniMainFrame::load(const String& xmlPath){
	m_host = dynamic_cast<WinHost*>(getNative()->getHost());
	loadFile(xmlPath, 0);
	FCView *control = getNative()->getViews().get(0);
	registerEvents(control);

	AnimalDiv *animalDiv = new AnimalDiv;
	animalDiv->setDock(FCDockStyle_Fill);
	control->addView(animalDiv);
}

void AniMainFrame::loadData(){
}

void AniMainFrame::resetScaleSize(FCSize clientSize){
	FCNative *native = getNative();
	if(native){
		FCSize nativeSize = native->getDisplaySize();
        ArrayList<FCView*> controls = native->getViews();
		for(int c = 0; c < controls.size(); c++){
            FCWindowFrame *frame = dynamic_cast<FCWindowFrame*>(controls.get(c));
            if (frame){
                WindowEx *window = dynamic_cast<WindowEx*>(frame->m_views.get(0));
                if (window && !window->isAnimateMoving()){
                    FCPoint location = window->getLocation();
                    if (location.x < 10 || location.x > nativeSize.cx - 10){
                        location.x = 0;
                    }
                    if (location.y < 30 || location.y > nativeSize.cy - 30){
                        location.y = 0;
                    }
                    window->setLocation(location);
                }
            }
        }
		FCSize scaleSize ={(int)(clientSize.cx * m_scaleFactor), (int)(clientSize.cy * m_scaleFactor)};
		native->setScaleSize(scaleSize);
		native->update();
		native->invalidate();
	}
}

int AniMainFrame::showMessageBox(const String& text, const String& caption, UINT uType){
	return MessageBox(m_hWnd, text.c_str(), caption.c_str(), uType);
}

int AniMainFrame::wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	if(m_host && m_host->onMessage(hWnd, message, wParam, lParam)){
		return 1;
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void AniMainFrame::onTimerEvent(void *sender, int timerID){
}