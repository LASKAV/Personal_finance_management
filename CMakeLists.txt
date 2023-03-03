cmake_minimum_required(VERSION 3.24)
project(Personal_finance_management)

set(CMAKE_CXX_STANDARD 14)

add_executable(Personal_finance_management
        Personal_finance_management/Personal_finance_management.cpp Personal_finance_management/Category.h Personal_finance_management/Date.h Personal_finance_management/Time.h Personal_finance_management/Spending.h Personal_finance_management/MoneyStorage.h Personal_finance_management/Card.h Personal_finance_management/Wallet.h)
