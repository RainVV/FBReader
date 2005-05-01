/*
 * FBReader -- electronic book reader
 * Copyright (C) 2005 Nikolay Pultsin <geometer@mawhrin.net>
 * Copyright (C) 2005 Mikhail Sobolev <mss@mawhrin.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "GtkWord.h"

GtkWord::GtkWord(const char *utf8String, int len, int startOffset) : Word(startOffset) {
	myUtf8Contents.append(utf8String, len);
	ZLUnicodeUtil::utf8ToUcs2(myUcs2Contents, myUtf8Contents, -1);
}

std::string GtkWord::mid(int start, int length) const {
  std::string result;

  if (length == -1) {
    length = this->length();
  }

  int end = std::min(this->length(), start+length);

	ZLUnicodeUtil::Ucs2String tempo (myUcs2Contents.begin()+start, myUcs2Contents.begin()+end);

  ZLUnicodeUtil::ucs2ToUtf8(result, tempo, -1);

  return result;
}
