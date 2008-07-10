/*
 *	PROGRAM:		Common part of dsc converters.
 *	MODULE:			cvt.h
 *	DESCRIPTION:	Common part of dsc converters.
 *
 *  The contents of this file are subject to the Initial
 *  Developer's Public License Version 1.0 (the "License");
 *  you may not use this file except in compliance with the
 *  License. You may obtain a copy of the License at
 *  http://www.ibphoenix.com/main.nfs?a=ibphoenix&page=ibp_idpl.
 *
 *  Software distributed under the License is distributed AS IS,
 *  WITHOUT WARRANTY OF ANY KIND, either express or implied.
 *  See the License for the specific language governing rights
 *  and limitations under the License.
 *
 *  The Original Code was created by Alex Peshkov
 *  for the Firebird Open Source RDBMS project.
 *
 *  Copyright (c) 2008 Alex Peshkov <peshkoff at mail.ru>
 *  and all contributors signed below.
 *
 *  All Rights Reserved.
 *  Contributor(s): ______________________________________.
 *
 *
 */

#ifndef COMMON_CVT_H
#define COMMON_CVT_H

namespace Jrd {

class CharSet;

}

namespace Firebird {

struct Callbacks
{
	bool (*transliterate)(const dsc* from, dsc* to, CHARSET_ID&, ErrorFunction err);
	CHARSET_ID (*getChid)(const dsc* d);
	ErrorFunction err;
	Jrd::CharSet* (*getToCharset)(CHARSET_ID charset2);
	void (*validateData)(Jrd::CharSet* toCharset, SLONG length, const UCHAR* q, ErrorFunction err);
	void (*validateLength)(Jrd::CharSet* toCharset, SLONG toLength, UCHAR* start, const USHORT to_size, ErrorFunction err);
	SLONG (*getCurDate)();
	void (*isVersion4)(bool& v4);
};

}


void CVT_conversion_error(const dsc*, ErrorFunction);
double CVT_power_of_ten(const int);
SLONG CVT_get_long(const dsc*, SSHORT, ErrorFunction);
double CVT_get_double(const dsc*, ErrorFunction);
USHORT CVT_make_string(const dsc*, USHORT, const char**, vary*, USHORT, ErrorFunction);
void CVT_move_common(const dsc*, dsc*, Firebird::Callbacks*);
void CVT_move(const dsc*, dsc*, ErrorFunction);
SSHORT CVT_decompose(const char*, USHORT, SSHORT, SLONG*, ErrorFunction);
USHORT CVT_get_string_ptr(const dsc*, USHORT*, UCHAR**, vary*, USHORT, ErrorFunction);
SINT64 CVT_get_int64(const dsc*, SSHORT, ErrorFunction);
SQUAD CVT_get_quad(const dsc*, SSHORT, ErrorFunction);

#endif //COMMON_CVT_H
