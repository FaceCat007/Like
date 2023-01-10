#include "..\\..\\stdafx.h"
#include "LikeMainFrame.h"
#include "..\\Service\\DataCenter.h"
#include "..\\Service\\SecurityDataHelper.h"


void LikeChart::onPaintCandle(FCPaint *paint, ChartDiv *div, CandleShape *cs){
	int x = 0, y = 0;
	vector<FCPoint> points;
	int visibleMaxIndex = 0, visibleMinIndex = 0;
	double visibleMax = 0, visibleMin = 0;
	int ciHigh = m_dataSource->getColumnIndex(cs->getHighField());
	int ciLow = m_dataSource->getColumnIndex(cs->getLowField());
	int ciOpen = m_dataSource->getColumnIndex(cs->getOpenField());
	int ciClose = m_dataSource->getColumnIndex(cs->getCloseField());
	int ciClr = m_dataSource->getColumnIndex(cs->getColorField());
	int ciStyle = m_dataSource->getColumnIndex(cs->getStyleField());
	int defaultLineWidth = 1;
	double vmax = m_dataSource->NaN, vmin = m_dataSource->NaN;
	if(cs->fillVScale()){
		getShapeMaxMin(cs, &vmax, &vmin);
	}
    if (!isOperating() && m_crossStopIndex != -1){
        if (selectCandle(div, (float)getTouchPoint().y, cs->getHighField(), cs->getLowField(), cs->getStyleField(), cs->getAttachVScale(), m_crossStopIndex, vmax, vmin)){
            defaultLineWidth = 2;
        }
    }
	for (int i = m_firstVisibleIndex; i <= m_lastVisibleIndex; i++){
		int thinLineWidth = 1;
		if(i == m_crossStopIndex){
			thinLineWidth = defaultLineWidth;
		}
		int style = -10000;
		switch (cs->getStyle()){
			case CandleStyle_Rect:
				style = 0;
				break;
			case CandleStyle_American:
				style = 3;
				break;
			case CandleStyle_CloseLine:
				style = 4;
				break;
			case CandleStyle_Tower:
				style = 5;
				break;
		}
		if (ciStyle != -1){
			double defineStyle = m_dataSource->get3(i, ciStyle);
			if (!FCDataTable::isNaN(defineStyle)){
				style = (int)defineStyle;
			}
		}
		if (style == -10000){
			continue;
		}
		double open = m_dataSource->get3(i, ciOpen);
		double high = m_dataSource->get3(i, ciHigh);
		double low = m_dataSource->get3(i, ciLow);
		double close = m_dataSource->get3(i, ciClose); 
		if (FCDataTable::isNaN(open) || FCDataTable::isNaN(high) || FCDataTable::isNaN(low) || FCDataTable::isNaN(close)){
            if (i != m_lastVisibleIndex || style != 4){
                continue;
            }
		}
		int scaleX = (int)getX(i);
		if (cs->getShowMaxMin()){
			if (i == m_firstVisibleIndex){
				visibleMaxIndex = i;
				visibleMinIndex = i;
				visibleMax = high;
				visibleMin = low ;
			}
			else{
				if (high > visibleMax){
					visibleMax = high;
					visibleMaxIndex = i;
				}
				if (low < visibleMin){
					visibleMin = low;
					visibleMinIndex = i;
				}
			}
		}
		int highY = (int)getY(div, high, cs->getAttachVScale(), vmax, vmin);
		int openY = (int)getY(div, open, cs->getAttachVScale(), vmax, vmin);
		int lowY = (int)getY(div, low, cs->getAttachVScale(), vmax, vmin);
		int closeY = (int)getY(div, close, cs->getAttachVScale(), vmax, vmin);
		int cwidth = (int)(m_hScalePixel * 2 / 3);
		if (cwidth % 2 == 0){
			cwidth += 1;
		}
		if (cwidth < 3){
			cwidth = 1;
		}
		int xsub = cwidth / 2;
		if(xsub < 1){
			xsub = 1;
		}
		switch(style){
		case 3:{
				Long color = cs->getUpColor();
				if(open > close){
					color = cs->getDownColor();
				}
				if (ciClr != -1){
					double defineColor = m_dataSource->get3(i, ciClr);
					if(!FCDataTable::isNaN(defineColor)){
						color = (Long)defineColor;
					}
				}
				if ((int)highY != (int)lowY){
					if (m_hScalePixel <= 3){
						drawThinLine(paint, color, thinLineWidth, scaleX, highY, scaleX, lowY);
					}
					else{
						drawThinLine(paint, color, thinLineWidth, scaleX, highY, scaleX, lowY);
						drawThinLine(paint, color, thinLineWidth, scaleX - xsub, openY, scaleX, openY);
						drawThinLine(paint, color, thinLineWidth, scaleX, closeY, scaleX + xsub, closeY);
					}
				}
				else{
					drawThinLine(paint, color, thinLineWidth, scaleX - xsub, closeY, scaleX + xsub, closeY);
				}
				break;
			}
		case 4:
			onPaintPolyline(paint, div, cs->getUpColor(), FCColor_None, ciClr, (float)defaultLineWidth, PolylineStyle_SolidLine, close, cs->getAttachVScale(), scaleX, (int)closeY, i, &points, &x, &y, vmax, vmin);
			break;
		default:
			if (open <= close){
				float recth = getUpCandleHeight(close, open, div->getVScale(cs->getAttachVScale())->getVisibleMax(), div->getVScale(cs->getAttachVScale())->getVisibleMin(), (float)div->getWorkingAreaHeight() - div->getVScale(cs->getAttachVScale())->getPaddingBottom() - div->getVScale(cs->getAttachVScale())->getPaddingTop());
				if (recth < 1){
					recth = 1;
				}
				int rcUpX = scaleX - xsub, rcUpTop = (int)closeY, rcUpBottom = (int)openY, rcUpW = cwidth, rcUpH = (int)recth;
				if (openY < closeY){
					rcUpTop = (int)openY;
					rcUpBottom = (int)closeY;
				}
				Long upColor = FCColor_None;
				int colorField = cs->getColorField();
				if (colorField != FCDataTable::NULLFIELD()){
					double defineColor = m_dataSource->get2(i, colorField);
					if(!FCDataTable::isNaN(defineColor)){
						upColor = (Long)defineColor;
					}
				}
				if(upColor == FCColor_None){
					if (open == close && cs->getMidColor() != FCColor_None){
						upColor = cs->getMidColor();
					}
					else{
						upColor = cs->getUpColor();
					}
				}
				switch (style){
					case 0:
					case 1:
					case 2:
						if ((int)highY != (int)lowY){
							drawThinLine(paint, upColor, thinLineWidth, scaleX, highY, scaleX, lowY);
							if (m_hScalePixel > 3){
								if ((int)openY == (int)closeY){
									drawThinLine(paint, upColor, thinLineWidth, rcUpX, rcUpBottom, rcUpX + rcUpW, rcUpBottom);
								}
								else{
									FCRect rcUp = {rcUpX, rcUpTop, rcUpX + rcUpW, rcUpBottom};
									if (style == 0 || style == 1){
										paint->fillRect(upColor, rcUp);
									}
									else if (style == 2){
										paint->fillRect(upColor, rcUp);
										if (thinLineWidth > 1){
                                            paint->fillRect(upColor, rcUp);
                                        }
									}
								}
							}
						}
						else{
							drawThinLine(paint, upColor, thinLineWidth, scaleX - xsub, closeY, scaleX + xsub, closeY);
						}
						break;
					case 5:{
							double lOpen = m_dataSource->get3(i - 1, ciOpen);
							double lClose = m_dataSource->get3(i - 1, ciClose);
							double lHigh = m_dataSource->get3(i - 1, ciHigh);
							double lLow = m_dataSource->get3(i - 1, ciLow);
							int top = highY;
							int bottom = lowY;
							if ((int)highY > (int)lowY){
								top = lowY;
								bottom = highY;
							}
							if (i == 0 || FCDataTable::isNaN(lOpen) || FCDataTable::isNaN(lClose) || FCDataTable::isNaN(lHigh) || FCDataTable::isNaN(lLow)){
								if (m_hScalePixel <= 3){
									drawThinLine(paint, upColor, thinLineWidth, rcUpX, top, rcUpX, bottom);
								}
								else{
									int rcUpHeight = (int)abs(bottom - top == 0 ? 1 : bottom - top);
									if (rcUpW > 0 && rcUpHeight > 0){
										FCRect rcUp = {rcUpX, top, rcUpX + rcUpW, top + rcUpHeight};
										paint->fillRect(upColor, rcUp);
										if (thinLineWidth > 1){
                                            paint->drawRect(upColor, (float)thinLineWidth, 0, rcUp);
                                        }
									}
								}
							}
							else{
								if (m_hScalePixel <= 3){
									drawThinLine(paint, upColor, thinLineWidth, rcUpX, top, rcUpX, bottom);
								}
								else{
									int rcUpHeight = (int)abs(bottom - top == 0 ? 1 : bottom - top);
									if (rcUpW > 0 && rcUpHeight> 0){
										FCRect rcUp = {rcUpX, top, rcUpX + rcUpW, top + rcUpHeight};
										paint->fillRect(upColor, rcUp);
										if (thinLineWidth > 1){
                                            paint->drawRect(upColor, (float)thinLineWidth, 0, rcUp);
                                        }
									}
								}
								if (lClose < lOpen && low < lHigh){
									int tx = rcUpX;
									int ty = (int)getY(div, lHigh, cs->getAttachVScale(), vmax, vmin);
									if (high < lHigh){
										ty = (int)highY;
									}
									int width = rcUpW;
									int height = (int)lowY - ty;
									if (height > 0){
										if (m_hScalePixel <= 3){
											drawThinLine(paint, cs->getDownColor(), thinLineWidth, tx, ty, tx, ty + height);
										}
										else{
											if (width > 0 && height > 0){
												FCRect rect = {tx, ty, tx + width, ty + height};
												paint->fillRect(cs->getDownColor(), rect);
												if (thinLineWidth > 1){
													paint->drawRect(cs->getDownColor(), (float)thinLineWidth, 0, rect);
												}
											}
										}
									}
								}
							}
							break;
						}
				}
			}
			else{
				float recth = getDownCandleHeight(close, open, div->getVScale(cs->getAttachVScale())->getVisibleMax(), div->getVScale(cs->getAttachVScale())->getVisibleMin(), (float)div->getWorkingAreaHeight() - div->getVScale(cs->getAttachVScale())->getPaddingBottom() - div->getVScale(cs->getAttachVScale())->getPaddingTop());
				if (recth < 1){
					recth = 1;
				}
				int rcDownX = scaleX - xsub, rcDownTop = (int)openY, rcDownBottom = (int)closeY, rcDownW = cwidth, rcDownH = (int)recth;
				if (closeY < openY){
					rcDownTop = (int)closeY;
					rcDownBottom = (int)openY;
				}
				Long downColor = FCColor_None;
				if (ciClr != -1){
					double defineColor = m_dataSource->get3(i, ciClr);
					if(!FCDataTable::isNaN(defineColor)){
						downColor = (Long)defineColor;
					}
				}
				if(downColor == FCColor_None){
                    if (open == close && cs->getMidColor() != FCColor_None)
                    {
                        downColor = cs->getMidColor();
                    }
                    else
                    {
                        downColor = cs->getDownColor();
                    }
				}
				switch (style){
					case 0:
					case 1:
					case 2:
						if ((int)highY != (int)lowY){
							drawThinLine(paint, downColor, thinLineWidth, scaleX, highY, scaleX, lowY);
							if (m_hScalePixel > 3){
								FCRect rcDown = {rcDownX, rcDownTop, rcDownX + rcDownW, rcDownBottom};
								if (style == 1){
									if (rcDownW > 0 && rcDownH > 0 && m_hScalePixel > 3){
										paint->fillRect(div->getBackColor(), rcDown);
									}
									paint->drawRect(downColor, (float)thinLineWidth, 0, rcDown);
								}
								else if (style == 0 || style == 2){
									paint->fillRect(downColor, rcDown);
									if (thinLineWidth > 1){
										paint->drawRect(downColor, (float)thinLineWidth, 0, rcDown);
									}
								}
							}
						}
						else{
							drawThinLine(paint, downColor, thinLineWidth, scaleX - xsub, closeY, scaleX + xsub, closeY);
						}
						break;
					case 5:
						double lOpen = m_dataSource->get3(i - 1, ciOpen);
						double lClose = m_dataSource->get3(i - 1, ciClose);
						double lHigh = m_dataSource->get3(i - 1, ciHigh);
						double lLow = m_dataSource->get3(i - 1, ciLow);
						int top = highY;
						int bottom = lowY;
						if ((int)highY > (int)lowY){
							top = lowY;
							bottom = highY;
						}
						if (i == 0 || FCDataTable::isNaN(lOpen) || FCDataTable::isNaN(lClose) || FCDataTable::isNaN(lHigh) || FCDataTable::isNaN(lLow)){
							if (m_hScalePixel <= 3){
								drawThinLine(paint, downColor, thinLineWidth, rcDownX, top, rcDownX, bottom);
							}
							else{
								int rcDownHeight = (int)abs(bottom - top == 0 ? 1 : bottom - top);
								if (rcDownW > 0 && rcDownHeight > 0){
									FCRect rcDown = {rcDownX, top, rcDownX + rcDownW, rcDownBottom};
									paint->fillRect(downColor,rcDown);
									if (thinLineWidth > 1){
										paint->drawRect(downColor, (float)thinLineWidth, 0, rcDown);
									}
								}
							}
						}
						else{
							if (m_hScalePixel <= 3){
								drawThinLine(paint, downColor, thinLineWidth, rcDownX, top, rcDownX, bottom);
							}
							else{
								int rcDownHeight = (int)abs(bottom - top == 0 ? 1 : bottom - top);
								if (rcDownW > 0 && rcDownHeight > 0){
									 FCRect rcDown = {rcDownX, top, rcDownX + rcDownW, rcDownBottom};
									 paint->fillRect(downColor, rcDown);
									 if (thinLineWidth > 1){
										 paint->drawRect(downColor, (float)thinLineWidth, 0, rcDown);
									 }
								}
							}
							if (lClose >= lOpen && high > lLow){
								int tx = rcDownX;
								int ty = (int)highY;
								int width = rcDownW;
								int height = (int)abs(getY(div, lLow, cs->getAttachVScale(), vmax, vmin) - ty);
								if (low > lLow){
									height = (int)lowY - ty;
								}
								if (height > 0){
									if (m_hScalePixel <= 3){
										drawThinLine(paint, cs->getUpColor(), thinLineWidth, tx, ty, tx, ty + height);
									}
									else{
										if (width > 0 && height > 0){
											FCRect rect = {tx, ty, tx + width, ty + height};
											paint->fillRect(cs->getUpColor(), rect);
											if (thinLineWidth > 1){
												paint->drawRect(cs->getUpColor(), (float)thinLineWidth, 0, rect);
											}
										}
									}
								}
							}
						}
						break;
				}
			}
			break;
		}
		if(cs->isSelected()){
			int kPInterval = m_maxVisibleRecord / 30;
			if (kPInterval < 2){
				kPInterval = 3;
			}
			if (i % kPInterval == 0){
				if (!FCDataTable::isNaN(open) && !FCDataTable::isNaN(high) && !FCDataTable::isNaN(low) && !FCDataTable::isNaN(close)){
					if (closeY >= div->getTitleBar()->getHeight()
						&& closeY <= div->getHeight() - div->getHScale()->getHeight()){
						FCRect sRect = {scaleX - 3, closeY - 4, scaleX + 4, closeY + 3};
						paint->fillRect(cs->getSelectedColor(), sRect);
					}
				}
			}
		}
	}
	onPaintCandleEx(paint, div, cs, visibleMaxIndex, visibleMax, visibleMinIndex, visibleMin);
}

