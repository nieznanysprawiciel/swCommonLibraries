#pragma once

#include "swCommonLib/External/Catch/catch.hpp"

#include "swCommonLib/Common/RTTR.h"

// Serialization
#include "swCommonLib/Serialization/PropertySerialization/Serialization.h"

// Test classes
#include "swCommonLib/TestUtils/TestClassHierarchy/SerializationPrimitives/StructWithSimpleTypes.h"
#include "swCommonLib/TestUtils/TestClassHierarchy/SerializationPrimitives/StringContainer.h"
#include "swCommonLib/TestUtils/TestClassHierarchy/SerializationPrimitives/BaseObject.h"
#include "swCommonLib/TestUtils/TestClassHierarchy/SerializationPrimitives/Arrays/ArrayContainer.h"
#include "swCommonLib/TestUtils/TestClassHierarchy/SerializationPrimitives/Structs/StructAsRefContainer.h"
#include "swCommonLib/TestUtils/TestClassHierarchy/SerializationPrimitives/Structs/StructAsPtrContainer.h"
#include "swCommonLib/TestUtils/TestClassHierarchy/SerializationPrimitives/Structs/StructAsCopyContainer.h"
#include "swCommonLib/TestUtils/TestClassHierarchy/SerializationPrimitives/Structs/StructPtrContainer.h"
#include "swCommonLib/TestUtils/TestClassHierarchy/SerializationPrimitives/Structs/StructSharedPtrContainer.h"
