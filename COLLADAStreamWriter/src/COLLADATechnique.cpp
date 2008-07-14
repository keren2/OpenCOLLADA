/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/


#include "COLLADAStreamWriter.h"
#include "COLLADATechnique.h"
#include "COLLADASWC.h"
#include "assert.h"

namespace COLLADA
{
    //---------------------------------------------------------------
    void Technique::openTechnique ( const String &profile, const String &xmlns )
    {
        mTechniqueCloser = mSW->openElement ( CSWC::COLLADA_ELEMENT_TECHNIQUE );

        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_PROFILE, profile );

        if ( !xmlns.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_XMLNS, xmlns );
    }

    //---------------------------------------------------------------
    void Technique::addChildElement ( const String &childElementName )
    {
        TagCloser childElementCloser = mSW->openElement ( childElementName );

        mOpenChildElements[childElementName] = &childElementCloser;
    }

    //---------------------------------------------------------------
    void Technique::closeChildElement ( const String &childElementName )
    {
        TagCloser* childElementCloser = mOpenChildElements[childElementName];

        if ( childElementCloser ) childElementCloser->close();
    }

    //---------------------------------------------------------------
    void Technique::addParameter ( const String &paramName, const String &value )
    {
        mSW->openElement ( paramName );

        if ( !value.empty() )
            mSW->appendText ( value );

        mSW->closeElement();
    }

    //---------------------------------------------------------------
    void Technique::addParameter ( const String &paramName, const bool &value )
    {
        mSW->openElement ( paramName );
        mSW->appendValues ( value );
        mSW->closeElement();
    }

    //---------------------------------------------------------------
    void Technique::addParameter ( const String &paramName, const int &value )
    {
        mSW->openElement ( paramName );
        mSW->appendValues ( value );
        mSW->closeElement();
    }

    //---------------------------------------------------------------
    void Technique::addParameter ( const String &paramName, const double &value )
    {
        mSW->openElement ( paramName );
        mSW->appendValues ( value );
        mSW->closeElement();
    }

    //---------------------------------------------------------------
    void Technique::addMatrixParameter ( const String &paramName, const double matrix[][4] ) const
    {
        mSW->openElement ( paramName );
        mSW->appendValues ( matrix[0][0], matrix[0][1], matrix[0][2], matrix[0][3] );
        mSW->appendValues ( matrix[1][0], matrix[1][1], matrix[1][2], matrix[1][3] );
        mSW->appendValues ( matrix[2][0], matrix[2][1], matrix[2][2], matrix[2][3] );
        mSW->appendValues ( matrix[3][0], matrix[3][1], matrix[3][2], matrix[3][3] );
        mSW->closeElement();
    }

    //---------------------------------------------------------------
    void Technique::closeTechnique()
    {
        mTechniqueCloser.close();
    }

} //namespace COLLADA