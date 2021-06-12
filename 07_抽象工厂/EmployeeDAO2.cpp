#include <vector>
using std::vector;

class EmployeeDO
{
};

//数据库访问有关的基类
class IDBConnection
{
};
class IDBConnectionFactory
{
public:
    virtual IDBConnection *CreateDBConnection() = 0;
};

class IDBCommand
{
};
class IDBCommandFactory
{
public:
    virtual IDBCommand *CreateDBCommand() = 0;
};

class IDataReader
{
};
// 工厂
class IDataReaderFactory
{
public:
    virtual IDataReader *CreateDataReader() = 0;
};

//支持SQL Server
class SqlConnection : public IDBConnection
{
};
class SqlConnectionFactory : public IDBConnectionFactory
{
};

class SqlCommand : public IDBCommand
{
};
class SqlCommandFactory : public IDBCommandFactory
{
};

class SqlDataReader : public IDataReader
{
};
class SqlDataReaderFactory : public IDataReaderFactory
{
};

//支持Oracle
class OracleConnection : public IDBConnection
{
};
class OracleConnectionFactory : public IDBConnectionFactory
{
};

class OracleCommand : public IDBCommand
{
};
class OracleCommandFactory : public IDBCommandFactory
{
};

class OracleDataReader : public IDataReader
{
};
class OracleDataReaderFactory : public IDataReaderFactory
{
};

class EmployeeDAO
{
    IDBConnectionFactory *dbConnectionFactory;
    IDBCommandFactory *dbCommandFactory;
    IDataReaderFactory *dataReaderFactory; // 3 个工厂基类指针

public:
    vector<EmployeeDO> GetEmployees()
    {
        IDBConnection *connection = dbConnectionFactory->CreateDBConnection(); // 动态创建对象
        connection->ConnectionString("...");

        IDBCommand *command = dbCommandFactory->CreateDBCommand();
        command->CommandText("...");
        command->SetConnection(connection); //关联性 三个工厂创建对象时必须为同一种数据库对应对象

        IDBDataReader *reader = command->ExecuteReader(); //关联性
        while (reader->Read())
        {
        }
    }
};
