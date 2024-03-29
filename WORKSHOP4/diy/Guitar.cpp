/***********************************************************************
// OOP244 Workshop #4 p2: tester program
//
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// -KANISHKA       FEBRUARY 15, 2024
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Guitar.h"
using namespace std;

namespace seneca
{
   const char *GuitarStr::material() const
   {
      return m_material;
   }
   double GuitarStr::gauge() const
   {
      return m_gauge;
   }
   GuitarStr::GuitarStr(){};

   GuitarStr::GuitarStr(const char *ma, double ga)
   {
      strncpy(m_material, ma, MAT_LEN);
      m_gauge = ga;
   };

   Guitar::Guitar(const char *mod)
   {
      m_strings = nullptr;
      m_numStrings = 0;
      strcpy(m_model, mod);
   }

   Guitar::Guitar(GuitarStr strs[], int ns, const char *mod)
   {
      if (ns < 0)
      {
         Guitar();
      }
      else
      {
         m_strings = new GuitarStr[ns + 1];
         for (int i = 0; i < ns; i++)
         {
            m_strings[i] = strs[i];
         }
         m_numStrings = ns;
         strcpy(m_model, mod);
      }
   }

   Guitar::~Guitar()
   {
      delete[] m_strings;
      m_strings = nullptr;
      m_numStrings = 0;
   }

   bool Guitar::changeString(const GuitarStr &gs, int sn)
   {
      if (sn < m_numStrings)
      {
         m_strings[sn] = gs;
         return true;
      }
      else
         return false;
   }

   void Guitar::reString(GuitarStr strs[], int ns)
   {
      delete[] m_strings;
      m_strings = new GuitarStr[ns+1];
      m_numStrings = ns;
      for (int i = 0; i < ns; i++)
      {
         m_strings[i] = strs[i];
      }
   }

   void Guitar::deString()
   {
      delete[] m_strings;
      m_strings = nullptr;
      m_numStrings = 0;
   }

   bool Guitar::strung() const
   {
      if (m_numStrings > 0)
         return true;
      else
         return false;
   }

   bool Guitar::matchGauge(double ga) const
   {
      for (int i = 0; i < m_numStrings; i++)
      {
         if (m_strings[i].gauge() == ga)
            return true;
      }
      return false;
   }

   std::ostream &Guitar::display(std::ostream &os) const
   {
      if (m_numStrings == 0)
      {
         os << "***Empty Guitar***" << endl;
         return os;
      }
      else
      {
         os << "Guitar Model: " << m_model << endl;
         os << "Strings: " << m_numStrings << endl;

         if (strung())
         {
            for (int i = 0; i < m_numStrings; i++)
            {
               os << "#" << left << i + 1 << setw(MAT_LEN) << right << m_strings[i].material() 
               << " | " << fixed << setprecision(1) << m_strings[i].gauge() << endl;
            }
         }
         return os;
      }
   }
}