void LikeChart::onPaintBar(FCPaint *paint, ChartDiv *div, BarShape *bs){
	int ciFieldName1 = m_dataSource->getColumnIndex(bs->getFieldName());
	int ciFieldName2 = m_dataSource->getColumnIndex(bs->getFieldName2());
	int ciClr = m_dataSource->getColumnIndex(bs->getColorField());
	int ciStyle = m_dataSource->getColumnIndex(bs->getStyleField());
	int defaultLineWidth = 1;
	double visibleMax = m_dataSource->NaN, visibleMin = m_dataSource->NaN;
	if(bs->fillVScale()){
		getShapeMaxMin(bs, &visibleMax, &visibleMin);
	}
    if (!isOperating() && m_crossStopIndex != -1){
        if (selectBar(div, (float)getTouchPoint().y, bs->getFieldName(), bs->getFieldName2(), bs->getStyleField(), bs->getAttachVScale(), m_crossStopIndex, visibleMax, visibleMin)){
            defaultLineWidth = 2;
        }
    }
	for (int i = m_firstVisibleIndex; i <= m_lastVisibleIndex; i++){
		int thinLineWidth = 1;
		if(m_crossStopIndex == i){
			thinLineWidth = defaultLineWidth;
		}
		int style = -10000;
		switch (bs->getStyle()){
			case BarStyle_Line:
				style = 2;
				break;
			case BarStyle_Rect:
				style = 0;
				break;
		}
		if (ciStyle != -1){
			double defineStyle = m_dataSource->get3(i, ciStyle);
			if (!FCDataTable::isNaN(defineStyle)){
				style = (int)defineStyle;
			}
		}
		if(style == -10000){
			continue;
		}
		double value = m_dataSource->get3(i, ciFieldName1); 
		int scaleX = (int)getX(i);
		double midValue = 0;
		if(ciFieldName2 != -1){
			midValue = m_dataSource->get3(i, ciFieldName2); 
		}
		double open = m_dataSource->get2(i, OPEN_INDEX); 
		double close =  m_dataSource->get2(i, CLOSE_INDEX); 
		int midY = (int)getY(div, midValue, bs->getAttachVScale(), visibleMax, visibleMin);
		if (!FCDataTable::isNaN(value)){
			float barY = getY(div, value, bs->getAttachVScale(), visibleMax, visibleMin);
			int startPX = scaleX;
			int startPY = (int)midY;
			int endPX = scaleX;
			int endPY = (int)barY;
			if (bs->getStyle() == BarStyle_Rect){
				if (startPY == div->getHeight() - div->getHScale()->getHeight()){
					startPY = div->getHeight() - div->getHScale()->getHeight() + 1;
				}
			}
			int x = 0, y = 0, width = 0, height = 0;
			width = (int)(m_hScalePixel * 2 / 3);
			if (width % 2 == 0){
				width += 1;
			}
			if (width < 3){
				width = 1;
			}
			x = scaleX - width / 2;
			if (startPY >= endPY){
				y = endPY;
			}
			else{
				y = startPY;
			}
			height = abs(startPY - endPY);
			if (height < 1){
				height = 1;
			}
			Long barColor = FCColor_None;
			if (ciClr != -1){
				double defineColor = m_dataSource->get3(i, ciClr);
				if(!FCDataTable::isNaN(defineColor)){
					barColor = (Long)defineColor;
				}
			}
			if(barColor == FCColor_None){
				if (open >= close){
					barColor = bs->getUpColor();
				}
				else{
					barColor = bs->getDownColor();
				}
			}
			switch (style){
				case -1:
					if (m_hScalePixel <= 3){
						drawThinLine(paint, barColor, thinLineWidth, startPX, y, startPX, y + height);
					}
					else{
						FCRect rect = {x, y, x + width,y + height};
						paint->fillRect(barColor, rect);
						//paint->drawRect(barColor, (float)thinLineWidth, 1, rect);
					}
					break;
				case 0:
					if (m_hScalePixel <= 3){
						drawThinLine(paint, barColor, thinLineWidth, startPX, y, startPX, y + height);
					}
					else{
						FCRect rect = {x, y, x + width,y + height};
						paint->fillRect(barColor, rect);
						if (thinLineWidth > 1){
							if (startPY >= endPY){
								paint->drawRect(bs->getDownColor(), (float)thinLineWidth, 0, rect);
							}
							else{
								paint->drawRect(bs->getUpColor(), (float)thinLineWidth, 0, rect);
							}
						}
					}
					break;
				case 1:
					if (m_hScalePixel <= 3){
						drawThinLine(paint, barColor, thinLineWidth, startPX, y, startPX, y + height);
					}
					else{
						FCRect rect = {x, y, x + width,y + height};
						paint->fillRect(barColor, rect);
					}
					break;
				case 2:
                    if (startPY <= 0){
                        startPY = 0;
                    }
                    if (startPY >= div->getHeight()){
                        startPY = div->getHeight();
                    }
                    if (endPY <= 0){
                        endPY = 0;
                    }
                    if (endPY >= div->getHeight()){
                        endPY = div->getHeight();
                    }
                    if (bs->getLineWidth() <= 1){
                        drawThinLine(paint, barColor, thinLineWidth, startPX, startPY, endPX, endPY);
                    }
                    else{
                        int lineWidth = (int)bs->getLineWidth();
                        if (lineWidth > m_hScalePixel){
                            lineWidth = (int)m_hScalePixel;
                        }
                        if (lineWidth < 1){
                            lineWidth = 1;
                        }
						paint->drawLine(barColor, (float)(lineWidth + thinLineWidth - 1), 0, startPX, startPY, endPX, endPY);
                    }
					break;
			}
			if(bs->isSelected()){
				int kPInterval = m_maxVisibleRecord / 30;
				if (kPInterval < 2){
					kPInterval = 2;
				}
				if (i % kPInterval == 0){
					if (barY >= div->getTitleBar()->getHeight()
						&& barY <= div->getHeight() - div->getHScale()->getHeight()){
						FCRect sRect = {scaleX - 3, (int)barY - 4, scaleX + 4, (int)barY + 3};
						paint->fillRect(bs->getSelectedColor(), sRect);
					}
				}
			}
		}
		if (i == m_lastVisibleIndex && div->getVScale(bs->getAttachVScale())->getVisibleMin() < 0){
			if (m_reverseHScale){
				int left = (int)(m_leftVScaleWidth + m_workingAreaWidth - (m_lastVisibleIndex - m_firstVisibleIndex + 1) * m_hScalePixel);
				paint->drawLine(bs->getDownColor(), 1, 0, m_leftVScaleWidth + m_workingAreaWidth, (int)midY, left, (int)midY);
			}
			else{
				int right = (int)(m_leftVScaleWidth + (m_lastVisibleIndex - m_firstVisibleIndex + 1) * m_hScalePixel);
				paint->drawLine(bs->getDownColor(), 1, 0, m_leftVScaleWidth, midY, right, midY);
			}
		}
	}
}

