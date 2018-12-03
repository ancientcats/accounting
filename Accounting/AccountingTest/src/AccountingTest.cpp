// AccountingTest.cpp : Defines the entry point for the console application.
//

#include <gtest/gtest.h>
#include "Accounting/Accounting.h"

using namespace testing;

class CAccountingTest : public Test
{
protected:
    virtual void SetUp()
    {

    }

    CAccounting m_kAccounting;
};

TEST_F( CAccountingTest, QueryAmount_NovemebrTotal30_Daily1 )
{
    m_kAccounting.CreateBudget( "201811", 30 );
    EXPECT_EQ( m_kAccounting.QueryAmount( "20181101", "20181101" ), 1 );
}

