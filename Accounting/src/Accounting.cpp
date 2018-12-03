#include "..\inc\Accounting.h"

CAccounting::CAccounting()
{
}


CAccounting::~CAccounting()
{
}

void CAccounting::CreateBudget( const std::string& strYearMonth, int nBudget )
{
    m_kBudget.push_back( make_pair( strYearMonth, nBudget ) );
}

int CAccounting::QueryAmount( const std::string& strStartYearMonthDate, const std::string& strEndYearMonthDate )
{
    int nAmount = 0;
    for ( const auto& budget : m_kBudget )
    {
        int nDays = DaysOfYearMonth( budget.first );
        int nPeriod = PeriodOfOverlappedYearMonth( budget.first, strStartYearMonthDate, strEndYearMonthDate );
        nAmount += ( ( budget.second / nDays ) * nPeriod );
    }

    return nAmount;
}

int CAccounting::DaysOfYearMonth( const std::string& strYearMonth ) const
{
    int nDays = 0;
    int nYear = std::stoi( strYearMonth.substr( 0, 4 ) );
    int nMonth = std::stoi( strYearMonth.substr( 4, 2 ) );
    if ( 2 == nMonth )
    {
        if ( ( ( nYear & 3 ) == 0 && ( nYear % 100 ) > 0 ) || ( nYear % 400 ) == 0 )
        {
            nDays = 29;
        }
        else
        {
            nDays = 28;
        }
    }
    else if ( nMonth < 8 )
    {
        nDays = ( nMonth & 1 ) ? 31 : 30;
    }
    else
    {
        nDays = ( nMonth & 1 ) ? 30 : 31;
    }
    return nDays;
}

int CAccounting::PeriodOfOverlappedYearMonth( const std::string& strYearMonth, const std::string& strStartYearMonthDate, const std::string& strEndYearMonthDate ) const
{
    int nYear = std::stoi( strYearMonth.substr( 0, 4 ) );
    int nMonth = std::stoi( strYearMonth.substr( 4, 2 ) );

    int nStartYear = std::stoi( strStartYearMonthDate.substr( 0, 4 ) );
    int nStartMonth = std::stoi( strStartYearMonthDate.substr( 4, 2 ) );
    int nStartDay = std::stoi( strStartYearMonthDate.substr( 6, 2 ) );

    int nEndYear = std::stoi( strEndYearMonthDate.substr( 0, 4 ) );
    int nEndMonth = std::stoi( strEndYearMonthDate.substr( 4, 2 ) );
    int nEndDay = std::stoi( strEndYearMonthDate.substr( 6, 2 ) );

    int nDays = DaysOfYearMonth( strYearMonth );
    if ( nYear == nStartYear && nYear == nEndYear )
    {
        if ( nMonth >= nStartMonth && nMonth <= nEndMonth )
        {
            if ( nMonth == nEndMonth )
            {
                return nEndDay - nStartDay + 1;
            }
            else
            {
                return nDays - nStartDay + 1;
            }
        }
    }

    return 0;
}