void LikeMainFrame::callEvent(String eventName, Object sender, Object invoke){
	if(eventName == FCEventID_CheckedChanged){
		onCheckedChangedEvent(sender);
	}else if(eventName == FCEventID_TextChanged){
		onTextChangedEvent(sender);
	}else if(eventName == FCEventID_SelectedTabPageChanged){
		onSelectedTabPageChangedEvent();
	}
}

void LikeMainFrame::callTouchEvent(String eventName, Object sender, FCTouchInfo touchInfo, Object invoke){
	if (touchInfo.m_firstTouch && touchInfo.m_clicks == 1){
		LikeMainFrame *mainFrame = (LikeMainFrame*)invoke;
		FCView *control = (FCView*)sender;
		if(control == mainFrame->m_divGraph){
			if(eventName == FCEventID_TouchDown){
				mainFrame->startPen();
			}else if(eventName == FCEventID_TouchMove){
				mainFrame->movePen();
			}else if(eventName == FCEventID_TouchUp){
				mainFrame->stopPen();
			}
		}else{
			String name = control->getName();
			if(name == L"btnStart"){
				start();
			}else if(name == L"btnSearch"){
				startSearch();
			}else if(name == L"btnExport"){
				exportData(true);
			}
		}
	}
}

void LikeMainFrame::callGridCellTouchEvent(String eventName, Object sender, FCGridCell *cell, FCTouchInfo touchInfo, Object invoke){
	onGridCellClickEvent(sender, cell, touchInfo);
}

void LikeMainFrame::registerEvents(FCView *control){
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
        }
		else if(checkBox){
			checkBox->setButtonBackColor(USERCOLOR51);
			checkBox->setButtonBorderColor(USERCOLOR21);
		}
		else if(button){
			button->addEvent((FCTouchEventCallBack*)this, FCEventID_Click, this);
		}
		registerEvents(subControl);
	}
}

void LikeMainFrame::callTimerEvent(String eventName, Object sender, int timerID, Object invoke){
	onTimerEvent(sender, timerID);
}

