// Rott.cpp : implementation file
//
/*
	Copyright 2003 Gabriel Dimitriu

	This file is part of grafice.
	This file is implementation of rotation of triangle.

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

#include "stdafx.h"
#include "grafice.h"
#include<math.h>
#include "Rott.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Rott dialog


Rott::Rott(CWnd* pParent /*=NULL*/)
	: CDialog(Rott::IDD, pParent)
{
	//{{AFX_DATA_INIT(Rott)
	m_Raza = 0.0;
	m_Rotatii = 0.0;
	m_Pas = 0.0;
	//}}AFX_DATA_INIT
}


void Rott::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Rott)
	DDX_Text(pDX, IDC_RAZA, m_Raza);
	DDX_Text(pDX, IDC_ROTATII, m_Rotatii);
	DDX_Text(pDX, IDC_PAS, m_Pas);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Rott, CDialog)
	//{{AFX_MSG_MAP(Rott)
	ON_BN_CLICKED(IDC_RUN, OnRun)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Rott message handlers

void Rott::OnRun() 
{
	// TODO: Add your control notification handler code here
	double x0,y0,x1,y1,x2,y2,x3,y3,f,fi,x1r,y1r,x2r,y2r,x3r,y3r;
	int i;
	CClientDC dc(this);
	UpdateData(TRUE);
	x0=300;
	y0=300;
	f=3.14/180.0;
	//coordonatele triunghiului initial
	x1=x0+m_Raza; y1=y0;
	x2=x0-m_Raza/2.0; y2=y0+sqrt(3.0)*m_Raza/2.0;
	x3=x2;	y3=y0-sqrt(3.0)*m_Raza/2.0;
	for(i=0;i<m_Rotatii;i++)
	{
		fi=f*m_Pas*i;
		//coordonatele triunghiului curent
		x1r=x0+(x1-x0)*cos(fi)-(y1-y0)*sin(fi);
		y1r=y0+(x1-x0)*sin(fi)+(y1-y0)*cos(fi);
		x2r=x0+(x2-x0)*cos(fi)-(y2-y0)*sin(fi);
		y2r=y0+(x2-x0)*sin(fi)+(y2-y0)*cos(fi);
		x3r=x0+(x3-x0)*cos(fi)-(y3-y0)*sin(fi);
		y3r=y0+(x3-x0)*sin(fi)+(y3-y0)*cos(fi);
		dc.MoveTo(round(x1r),round(y1r));
		dc.LineTo(round(x2r),round(y2r));
		dc.LineTo(round(x3r),round(y3r));
		dc.LineTo(round(x1r),round(y1r));
	}
}

long Rott::round(double x)
{
	double temp;
	temp=fabs(x-floor(x));
	if(temp<0.5) return floor(x);
	else return ceil(x);
}
