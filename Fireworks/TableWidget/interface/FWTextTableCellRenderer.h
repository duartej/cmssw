#ifndef Fireworks_TableWidget_FWTextTableCellRenderer_h
#define Fireworks_TableWidget_FWTextTableCellRenderer_h
// -*- C++ -*-
//
// Package:     TableWidget
// Class  :     FWTextTableCellRenderer
// 
/**\class FWTextTableCellRenderer FWTextTableCellRenderer.h Fireworks/TableWidget/interface/FWTextTableCellRenderer.h

 Description: A Cell Renderer who draws text and can show selection of a cell

 Usage:
    Use when the cells of a table are simple text and you want to be able to also show that a cell has been selected.

*/
//
// Original Author:  Chris Jones
//         Created:  Mon Feb  2 16:43:50 EST 2009
// $Id: FWTextTableCellRenderer.h,v 1.1 2009/02/03 20:33:03 chrjones Exp $
//

// system include files
#include <string>
#include "GuiTypes.h"
#include "TGResourcePool.h"
#include "TGGC.h"

// user include files
#include "Fireworks/TableWidget/interface/FWTableCellRendererBase.h"

// forward declarations

class FWTextTableCellRenderer : public FWTableCellRendererBase {
   
public:
   static const TGGC&  getDefaultGC();
   static const TGGC&  getHighlightGC();  
   
   enum Justify {
      kJustifyLeft,
      kJustifyRight,
      kJustifyCenter
   };
   
   FWTextTableCellRenderer(const TGGC* iContext=&(getDefaultGC()), 
                           const TGGC* iContext=&(getHighlightGC()),
                           Justify iJustify=kJustifyLeft);
   virtual ~FWTextTableCellRenderer();
   
   // ---------- const member functions ---------------------
   const TGGC* graphicsContext() const { return m_context;}
   virtual UInt_t width() const;
   virtual UInt_t height() const;
   
   const TGFont* font() const;
   // ---------- static member functions --------------------
   
   // ---------- member functions ---------------------------
   void setData(const std::string&, bool isSelected);
   void setGraphicsContext(const TGGC* iContext) { m_context = iContext;}
   void setJustify(Justify);
   
   virtual void draw(Drawable_t iID, int iX, int iY, unsigned int iWidth, unsigned int iHeight);
   
   
private:
   FWTextTableCellRenderer(const FWTextTableCellRenderer&); // stop default
   
   const FWTextTableCellRenderer& operator=(const FWTextTableCellRenderer&); // stop default
   
   // ---------- member data --------------------------------
   const TGGC* m_context;
   const TGGC* m_highlightContext;
   TGFont* m_font;
   std::string m_data;
   bool m_isSelected;
   Justify m_justify;
};


#endif