bool LikeMainFrame::callPaintEvent(String eventName, Object sender, FCPaint *paint, const FCRect& clipRect, Object invoke){
	LikeMainFrame *mainFrame = (LikeMainFrame*)invoke;
	vector<FCPoint> points = mainFrame->m_movePoints;
	int pointsSize = (int)points.size();
	if(pointsSize > 0){
		FCPoint *pts = new FCPoint[pointsSize];
		for(int i = 0; i < pointsSize; i++){
			pts[i] = points[i];
		}
		paint->drawPolyline(FCColor::rgba(248, 73, 96, 200), 5, 0, pts, pointsSize);
		int highY = 0, lowY = 0;
		for(int i = 0; i < pointsSize; i++){
			//FCRect eeRect = {points[i].x - 10, points[i].y - 10, points[i].x + 10, points[i].y + 10};
			if(i == 0){
				highY = points[i].y;
				lowY = points[i].y;
			}else{
				if(highY < points[i].y){
					highY = points[i].y;
				}
				if(lowY > points[i].y){
					lowY = points[i].y;
				}
			}
			//paint->fillEllipse(FCColor::rgb(255, 80, 80), eeRect);
		}
		if((int)mainFrame->m_graphDatas.size() > 0){
			double highValue = 0, lowValue = 0;
			for(int s = 0; s < (int)mainFrame->m_graphDatas.size(); s++){
				SecurityData *data = mainFrame->m_graphDatas[s];
				if(s == 0){
					highValue = data->m_close;
					lowValue = data->m_close;
				}else{
					if(highValue < data->m_close){
						highValue = data->m_close;
					}
					if(lowValue > data->m_close){
						lowValue = data->m_close;
					}
				}
			}
			int x = points[0].x;
			for(int s = 0; s < (int)mainFrame->m_graphDatas.size(); s++){
				SecurityData *data = mainFrame->m_graphDatas[s];
				int closeY = highY - (highY - lowY) * (abs(data->m_close - lowValue) / abs(highValue - lowValue));
				int hY =  highY - (highY - lowY) * (abs(data->m_high - lowValue) / abs(highValue - lowValue));
				int lY = highY - (highY - lowY) * (abs(data->m_low - lowValue) / abs(highValue - lowValue));
				int openY = highY - (highY - lowY) * (abs(data->m_open - lowValue) / abs(highValue - lowValue)); 
				if(data->m_close >= data->m_open){
					paint->drawLine(USERCOLOR69, 1, 0, x, hY, x, lY);
					FCRect upRect = {x - 5, closeY, x + 5, openY};
					if(abs(closeY - openY) < 1){
						upRect.bottom = upRect.top + 1;
					}
					paint->fillRect(USERCOLOR69, upRect);
				}else{
					paint->drawLine(USERCOLOR70, 1, 0, x, hY, x, lY);
					FCRect downRect = {x - 5, openY, x + 5, closeY};
					if(abs(closeY - openY) < 1){
						downRect.bottom = downRect.top + 1;
					}
					paint->fillRect(USERCOLOR70, downRect);
				}
				x += 21;
			}
		}
		delete[] pts;
		pts = 0;
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LikeMainFrame::LikeMainFrame(HWND hWnd){
	m_chartLeft = 0;
	m_chartRight = 0;
	m_chartScope = 0;
	m_divGraph = 0;
	m_host = 0;
	m_hWnd = hWnd;
	m_scaleFactor = 1;
	m_startPen = false;
	m_tableCodes = 0;
	m_tableResults = 0;
	m_timerID = FCView::getNewTimerID();
	m_txtCode = 0;
}

LikeMainFrame::~LikeMainFrame(){
	m_chartLeft = 0;
	m_chartRight = 0;
	m_chartScope = 0;
	m_host = 0;
	m_hWnd = 0;
	m_tableCodes = 0;
	m_tableResults = 0;
	m_txtCode = 0;
}

double LikeMainFrame::getScaleFactor(){
	return m_scaleFactor;
}

void LikeMainFrame::setScaleFactor(double scaleFactor){
	m_scaleFactor = scaleFactor;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void LikeMainFrame::exit(){
}

bool LikeMainFrame::isWindowShowing(){
	ArrayList<FCView*> controls = getNative()->getViews();
	for(int c = 0; c < controls.size(); c++){
        FCWindowFrame *frame = dynamic_cast<FCWindowFrame*>(controls.get(c));
        if (frame){
			return true;
		}
	}
	return false;
}

void LikeMainFrame::load(const String& xmlPath){
	m_host = dynamic_cast<WinHost*>(getNative()->getHost());
	loadFile(xmlPath, 0);
	FCView *control = getNative()->getViews().get(0);
	registerEvents(control);
	DataCenter::startService();
	ALikeService *aLikeService = DataCenter::getALikeService();
	DataCenter::setMainUI(this);
	m_tableCodes = getGrid(L"tableCodes");
	m_tableCodes->addEvent((FCGridCellTouchEventCallBack*)this, FCEventID_GridCellClick, this);
	m_tableCodes2 = getGrid(L"tableCodes2");
	m_tableCodes2->addEvent((FCGridCellTouchEventCallBack*)this, FCEventID_GridCellClick, this);
	m_tableResults = getGrid(L"tableResults");
	m_tableResults->addEvent((FCGridCellTouchEventCallBack*)this, FCEventID_GridCellClick, this);
	m_txtCode = getTextBox(L"txtCode");
	m_txtCode->addEvent((FCEventCallBack*)this, FCEventID_TextChanged, this);
	m_txtCode2 = getTextBox(L"txtCode2");
	m_txtCode2->addEvent((FCEventCallBack*)this, FCEventID_TextChanged, this);
	m_tableCodes->beginUpdate();
	if(aLikeService->m_historyDatas.size() > 0){
		map<String, SecurityHistoryData*>::iterator sIter = aLikeService->m_historyDatas.begin();
		for(; sIter != aLikeService->m_historyDatas.end(); ++sIter){
			String code = sIter->first;
			FCGridRow *row = new FCGridRowEx;
			row->setHeight(30);
			m_tableCodes->addRow(row);
			FCGridStringCell *cell = new FCGridStringCell(code);
			row->addCell(0, cell);
			FCGridCellStyle *cellStyle = new FCGridCellStyle;
			cellStyle->setTextColor(USERCOLOR3);
			row->getCell(0)->setStyle(cellStyle);
			FCGridIntCell *cell2 = new FCGridIntCell;
			row->addCell(1, cell2);
		}
	}
	m_tableCodes->endUpdate();
	m_tableCodes->invalidate();
	m_chartLeft = dynamic_cast<FCChart*>(findView(L"chartLeft"));
	m_chartRight = dynamic_cast<FCChart*>(findView(L"chartRight"));
	m_chartScope = dynamic_cast<FCChart*>(findView(L"chartScope"));
	initChart(m_chartLeft);
	initChart(m_chartRight);
	initChart(m_chartScope);
	m_tableCodes->addEvent((FCTimerEventCallBack*)this, FCEventID_Timer, this);
	FCCheckBox *cbNext = getCheckBox(L"cbNext");
	cbNext->addEvent((FCEventCallBack*)this, FCEventID_CheckedChanged, this);
	getTabView(L"tabChart")->addEvent((FCEventCallBack*)this, FCEventID_GridSelectedRowsChanged, this);

	m_divGraph = getDiv(L"divGraph");
	m_divGraph->addEvent((FCPaintEventCallBack*)this, FCEventID_PaintBorder, this);
	m_divGraph->addEvent((FCTouchEventCallBack*)this, FCEventID_TouchDown, this);
	m_divGraph->addEvent((FCTouchEventCallBack*)this, FCEventID_TouchMove, this);
	m_divGraph->addEvent((FCTouchEventCallBack*)this, FCEventID_TouchUp, this);
}

void LikeMainFrame::loadData(){
}

void LikeMainFrame::resetScaleSize(FCSize clientSize){
	FCNative *native = getNative();
	if(native){
		FCSize nativeSize = native->getSize();
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

int LikeMainFrame::showMessageBox(const String& text, const String& caption, UINT uType){
	return MessageBox(m_hWnd, text.c_str(), caption.c_str(), uType);
}

int LikeMainFrame::wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	if(m_host && m_host->onMessage(hWnd, message, wParam, lParam)){
		return 1;
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void LikeMainFrame::bindHistoryDatas(const String& code, int index){
	ALikeService *aLikeService = DataCenter::getALikeService();
	if ((int)m_likeDataInfos.size() > 0){
        if (index >= (int)m_likeDataInfos.size()){
            index = (int)m_likeDataInfos.size() - 1;
        }
        LikeDataInfo &likeDataInfo = m_likeDataInfos[index];
        SecurityHistoryData *left = aLikeService->m_historyDatas[likeDataInfo.m_leftCode];
        SecurityHistoryData *right = aLikeService->m_historyDatas[likeDataInfo.m_rightCode];
		getLabel(L"lblStock")->setText(left->m_security->m_name + L"(" + left->m_security->m_code + L"):" + right->m_security->m_name + L"(" + right->m_security->m_code + L")");
		getLabel(L"lblStock")->invalidate();
        vector<SecurityData*> leftDatas;
        vector<SecurityData*> rightDatas;
		int leftDatasSize = (int)left->m_datasSize;
		FCCheckBox *cbNext = getCheckBox(L"cbNext");
		for(int i = 0; i < leftDatasSize; i++){
			SecurityData *data = left->m_datas[i];
			if(cbNext->isChecked()){
				if (data->m_date >= likeDataInfo.m_leftStartDate){
					leftDatas.push_back(data);
				}
			}
			else{
				if (data->m_date >= likeDataInfo.m_leftStartDate && data->m_date <= likeDataInfo.m_leftStopDate){
					leftDatas.push_back(data);
				}
			}
        }
		int rightDatasSize = (int)right->m_datasSize;
        for(int i = 0; i < rightDatasSize; i++){
			SecurityData *data = right->m_datas[i];
			if(cbNext->isChecked()){
				if (data->m_date >= likeDataInfo.m_rightStartDate){
					rightDatas.push_back(data);
				}
			}
			else{
				if (data->m_date >= likeDataInfo.m_rightStartDate && data->m_date <= likeDataInfo.m_rightStopDate){
					rightDatas.push_back(data);
				}
			}
        }
		if((int)leftDatas.size() > 0 && (int)rightDatas.size() > 0){
			int fields[6];
			fields[0] = CLOSE_INDEX;
			fields[1] = HIGH_INDEX;
			fields[2] = LOW_INDEX;
			fields[3] = OPEN_INDEX;
			fields[4] = VOL_INDEX;
			fields[5] = AMOUNT_INDEX;
			vector<FCScript*> indicators;
			SecurityDataHelper::bindHistoryDatas(m_chartLeft, m_chartLeft->getDataSource(), &indicators, fields, &leftDatas);
			SecurityDataHelper::bindHistoryDatas(m_chartRight, m_chartRight->getDataSource(), &indicators, fields, &rightDatas);
			leftDatas.clear();
			rightDatas.clear();
			FCDataTable *leftDataSource = m_chartLeft->getDataSource();
			BarShape *leftBar = dynamic_cast<BarShape*>(m_chartLeft->getDivs().get(1)->getShapes(SortType_Asc).get(0));
			int rowsSize = leftDataSource->getRowsCount();
			for (int i = 0; i < rowsSize; i++){
				double volume = leftDataSource->get2(i, VOL_INDEX);
				double close = leftDataSource->get2(i, CLOSE_INDEX);
				double open = leftDataSource->get2(i, OPEN_INDEX);
				if (close >= open){
					leftDataSource->set2(i, leftBar->getStyleField(), 1);
					leftDataSource->set2(i, leftBar->getColorField(), FCColor::rgba(248, 73, 96, 150));
				}
				else{
					leftDataSource->set2(i, leftBar->getStyleField(), 0);
					leftDataSource->set2(i, leftBar->getColorField(), FCColor::rgba(15, 193, 118, 150));
				}
			}
			FCDataTable *rightDataSource = m_chartRight->getDataSource();
			BarShape *rightBar = dynamic_cast<BarShape*>(m_chartRight->getDivs().get(1)->getShapes(SortType_Asc).get(0));
			rowsSize = rightDataSource->getRowsCount();
			for (int i = 0; i < rowsSize; i++){
				double volume = rightDataSource->get2(i, VOL_INDEX);
				double close = rightDataSource->get2(i, CLOSE_INDEX);
				double open = rightDataSource->get2(i, OPEN_INDEX);
				if (close >= open){
					rightDataSource->set2(i, rightBar->getStyleField(), 1);
					rightDataSource->set2(i, rightBar->getColorField(), FCColor::rgba(248, 73, 96, 150));
				}
				else{
					rightDataSource->set2(i, rightBar->getStyleField(), 0);
					rightDataSource->set2(i, rightBar->getColorField(), FCColor::rgba(15, 193, 118, 150));
				}
			}
			m_chartLeft->update();
			m_chartRight->update();
			m_chartLeft->scrollLeftToBegin();
			m_chartRight->scrollLeftToBegin();
			m_chartLeft->update();
			m_chartRight->update();
			getNative()->invalidate();
		}
		else{
			m_chartLeft->clear();
			m_chartRight->clear();
			m_chartLeft->update();
			m_chartRight->update();
			getNative()->invalidate();
		}
    }
	else{
		m_chartLeft->clear();
		m_chartRight->clear();
		m_chartLeft->update();
		m_chartRight->update();
		getNative()->invalidate();
	}
}

void LikeMainFrame::bindResultTable(const String& code){
	ALikeService *aLikeService = DataCenter::getALikeService();
	m_tableResults->clearRows();
	m_tableResults->beginUpdate();
	int score = 0;
	vector<LikeDataInfo>::iterator sIter = m_likeDataInfos.begin();
	int count = 0;
	for(; sIter != m_likeDataInfos.end(); ++sIter){
		LikeDataInfo &likeDataInfo = *sIter;
		FCGridRow *row = new FCGridRowEx;
		row->setHeight(30);
		m_tableResults->addRow(row);
		FCGridIntCell *cell = new FCGridIntCell();
		cell->setInt((int)likeDataInfo.m_score);
		row->addCell(0, cell);
		FCGridCellStyle *cellStyle1 = new FCGridCellStyle;
		if((int)likeDataInfo.m_score > aLikeService->getMaxScore()){
			cellStyle1->setTextColor(USERCOLOR69);
		}
		else{
			cellStyle1->setTextColor(USERCOLOR70);
		}
		cell->getRow()->getCell(0)->setStyle(cellStyle1);
		FCGridStringCell *cell2 = new FCGridStringCell(likeDataInfo.m_rightCode);
		row->addCell(1, cell2);
		FCGridCellStyle *cellStyle2 = new FCGridCellStyle;
		cellStyle2->setTextColor(USERCOLOR3);
		row->getCell(1)->setStyle(cellStyle2);
		count++;
		if(count > 10){
			break;
		}
	}
	if((int)m_likeDataInfos.size() > 0){
		score = m_likeDataInfos[0].m_score;
	}
	m_tableResults->endUpdate();
	ArrayList<FCGridRow*> selectedRows;
	if((int)m_tableResults->m_rows.size() > 0){
		selectedRows.add(m_tableResults->m_rows.get(0));
	}
	m_tableResults->setSelectedRows(selectedRows);
	m_tableResults->invalidate();
}

void LikeMainFrame::bindSandBoxTable(vector<LikeDataInfo> *likeDataInfos){
	m_tableCodes2->clearRows();
	m_tableCodes2->beginUpdate();
	vector<LikeDataInfo>::iterator sIter = likeDataInfos->begin();
	int count = 0;
	for(; sIter != likeDataInfos->end(); ++sIter){
		LikeDataInfo &likeDataInfo = *sIter;
		FCGridRow *row = new FCGridRowEx;
		row->setHeight(30);
		m_tableCodes2->addRow(row);
		FCGridStringCell *cell = new FCGridStringCell(likeDataInfo.m_rightCode);
		row->addCell(0, cell);
		FCGridDoubleCell *cell2 = new FCGridDoubleCell(likeDataInfo.m_diffRange);
		row->addCell(1, cell2);
		FCGridDoubleCell *cell3 = new FCGridDoubleCell(likeDataInfo.m_rightStartDate);
		row->addCell(2, cell3);
		FCGridDoubleCell *cell4 = new FCGridDoubleCell(likeDataInfo.m_rightStopDate);
		row->addCell(3, cell4);
	}
	m_tableCodes2->endUpdate();
	ArrayList<FCGridRow*> selectedRows;
	if((int)m_tableCodes2->m_rows.size() > 0){
		selectedRows.add(m_tableCodes2->m_rows.get(0));
	}
	m_tableCodes2->setSelectedRows(selectedRows);
	m_tableCodes2->invalidate();
}

String LikeMainFrame::exportData(bool writeFile){
	String code;
	FCTabView *tabChart = getTabView(L"tabChart");
	if(tabChart->getSelectedIndex() == 1){
		ArrayList<FCGridRow*> selectedRows = m_tableCodes->getSelectedRows();
		int selectedRowsSize = (int)selectedRows.size();
		if(selectedRowsSize > 0){
			code = selectedRows.get(0)->getCell(0)->getText();
		}
	}else{
		ArrayList<FCGridRow*> selectedRows = m_tableResults->getSelectedRows();
		int selectedRowsSize = (int)selectedRows.size();
		if(selectedRowsSize > 0){
			code = selectedRows.get(0)->getCell(1)->getText();
		}
	}
	if((int)code.length() > 0){
		FCChart *chart = 0;
		FCTabView *tabChart = getTabView(L"tabChart");
		int sIndex = -1, eIndex = -1;
		if(tabChart->getSelectedIndex() == 1){
			chart = m_chartScope;
			ArrayList<ChartDiv*> divs = chart->getDivs();
			ChartDiv *div = divs.get(0);
			SelectArea *selectArea = div->getSelectArea();
			if(selectArea->isVisible()){
				FCRect bounds = selectArea->getBounds();
				FCPoint sPoint ={bounds.left, bounds.top};
				sIndex = chart->getIndex(sPoint);
				FCPoint ePoint ={bounds.right, bounds.top};
				eIndex = chart->getIndex(ePoint);
			}
		}else{
			chart = m_chartRight;
			ArrayList<ChartDiv*> divs = chart->getDivs();
			ChartDiv *div = divs.get(0);
			SelectArea *selectArea = div->getSelectArea();
			if(selectArea->isVisible()){
				FCRect bounds = selectArea->getBounds();
				FCPoint sPoint ={bounds.left, bounds.top};
				sIndex = chart->getIndex(sPoint);
				FCPoint ePoint ={bounds.right, bounds.top};
				eIndex = chart->getIndex(ePoint);
			}
		}
		if(sIndex != -1 && eIndex != -1 && eIndex > sIndex){
			FCDataTable *dataSource = chart->getDataSource();
			ALikeService *aLikeService = DataCenter::getALikeService();
			String name = aLikeService->m_securities[code]->m_name;
			String strOutput = code + L"," + name + L"\r\n";
			for(int i = sIndex; i <= eIndex; i++){
				double close = dataSource->get2(i, CLOSE_INDEX);
				double high = dataSource->get2(i, HIGH_INDEX);
				double low = dataSource->get2(i, LOW_INDEX);
				double open = dataSource->get2(i, OPEN_INDEX);
				double date = dataSource->getXValue(i);
				double amount = dataSource->get2(i, VOL_INDEX);
				double vol = dataSource->get2(i, AMOUNT_INDEX);
				wchar_t szValue[1024] = {0};
				_stprintf_s(szValue, 1023, L"%f,%f,%f,%f,%f,%f,%f\r\n", date, close, high, low, open, amount, vol);
				strOutput += szValue;
			}
			strOutput += L"[END]\r\n";
			if(writeFile){
				String appPath = FCTran::stringToString(FCTran::getAppPath());
				FCFile::append(appPath + L"\\K线数据.txt", strOutput);
			}
			return strOutput;
		}
	}
	return L"";
}

void LikeMainFrame::initChart(FCChart *chart){
	FCDataTable *dataSource = chart->getDataSource();
	chart->setCanMoveShape(true);
	chart->setScrollAddSpeed(true);
	chart->setLeftVScaleWidth(85);
	chart->setRightVScaleWidth(85);
	chart->setHScalePixel(10);
	chart->setHScaleFieldText(L"日期");
	ChartDiv *candleDiv = chart->getDivs().get(0);
	candleDiv->getTitleBar()->setText(L"日线");
	candleDiv->getVGrid()->setVisible(true);
	candleDiv->getLeftVScale()->setPaddingTop(2);
	candleDiv->getLeftVScale()->setPaddingBottom(2);
	FCFont vFont(L"Default", 14, false, false, false);
	candleDiv->getLeftVScale()->setFont(&vFont);
	candleDiv->getRightVScale()->setFont(&vFont);
	candleDiv->getRightVScale()->setPaddingTop(2);
    candleDiv->getRightVScale()->setPaddingBottom(2);
    candleDiv->getTitleBar()->m_titles.add( new ChartTitle(CLOSE_INDEX, L"CLOSE", USERCOLOR67, 0, true));
	candleDiv->getTitleBar()->m_titles.add( new ChartTitle(CLOSE_INDEX, L"HIGH", USERCOLOR67, 0, true));
	candleDiv->getTitleBar()->m_titles.add( new ChartTitle(CLOSE_INDEX, L"LOW", USERCOLOR67, 0, true));
	candleDiv->getTitleBar()->m_titles.add( new ChartTitle(CLOSE_INDEX, L"OPEN", USERCOLOR67, 0, true));
	CandleShape *candle = new CandleShape;
	candleDiv->addShape(candle);
	candleDiv->setBackColor(FCColor_None);
	candle->setCloseField(CLOSE_INDEX);
	candle->setOpenField(OPEN_INDEX);
	candle->setHighField(HIGH_INDEX);
	candle->setLowField(LOW_INDEX);
	candle->setCloseFieldText(L"收盘");
	candle->setHighFieldText(L"最高");
	candle->setLowFieldText(L"最低");
	candle->setOpenFieldText(L"开盘");
	candle->setUpColor(USERCOLOR69);
	candle->setDownColor(USERCOLOR70);

	ChartDiv *volumeDiv = chart->getDivs().get(1);
	volumeDiv->setBackColor(FCColor_None);
	volumeDiv->getVGrid()->setDistance(30);
	volumeDiv->getLeftVScale()->setDigit(0);
	volumeDiv->getLeftVScale()->setFont(&vFont);
	volumeDiv->getRightVScale()->setDigit(0);
	volumeDiv->getRightVScale()->setFont(&vFont);
	BarShape *bar = new BarShape;
	int styleField = dataSource->AUTOFIELD();
	int colorField = dataSource->AUTOFIELD();
	bar->setColorField(colorField);
	bar->setStyleField(styleField);
	bar->setFieldName(VOL_INDEX);
	bar->setFieldText(VOL);
	volumeDiv->addShape(bar);
	volumeDiv->getTitleBar()->setText(L"成交量");
	candleDiv->getTitleBar()->setTextColor(USERCOLOR67);
	volumeDiv->getTitleBar()->setTextColor(USERCOLOR67);
	ChartTitle *barTitle = new ChartTitle(VOL_INDEX, L"成交量", USERCOLOR67, 0, true);
	barTitle->setFieldTextMode(TextMode_Value);
	volumeDiv->getTitleBar()->m_titles.add(barTitle);
	candleDiv->getHScale()->setVisible(false);
	candleDiv->getHScale()->setHeight(0);
	volumeDiv->getHScale()->setVisible(true);
	volumeDiv->getHScale()->setHeight(22);
	volumeDiv->getLeftVScale()->setTextColor(USERCOLOR67);
	volumeDiv->getRightVScale()->setTextColor(USERCOLOR67);
	dataSource->addColumn(CLOSE_INDEX);
	dataSource->addColumn(OPEN_INDEX);
	dataSource->addColumn(HIGH_INDEX);
	dataSource->addColumn(LOW_INDEX);
	dataSource->addColumn(VOL_INDEX);
	dataSource->addColumn(AMOUNT_INDEX);
	dataSource->addColumn(colorField);
	dataSource->addColumn(styleField);
	dataSource->setColsCapacity(16);
	dataSource->setColsGrowStep(4);

	candleDiv->getLeftVScale()->setTextColor(USERCOLOR67);
    volumeDiv->getLeftVScale()->setTextColor(USERCOLOR67);
    candleDiv->getLeftVScale()->getCrossLineTip()->setBackColor(USERCOLOR8);
    volumeDiv->getLeftVScale()->getCrossLineTip()->setBackColor(USERCOLOR8);
	candleDiv->getLeftVScale()->setScaleColor(USERCOLOR8);
    volumeDiv->getLeftVScale()->setScaleColor(USERCOLOR8);

	candleDiv->getRightVScale()->setTextColor(USERCOLOR67);
    volumeDiv->getRightVScale()->setTextColor(USERCOLOR67);
    candleDiv->getRightVScale()->getCrossLineTip()->setBackColor(USERCOLOR8);
    volumeDiv->getRightVScale()->getCrossLineTip()->setBackColor(USERCOLOR8);
	candleDiv->getRightVScale()->setScaleColor(USERCOLOR8);
    volumeDiv->getRightVScale()->setScaleColor(USERCOLOR8);

    candleDiv->getHScale()->getCrossLineTip()->setBackColor(USERCOLOR8);
    volumeDiv->getHScale()->getCrossLineTip()->setBackColor(USERCOLOR8);

    candleDiv->getHScale()->setScaleColor(USERCOLOR8);
    volumeDiv->getHScale()->setScaleColor(USERCOLOR8);
    candleDiv->getHGrid()->setGridColor(USERCOLOR8);
    volumeDiv->getHGrid()->setGridColor(USERCOLOR8);
	candleDiv->getVGrid()->setVisible(false);
    volumeDiv->getVGrid()->setVisible(false);
    candleDiv->getTitleBar()->setUnderLineColor(USERCOLOR8);
    volumeDiv->getTitleBar()->setUnderLineColor(USERCOLOR8);
    volumeDiv->getHScale()->setTextColor(USERCOLOR67);

	volumeDiv->getHScale()->m_dateColors.put(DateType_Year, USERCOLOR67);
    volumeDiv->getHScale()->m_dateColors.put(DateType_Month, USERCOLOR67);
    volumeDiv->getHScale()->m_dateColors.put(DateType_Day, USERCOLOR67);
    volumeDiv->getHScale()->m_dateColors.put(DateType_Hour, USERCOLOR67);
    volumeDiv->getHScale()->m_dateColors.put(DateType_Minute, USERCOLOR67);
    volumeDiv->getHScale()->m_dateColors.put(DateType_Second, USERCOLOR67);
    volumeDiv->getHScale()->m_dateColors.put(DateType_Millisecond, USERCOLOR67);
	volumeDiv->getVGrid()->setDistance(20);

}

void LikeMainFrame::onCheckedChangedEvent(void *sender){
	ArrayList<FCGridRow*> selectedRows = m_tableCodes->getSelectedRows();
	int selectedRowsSize = (int)selectedRows.size();
	if(selectedRowsSize > 0){
		String code = selectedRows.get(0)->getCell(0)->getText();
		ArrayList<FCGridRow*> selectedRows2 = m_tableResults->getSelectedRows();
		int index = 0;
		if((int)selectedRows2.size() > 0){
			index = selectedRows2.get(0)->getIndex();
		}
		bindHistoryDatas(code, index);
	}
}

void LikeMainFrame::onGridCellClickEvent(void *sender, FCGridCell *cell, FCTouchInfo touchInfo){
	ALikeService *aLikeService = DataCenter::getALikeService();
	if(aLikeService->isCompleted()){
		if(cell->getGrid() == m_tableCodes){
			String code = cell->getRow()->getCell(0)->getText();
			if(getTabView(L"tabChart")->getSelectedIndex() == 0){
				FCSpin *spinN = getSpin(L"spinN");
				FCSpin *spinM = getSpin(L"spinM");
				aLikeService->setN((int)spinN->getValue());
				aLikeService->setM((int)spinM->getValue());
				aLikeService->m_historyDatas[code]->m_startIndex = -1;
				aLikeService->start(code, &m_likeDataInfos);
				bindHistoryDatas(code, 0);
				bindResultTable(code);
				FCGridCellStyle *cellStyle = new FCGridCellStyle;
				int score = 0;
				if ((int)m_likeDataInfos.size() > 0){
					score = m_likeDataInfos[0].m_score;
				}
				if(score > aLikeService->getMaxScore()){
					cellStyle->setTextColor(USERCOLOR69);
				}
				else{
					cellStyle->setTextColor(USERCOLOR70);
				}
				cell->getRow()->getCell(1)->setStyle(cellStyle);
				cell->getRow()->getCell(1)->setInt(score);
			}
			m_chartScope->clear();
			m_chartScope->update();
			int fields[6];
			fields[0] = CLOSE_INDEX;
			fields[1] = HIGH_INDEX;
			fields[2] = LOW_INDEX;
			fields[3] = OPEN_INDEX;
			fields[4] = VOL_INDEX;
			fields[5] = AMOUNT_INDEX;
			vector<SecurityData*> historyDatas;
			int historyDatasSize = (int)aLikeService->m_historyDatas[code]->m_datasSize;
			for(int i = 0; i < historyDatasSize; i++){
				historyDatas.push_back(aLikeService->m_historyDatas[code]->m_datas[i]);
			}
			vector<FCScript*> indicators;
			SecurityDataHelper::bindHistoryDatas(m_chartScope, m_chartScope->getDataSource(), &indicators, fields, &historyDatas);
			FCDataTable *dataSource = m_chartScope->getDataSource();
			BarShape *scopeBar = dynamic_cast<BarShape*>(m_chartScope->getDivs().get(1)->getShapes(SortType_Asc).get(0));
			int rowsSize = dataSource->getRowsCount();
			for (int i = 0; i < rowsSize; i++){
				double volume = dataSource->get2(i, VOL_INDEX);
				double close = dataSource->get2(i, CLOSE_INDEX);
				double open = dataSource->get2(i, OPEN_INDEX);
				if (close >= open){
					dataSource->set2(i, scopeBar->getStyleField(), 1);
					dataSource->set2(i, scopeBar->getColorField(), FCColor::rgba(248, 73, 96, 150));
				}
				else{
					dataSource->set2(i, scopeBar->getStyleField(), 0);
					dataSource->set2(i, scopeBar->getColorField(), FCColor::rgba(15, 193, 118, 150));
				}
			}
			m_chartScope->update();
			m_chartScope->invalidate();
		}
		else if(cell->getGrid() == m_tableCodes2){
			String code = cell->getRow()->getCell(0)->getText();
			double startDate = cell->getRow()->getCell(2)->getDouble();
			double endDate = cell->getRow()->getCell(3)->getDouble();
			m_chartScope->clear();
			m_chartScope->update();
			int fields[6];
			fields[0] = CLOSE_INDEX;
			fields[1] = HIGH_INDEX;
			fields[2] = LOW_INDEX;
			fields[3] = OPEN_INDEX;
			fields[4] = VOL_INDEX;
			fields[5] = AMOUNT_INDEX;
			vector<SecurityData*> historyDatas;
			int historyDatasSize = (int)aLikeService->m_historyDatas[code]->m_datasSize;
			for(int i = 0; i < historyDatasSize; i++){
				SecurityData *securityData = aLikeService->m_historyDatas[code]->m_datas[i];
				if(securityData->m_date >= startDate && securityData->m_date <= endDate){
					historyDatas.push_back(securityData);
				}
			}
			vector<FCScript*> indicators;
			SecurityDataHelper::bindHistoryDatas(m_chartScope, m_chartScope->getDataSource(), &indicators, fields, &historyDatas);
			FCDataTable *dataSource = m_chartScope->getDataSource();
			BarShape *scopeBar = dynamic_cast<BarShape*>(m_chartScope->getDivs().get(1)->getShapes(SortType_Asc).get(0));
			int rowsSize = dataSource->getRowsCount();
			for (int i = 0; i < rowsSize; i++){
				double volume = dataSource->get2(i, VOL_INDEX);
				double close = dataSource->get2(i, CLOSE_INDEX);
				double open = dataSource->get2(i, OPEN_INDEX);
				if (close >= open){
					dataSource->set2(i, scopeBar->getStyleField(), 1);
					dataSource->set2(i, scopeBar->getColorField(), FCColor::rgba(248, 73, 96, 150));
				}
				else{
					dataSource->set2(i, scopeBar->getStyleField(), 0);
					dataSource->set2(i, scopeBar->getColorField(), FCColor::rgba(15, 193, 118, 150));
				}
			}
			m_chartScope->update();
			m_chartScope->invalidate();
		}
		else if(cell->getGrid() == m_tableResults){
			bindHistoryDatas(m_tableCodes->getSelectedRows().get(0)->getCell(0)->getText(), cell->getRow()->getIndex());
		}
	}
}

void LikeMainFrame::onSelectedTabPageChangedEvent(){
	if(getTabView(L"tabChart")->getSelectedIndex() == 0){
		ArrayList<ChartDiv*> divs = m_chartScope->getDivs();
		for(int c = 0; c < divs.size(); c++){
			ChartDiv *div = divs.get(c);
			SelectArea *selectArea = div->getSelectArea();
			if(selectArea->isVisible()){
				FCGrid *selectedGrid = m_tableCodes;
				if(getTabView(L"tabCodes")->getSelectedIndex() == 1){
					selectedGrid = m_tableCodes2;
				}
				ArrayList<FCGridRow*> selectedRows = selectedGrid->getSelectedRows();
				int selectedRowsSize = (int)selectedRows.size();
				if(selectedRowsSize > 0){
					String code = selectedRows.get(0)->getCell(0)->getText();
					ALikeService *aLikeService = DataCenter::getALikeService();
					FCRect bounds = selectArea->getBounds();
					FCPoint sPoint ={bounds.left, bounds.top};
					int sIndex = m_chartScope->getIndex(sPoint);
					FCPoint ePoint ={bounds.right, bounds.top};
					int eIndex = m_chartScope->getIndex(ePoint);
					if(eIndex > sIndex){
						double startDate = m_chartScope->getDataSource()->getXValue(sIndex);
						int startIndex = 0;
						int historyDatasSize = (int)aLikeService->m_historyDatas[code]->m_datasSize;
						for(startIndex = 0; startIndex < historyDatasSize; startIndex++){
							SecurityData *securityData = aLikeService->m_historyDatas[code]->m_datas[startIndex];
							if(securityData->m_date >= startDate){
								break;
							}
						}
						aLikeService->m_historyDatas[code]->m_startIndex = startIndex;
						aLikeService->setM(eIndex - sIndex + 1);
						aLikeService->start(code, &m_likeDataInfos);
						bindHistoryDatas(code, 0);
						bindResultTable(code);
					}
				}
				break;
			}
		}
	}
}

void LikeMainFrame::onTextChangedEvent(void *sender){
	if(sender == m_txtCode){
		String text = m_txtCode->getText();
		ArrayList<FCGridRow*> rows = m_tableCodes->m_rows;
		for(int r = 0; r < rows.size(); r++){
			FCGridRow *row = rows.get(r);
			String cellText = row->getCell(0)->getText();
			if((int)cellText.length() == 0 || (int)cellText.find(text) == 0){
				row->setVisible(true);
			}
			else{
				row->setVisible(false);
			}
		}
		m_tableCodes->update();
		m_tableCodes->invalidate();
	}
	else if(sender == m_txtCode2){
		String text = m_txtCode2->getText();
		ArrayList<FCGridRow*> rows = m_tableCodes2->m_rows;
		for(int r = 0; r < rows.size(); r++){
			FCGridRow *row = rows.get(r);
			String cellText = row->getCell(0)->getText();
			if((int)cellText.length() == 0 || (int)cellText.find(text) == 0){
				row->setVisible(true);
			}
			else{
				row->setVisible(false);
			}
		}
		m_tableCodes2->update();
		m_tableCodes2->invalidate();
	}
}

void LikeMainFrame::onTimerEvent(void *sender, int timerID){
	ALikeService *aLikeService = DataCenter::getALikeService();
	FCButton *btnStart = getButton(L"btnStart");
	if(aLikeService->getCurCount() > 0){
		wchar_t sz[1024] ={0};
		_stprintf_s(sz, 1023, L"%d/%d", aLikeService->getCurCount(), (int)aLikeService->m_historyDatas.size());
		btnStart->setText(sz);
		btnStart->invalidate();
	}
	else if(aLikeService->getCurCount() == -1){
		ArrayList<FCGridRow*> rows = m_tableCodes->m_rows;
		for(int r = 0; r < rows.size(); r++){
			FCGridRow *row = rows.get(r);
			String code = row->getCell(0)->getText();
			int score = 0;
			aLikeService->getData(code, &m_likeDataInfos);
			if(m_likeDataInfos.size() > 0){
				score = m_likeDataInfos[0].m_score;
			}
			FCGridCellStyle *cellStyle = new FCGridCellStyle;
			if(score > aLikeService->getMaxScore()){
				cellStyle->setTextColor(USERCOLOR37);
			}
			else{
				cellStyle->setTextColor(USERCOLOR97);
			}
			row->getCell(1)->setStyle(cellStyle);
			row->getCell(1)->setInt(score);
		}
		btnStart->setText(L"全面相似对比");
		getNative()->invalidate();
		m_tableCodes->stopTimer(m_timerID);
	}
}

void LikeMainFrame::start(){
	ALikeService *aLikeService = DataCenter::getALikeService();
	if(aLikeService->isCompleted()){
		getTabView(L"tabCodes")->setSelectedIndex(0);
		FCSpin *spinN = getSpin(L"spinN");
		FCSpin *spinM = getSpin(L"spinM");
		aLikeService->setN((int)spinN->getValue());
		aLikeService->setM((int)spinM->getValue());
		FCSpin *spinThreads = getSpin(L"spinThreads");
		aLikeService->setThreads((int)spinThreads->getValue());
		aLikeService->start();
		m_tableCodes->startTimer(m_timerID, 1000);
	}
}

void LikeMainFrame::startSearch(){
	ALikeService *aLikeService = DataCenter::getALikeService();
	if(aLikeService->isCompleted()){
		getTabView(L"tabChart")->setSelectedIndex(1);
		getTabView(L"tabCodes")->setSelectedIndex(1);
		FCSpin *spinN = getSpin(L"spinN");
		FCSpin *spinM = getSpin(L"spinM");
		FCSpin *spinRangeMax = getSpin(L"spinRangeMax");
		FCSpin *spinRangeMin = getSpin(L"spinRangeMin");
		FCSpin *spinSwingDown = getSpin(L"spinSwingDown");
		FCSpin *spinSwingUp = getSpin(L"spinSwingUp");
		aLikeService->setN((int)spinN->getValue());
		aLikeService->setM((int)spinM->getValue());
		FCSpin *spinThreads = getSpin(L"spinThreads");
		aLikeService->setThreads((int)spinThreads->getValue());
		aLikeService->sandBoxInfo->m_rangeMax = spinRangeMax->getValue() / 100;
		aLikeService->sandBoxInfo->m_rangeMin = spinRangeMin->getValue() / 100;
		aLikeService->sandBoxInfo->m_swingDown = spinSwingDown->getValue() / 100;
		aLikeService->sandBoxInfo->m_swingUp = spinSwingUp->getValue() / 100;
		aLikeService->startSandBox((int)spinM->getValue(), &m_likeDataInfos);
		bindSandBoxTable(&m_likeDataInfos);
	}
}

void LikeMainFrame::startPen(){
	m_startPen = true;
	m_movePoints.clear();
	m_graphDatas.clear();
	FCPoint mp = m_divGraph->getTouchPoint();
	m_movePoints.push_back(mp);
	m_divGraph->invalidate();
}

void LikeMainFrame::movePen(){
	FCPoint mp = m_divGraph->getTouchPoint();
	m_movePoints.push_back(mp);
	m_divGraph->invalidate();
}

void LikeMainFrame::stopPen(){
	m_startPen = false;
	FCPoint mp = m_divGraph->getTouchPoint();
	m_movePoints.push_back(mp);
	int movePointsSize = (int)m_movePoints.size();
	int highY = 0, lowY = 0, leftX = 0, rightX = 0;
	for(int i = 0; i < movePointsSize; i++){
		if(i == 0){
			highY = m_movePoints[i].y;
			lowY = m_movePoints[i].y;
			leftX = m_movePoints[i].x;
		}
		if(highY < m_movePoints[i].y){
			highY = m_movePoints[i].y;
		}
		if(lowY > m_movePoints[i].y){
			lowY = m_movePoints[i].y;
		}
		if(i == movePointsSize - 1){
			rightX = m_movePoints[i].x;
		}
	}
	vector<FCPoint> points2;
	
	FCPoint lastPoint = {0};
	for(int x = leftX; x <= rightX; x += 21){
		if(x == leftX){
			FCPoint newPoint = {x, m_movePoints[0].y};
			points2.push_back(newPoint);
			lastPoint = newPoint;
		}else{
			for(int i = 1; i < movePointsSize; i++){
				if(x >= m_movePoints[i - 1].x && x <= m_movePoints[i].x){
					float k = 0, b = 0;
					FCPlot::lineXY(m_movePoints[i - 1].x, m_movePoints[i - 1].y, m_movePoints[i].x, m_movePoints[i].y, 0, 0, &k, &b);
					int newY = k * x + b;
					FCPoint newPoint = {x, newY};
					points2.push_back(newPoint);
					lastPoint = newPoint;
					break;
				}
			}
		}
	}
	FCPoint *pointsCopy = new FCPoint[(int)points2.size()];
	for(int i = 0; i < (int)points2.size(); i++){
		pointsCopy[i] = points2[i];
	}
	String minCode;
	int minStart = -1, minEnd = -1;
	DataCenter::getALikeService()->checkGraph(pointsCopy, (int)points2.size(), highY, lowY, &minCode, &minStart, &minEnd);
	if((int)minCode.length() > 0){
		map<String, SecurityHistoryData*>::iterator sIter = DataCenter::getALikeService()->m_historyDatas.find(minCode);
		SecurityHistoryData *historyData = sIter->second;
		for(int i = minStart; i <= minEnd; i++){
			m_graphDatas.push_back(historyData->m_datas[i]);
		}
	}
	delete[] pointsCopy;
	pointsCopy = 0;
	m_divGraph->invalidate();
}