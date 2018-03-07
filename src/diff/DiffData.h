//  DiffData.h
//  ZipDiff
/*
 The MIT License (MIT)
 Copyright (c) 2018 HouSisong
 
 Permission is hereby granted, free of charge, to any person
 obtaining a copy of this software and associated documentation
 files (the "Software"), to deal in the Software without
 restriction, including without limitation the rights to use,
 copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the
 Software is furnished to do so, subject to the following
 conditions:
 
 The above copyright notice and this permission notice shall be
 included in all copies of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef ZipDiff_DiffData_h
#define ZipDiff_DiffData_h
#include <vector>
#include <string>
#include "../patch/Zipper.h"
#include "../patch/ZipDiffData.h"
#include "../../HDiffPatch/libHDiffPatch/HDiff/diff_types.h"

bool zipFileData_isSame(UnZipper* self,int selfIndex,UnZipper* srcZip,int srcIndex);//byte by byte test
static inline std::string zipFile_name(UnZipper* self,int fileIndex){
    int nameLen=UnZipper_file_nameLen(self,fileIndex);
    const char* nameBegin=UnZipper_file_nameBegin(self,fileIndex);
    return std::string(nameBegin,nameBegin+nameLen);
    
}

bool getSamePairList(UnZipper* newZip,UnZipper* oldZip,
                     std::vector<uint32_t>& out_samePairList,
                     std::vector<uint32_t>& out_newRefList,
                     std::vector<uint32_t>& out_newReCompressList);

bool readZipStreamData(UnZipper* zip,const std::vector<uint32_t>& refList,
                       std::vector<unsigned char>& out_data);

bool serializeZipDiffData(std::vector<TByte>& out_data, UnZipper* newZip,UnZipper* oldZip,
                          const std::vector<uint32_t>& newReCompressList,
                          const std::vector<uint32_t>& samePairList,
                          const std::vector<uint32_t>& oldRefList,
                          const std::vector<TByte>&    hdiffzData,
                          hdiff_TCompress*             compressPlugin);

#endif //ZipDiff_DiffData_h