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


#ifndef __COLLADAMAX_IMAGE_EXPORTER_H__
#define __COLLADAMAX_IMAGE_EXPORTER_H__

#include "COLLADAMaxPrerequisites.h"

#include "COLLADAStreamWriter.h"
#include "COLLADALibraryImages.h"

#include "COLLADAMaxEffectExporter.h"
#include "COLLADAMaxDocumentExporter.h"

namespace COLLADAMax
{


    /** This class writes the @a \<library_images\>. It uses informations created by an effect exporter.*/

    class ImageExporter : public COLLADA::LibraryImages
    {

    private:
        /** Map of image filenames and image ids.*/
        const ExportedImageMap & mExportedImageMap;

    public:
        /**
        @param streamWriter The stream the output will be written to
        @param documentExporter The document exporter this material exporter is used in*/
        ImageExporter ( COLLADA::StreamWriter * streamWriter, DocumentExporter * documentExporter );
        virtual ~ImageExporter()
        {}

        /** Exports the library images.*/
        void doExport();

    private:
        ImageExporter ( const ImageExporter & imageExporter );
        ImageExporter &operator= ( const ImageExporter & imageExporter );

    };
}

#endif //__COLLADAMAX_IMAGE_EXPORTER_H__