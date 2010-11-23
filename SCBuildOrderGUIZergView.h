// SCBuildOrderGUIView.h : interface of the CSCBuildOrderGUIZergView class
//

#pragma once

#include <vector>

#include "SCBuildOrderGUIView.h"
#include "SCBuildOrderGUIDoc.h"
#include "ZergTarget.h"
#include "ZergStateDlg.h"
#include "SettingsDlg.h"

#include "NumberFormat.h"

class CSCBuildOrderGUIZergView : public CSCBuildOrderGUIView
{
protected: // create from serialization only
	CSCBuildOrderGUIZergView();
	DECLARE_DYNCREATE(CSCBuildOrderGUIZergView)

// Attributes
public:
	CSCBuildOrderGUIDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
public:
	virtual ~CSCBuildOrderGUIZergView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

protected:
	CZergEngine *m_zergEngine;

	virtual void StartEngine();
	virtual void StopEngine();

	CVector<EZergCommand> m_bestBuildOrder;
	CVector<CZergStateDlg *> m_waypointDlgs;

	virtual void AddTargetDlg();
	virtual void SetTargetDlgPositions(const CRect &rect);

	virtual const CEngine *GetEngine() const { return m_zergEngine; }
	virtual bool UpdateBestBuildOrder();
	virtual CDialog *GetTargetDlg(int index) { return m_waypointDlgs[index]; }
};

#ifndef _DEBUG  // debug version in SCBuildOrderGUIViewView.cpp
inline CSCBuildOrderGUIDoc* CSCBuildOrderGUIZergView::GetDocument() const
   { return reinterpret_cast<CSCBuildOrderGUIDoc*>(m_pDocument); }
#endif

