#include "FactoryTest.h"
#include "Test.h"
ITest* FactoryTest::createTest()
{
    return new Test;
}
