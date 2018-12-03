#pragma once

#include <string>
#include <vector>

typedef std::vector< std::pair< std::string, int > > Budget;

class CAccounting
{
public:
    CAccounting();
    ~CAccounting();

    void CreateBudget( const std::string& strYearMonth, int nBudget );
    int QueryAmount( const std::string& strStartYearMonthDate, const std::string& strEndYearMonthDate );

protected:

    int DaysOfYearMonth( const std::string& strYearMonth ) const;
    int PeriodOfOverlappedYearMonth( const std::string& strYearMonth, const std::string& strStartYearMonthDate, const std::string& strEndYearMonthDate ) const;

    Budget  m_kBudget;
};

