#if !defined(AFX_POL_H__BBCA4139_9B51_4B26_9B6E_9A895D644FA5__INCLUDED_)
#define AFX_POL_H__BBCA4139_9B51_4B26_9B6E_9A895D644FA5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// POL.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// POL dialog
/*
	Copyright 2003 Gabriel Dimitriu

	This file is part of grafice.
	This file is definition of rotation of a ploygon.

    Grafice is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    Grafice is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Dgrafice; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  
*/
class POL : public CDialog
{
// Construction
public:
	POL(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(POL)
	enum { IDD = IDD_POL };
	double	m_Pas;
	double	m_Raza;
	double	m_Lmin;
	long	m_Nr;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(POL)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(POL)
	afx_msg void OnRun();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void FIG(double xa,double ya,double xb,double yb,double xc,double yc,CClientDC *dc);
	void LAT(double xa,double ya,double xb,double yb,double *x1,double *y1);
	long round(double x);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POL_H__BBCA4139_9B51_4B26_9B6E_9A895D644FA5__INCLUDED_)
