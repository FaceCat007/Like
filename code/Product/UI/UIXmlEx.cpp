#include "..\\..\\stdafx.h"
#include "UIXmlEx.h"
#include "RibbonButton.h"
#include "RibbonButton2.h"
#include "WindowEx.h"
#include "WindowButton.h"
#include "..\\Script\\FaceCatScript.h"
#include "..\\Service\\DataCenter.h"
#include "LikeMainFrame.h"

namespace FaceCat{
	UIXmlEx::UIXmlEx(){
		m_scaleFactor = 1;
	}

	UIXmlEx::~UIXmlEx(){
		m_controlsMap.clear();
		m_tempTabPages.clear();
	}

	void UIXmlEx::autoSelectFirstRow(FCGrid *grid){
		int rowsSize = (int)grid->m_rows.size();
		if(rowsSize > 0){
			ArrayList<FCGridRow*> selectedRows = grid->getSelectedRows();
			int selectedRowsSize = (int)selectedRows.size();
			if(selectedRowsSize == 0){
				selectedRows.add(grid->m_rows.get(0));
				grid->setSelectedRows(selectedRows);
			}
		}
	}

	void UIXmlEx::autoSelectLastRow(FCGrid *grid){
		int rowsSize = (int)grid->m_rows.size();
		if(rowsSize > 0){
			ArrayList<FCGridRow*> selectedRows;
			selectedRows.add(grid->m_rows.get(rowsSize - 1));
			grid->setSelectedRows(selectedRows);
		}
	}

	FCView* UIXmlEx::createView(IXMLDOMNode *node, const String& type){
		if (type == L"ribbonbutton"){
            return new RibbonButton;
        }
		else if (type == L"ribbonbutton2"){
            return new RibbonButton2;
        }
        else if (type == L"windowex"){
            return new WindowEx;
		}
		else if (type == L"chartex"){
            return new LikeChart;
		}
		else{
			return FCUIXml::createView(node, type);
		}
	}

	FCView* UIXmlEx::findView(const String& name){
		FCView *control = 0;
		map<String, FCView*>::iterator sIter = m_controlsMap.find(name);
		if(sIter != m_controlsMap.end()){
			control = sIter->second;
		}
		if(!control){
			control = FCUIXml::findView(name);
			m_controlsMap[name] = control;
		}
		if(!control){
			control = m_native->findView(name);
			m_controlsMap[name] = control;
		}
		return control;
	}

	int UIXmlEx::getColumnsIndex(FCGrid *grid, map<int, FCGridColumn*> *columnsIndex){
		for(int c = 0; c < grid->m_columns.size(); c++){
			FCGridColumn *column = grid->m_columns.get(c);
			String columnName = column->getName();
			int columnNameSize = (int)columnName.size();
			String numStr = L"";
			for(int i = 0; i < columnNameSize; i++){
				String sz = columnName.substr(i, 1);
				if(sz == L"0" || sz == L"1" || sz == L"2" || sz == L"3" || sz == L"4" || 
					sz == L"5" || sz == L"6" || sz == L"7" || sz == L"8" || sz == L"9"){
					numStr += sz;
				}
			}
			(*columnsIndex)[FCTran::strToInt(numStr)] = column;
		}
		return 1;
	}

	void UIXmlEx::loadData(){
	}

	void UIXmlEx::loadFile(const String& fileName, FCView *control){
		m_controlsMap.clear();
		FCUIXml::loadFile(fileName, control);
		m_tempTabPages.clear();
	}

	void UIXmlEx::onAddView(FCView *control, IXMLDOMNode *node){
		m_controlsMap[control->getName()] = control;
		FCUIXml::onAddView(control, node);
	}

	void UIXmlEx::removeTempControls(){
		vector<String> tabPageNames;
		map<String, FCView*>::iterator sIter = m_controlsMap.begin();
		for(; sIter != m_controlsMap.end(); ++sIter){
			FCView *control = sIter->second;
			FCTabPage *tabPage = dynamic_cast<FCTabPage*>(control);
			if(tabPage){
				control->getParent()->removeView(control);
				tabPageNames.push_back(sIter->first);
				m_tempTabPages[sIter->first] = tabPage;
				tabPage->setTabView(0);
			}
		}
		vector<String>::iterator sIter2 = tabPageNames.begin();
		for(; sIter2 != tabPageNames.end(); ++sIter2){
			sIter = m_controlsMap.find(*sIter2);
			if(sIter != m_controlsMap.end()){
				m_controlsMap.erase(sIter);
			}
		}
		tabPageNames.clear();
	}

