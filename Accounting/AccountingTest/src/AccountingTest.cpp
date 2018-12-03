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

// Todo: «Ý¾ã²z

TEST_F( CAccountingTest, QueryAmount_Check31DaysMonthInSecondHalfYear )
{
    m_kAccounting.CreateBudget( "201808", 31 );
    EXPECT_EQ( m_kAccounting.QueryAmount( "20180801", "20180801" ), 1 );
}

TEST_F( CAccountingTest, QueryAmount_Check31DaysMonthInFirstHalfYear )
{
    m_kAccounting.CreateBudget( "201807", 31 );
    EXPECT_EQ( m_kAccounting.QueryAmount( "20180701", "20180701" ), 1 );
}

TEST_F( CAccountingTest, QueryAmount_Check30DaysMonthInFirstHalfYear )
{
    m_kAccounting.CreateBudget( "201804", 30 );
    EXPECT_EQ( m_kAccounting.QueryAmount( "20180401", "20180401" ), 1 );
}

//

TEST_F( CAccountingTest, QueryAmount_NovemberTotal30_Monthly30 )
{
    m_kAccounting.CreateBudget( "201811", 30 );
    EXPECT_EQ( m_kAccounting.QueryAmount( "20181101", "20181130" ), 30 );
}

TEST_F( CAccountingTest, QueryAmount_NovemberTotal30_NovemberAcrossToDecember30 )
{
    m_kAccounting.CreateBudget( "201811", 30 );
    EXPECT_EQ( m_kAccounting.QueryAmount( "20181101", "20181231" ), 30 );
}

