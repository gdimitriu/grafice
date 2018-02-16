// POL.cpp : implementation file
//
/*
	Copyright 2003 Gabriel Dimitriu

	This file is part of grafice.
	This file is implementation of rotation of a ploygon.

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
#include "POL.h"
#include<math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// POL dialog


POL::POL(CWnd* pParent /*=NULL*/)
	: CDialog(POL::IDD, pParent)
{
	//{{AFX_DATA_INIT(POL)
	m_Pas = 0.0;
	m_Raza = 0.0;
	m_Lmin = 0.0;
	m_Nr = 0;
	//}}AFX_DATA_INIT
}


void POL::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(POL)
	DDX_Text(pDX, IDC_PAS, m_Pas);
	DDX_Text(pDX, IDC_RAZA, m_Raza);
	DDX_Text(pDX, IDC_LUNGIME, m_Lmin);
	DDX_Text(pDX, IDC_LATURI, m_Nr);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(POL, CDialog)
	//{{AFX_MSG_MAP(POL)
	ON_BN_CLICKED(IDC_RUN, OnRun)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// POL message handlers

void POL::OnRun() 
{
	// TODO: Add your control notification handler code here
	CClientDC dc(this);
	UpdateData(TRUE);
	double f;
	double xa,ya,xb,yb,xc,yc;
	f=3.1415/180.0;
	f=f*360.0;
	for(int i=1;i<=m_Nr;i++)
	{
		xa=0.0;ya=0.0;
		xb=m_Raza*cos((i-1)*f); yb=m_Raza*sin((i-1)*f);
		xc=m_Raza*cos(i*f); yc=m_Raza*sin(i*f);
		dc.MoveTo(round(xa)+200,round(ya)+200);
		dc.LineTo(round(xb)+200,round(yb)+200);
		dc.LineTo(round(xc)+200,round(yc)+200);
		dc.LineTo(round(xa)+200,round(ya)+200);
	//	FIG(xa,ya,xb,yb,xc,yc,&dc);
	}
}

long POL::round(double x)
{
	double temp;
	temp=fabs(x-floor(x));
	if(temp<0.5) return floor(x);
	else return ceil(x);
}

void POL::LAT(double xa, double ya,double xb, double yb, double *x1, double *y1)
{
	double eps,fi,rap;
	eps=1.0E-4;
	if((fabs(xa-xb)<=eps) && (yb<ya)) fi=3.0*3.1415/2.0;
	if((fabs(xa-xb)<=eps) && (yb>ya)) fi=3.1415/2.0;
	if((fabs(xa-xb)>eps) && (yb>=ya))
	{
		rap=(yb-ya)/(xb-xa);
		fi=atan(rap);
		if((fabs(fi)<=eps) && (xb>xa)) fi=0.0;
		if(fi<0.0) fi=fi+3.1415;
	}
	if((fabs(xa-xb)>eps) && (yb<ya))
	{
		rap=(yb-ya)/(xb-xa);
		fi=atan(rap);
		if(fi>0.0) fi=fi+3.1415;
		else fi=fi+2*3.1415;
	}
	*x1=xa+m_Pas*cos(fi);
	*y1=ya+m_Pas*sin(fi);
}

void POL::FIG(double xa, double ya, double xb, double yb, double xc, double yc,CClientDC *dc)
{
	double x1,y1,x2,y2,x3,y3,dist;
	while(1)
	{
		LAT(xa,ya,xb,yb,&x1,&y1);
		dc->MoveTo(round(x1)+200,round(y1)+200);
		LAT(xb,yb,xc,yc,&x2,&y2);
		dc->LineTo(round(x2)+200,round(y2)+200);
		LAT(xc,yc,xa,ya,&x3,&y3);
		dc->LineTo(round(x3)+200,round(y3)+200);
		dc->LineTo(round(x1)+200,round(y1)+200);
		xa=x1;	ya=y1;	xb=x2;	yb=y2;
		xc=x3;	yc=y3;
		dist=(xa-xb)*(xa-xb)+(ya-yb)*(ya-yb);
		dist=sqrt(dist);
		if(fabs(dist)<=m_Lmin) break;
	}
}
