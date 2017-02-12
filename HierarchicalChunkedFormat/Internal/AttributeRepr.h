#pragma once
/**
@file AttributeRepr.h
@author nieznanysprawiciel
@copyright File is part of Sleeping Wombat Libraries.
*/

#include "swCommonLib/HierarchicalChunkedFormat/Headers/AttributeHeader.h"

namespace sw
{

class AttributeRepr;
DEFINE_PTR_TYPE( AttributeRepr );
DEFINE_WPTR_TYPE( AttributeRepr );


/**@brief */
class AttributeRepr
{
private:

	AttributeHeader		m_header;		///< Header from file.

	AttributeReprPtr	m_nextAttrib;	///< Next attribute in list.

protected:
public:
	explicit		AttributeRepr() = default;
	~AttributeRepr() = default;

};

}	// sw
