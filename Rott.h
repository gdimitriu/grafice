#if !defined(AFX_ROTT_H__B8146E46_F140_4C2C_B0BD_65524B353771__INCLUDED_)
#define AFX_ROTT_H__B8146E46_F140_4C2C_B0BD_65524B353771__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Rott.h : header file
//
/*
	Copyright 2003 Gabriel Dimitriu

	This file is part of grafice.
	This file is definition of rotation of triangle.

    Grafice is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    Grafice is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with grafice; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  
*/
/////////////////////////////////////////////////////////////////////////////
// Rott dialog

class Rott : public CDialog
{
// Construction
public:
	Rott(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Rott)
	enum { IDD = IDD_ROTT };
	double	m_Raza;
	double	m_Rotatii;
	double	m_Pas;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Rott)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Rott)
	afx_msg void OnRun();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	long round(double x);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROTT_H__B8146E46_F140_4C2C_B0BD_65524B353771__INCLUDED_)