	double UIXmlEx::getScaleFactor(){
		return m_scaleFactor;
	}

	void UIXmlEx::setScaleFactor(double scaleFactor){
		m_scaleFactor = scaleFactor;
	}

	void UIXmlEx::resetScaleSize(FCSize clientSize){
		if(getNative()){
			m_native = getNative();
		}
		if(m_native){
			FCSize nativeSize = m_native->getSize();
			ArrayList<FCView*> controls = m_native->getViews();
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
		}
		FCSize scaleSize = {(int)(clientSize.cx * m_scaleFactor), (int)(clientSize.cy * m_scaleFactor)};
		m_native->setScaleSize(scaleSize);
		m_native->update();
		m_native->invalidate();
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void WindowXmlEx::callTouchEvent(String eventName, Object sender, FCTouchInfo touchInfo, Object invoke){
		if (touchInfo.m_firstTouch && touchInfo.m_clicks == 1){
            FCView *control = (FCView*)sender;
            if(getWindow() && control == getWindow()->getCloseButton()){
                close();
            }
        }
	}

	void WindowXmlEx::callInvokeEvent(String eventName, Object sender, Object args, Object invoke){
		onInvoke(args);
	}
    
    WindowXmlEx::WindowXmlEx(){
		m_isClosing = false;
		m_isWinForm = false;
        m_native = 0;
        m_window = 0;
		m_winForm = 0;
	}
    
	WindowXmlEx::~WindowXmlEx(){
		if(m_window){
			delete m_window;
			m_window = 0;
		}
        m_native = 0;
		m_winForm = 0;
	}

	bool WindowXmlEx::isWinForm(){
		return m_isWinForm;
	}

	void WindowXmlEx::setIsWinForm(bool isWinForm){
		m_isWinForm = isWinForm;
	}
    
    WindowEx* WindowXmlEx::getWindow(){
        return m_window;
    }
    
	void WindowXmlEx::close(){
		m_isClosing = true;
        m_window->invoke((void*)-10000);
	}
    
    void WindowXmlEx::load(FCNative *native, String xmlName, String windowName){
        setNative(native);
        m_native = native;
        string appPath = DataCenter::getAppPath();
        String wAppPath = FCTran::stringToString(appPath);
        String xmlPath = wAppPath + L"\\config\\" + xmlName + L".xml";
        setScript(new FaceCatScript(this));
        loadFile(xmlPath, 0);
        m_window = dynamic_cast<WindowEx*>(findView(windowName));
        m_window->addEvent((FCInvokeEventCallBack*)this, FCEventID_Invoke, this);
    }
    
    void WindowXmlEx::onInvoke(void *args){
        int state = (int)args;
        if (state == -10000){
			if(m_window){
				m_window->close();
			}
			m_native->m_draggingView = 0;
			m_native->m_focusedView = 0;
			m_native->m_touchDownView = 0;
			m_native->m_touchMoveView = 0;
			FCNative *native = m_native;
            native->invalidate();
			delete this;
        }
    }
    
	void WindowXmlEx::show(){
		FCPoint location ={-m_window->getWidth(), -m_window->getHeight()};
		m_window->setLocation(location);
		m_window->animateShow(false);
		m_window->invalidate();
	}

	void WindowXmlEx::showDialog(){
		FCPoint location ={-m_window->getWidth(), -m_window->getHeight()};
		m_window->setLocation(location);
		m_window->animateShow(true);
		m_window->invalidate();
	}

	void FCGridRowEx::onPaint(FCPaint *paint, const FCRect& clipRect, bool isAlternate){
		FCRect drawRect = clipRect;
		drawRect.left += 1;
		drawRect.right -= 1;
		if(isAlternate){
			paint->fillGradientRect(FCColor::rgba(255, 255, 255, 10), FCColor::rgba(255, 255, 255, 10), drawRect, 0, 90);
		}
		bool isSelectedRow = false;
		ArrayList<FCGridRow*> selectedRows = getGrid()->getSelectedRows();
		if(selectedRows.size() > 0){
			if(selectedRows.get(0) == this){
				isSelectedRow = true;
			}
		}
		if(isSelectedRow){

			int dCount = 0;
			if(m_grid->getVScrollBar() && m_grid->getVScrollBar()->isVisible()){
				drawRect.right -= 8;
			}
			paint->drawRoundRect(USERCOLOR17, 1, 0, drawRect, 0);
		}
	}

	void FCGridRowEx::onPaintBorder(FCPaint *paint, const FCRect& clipRect, bool isAlternate){
		
	}
}