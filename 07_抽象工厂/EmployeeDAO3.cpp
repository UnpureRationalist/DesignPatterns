#include <vector>
using std::vector;

class EmployeeDO
{
};

//数据库访问有关的基类
class IDBConnection
{
};

class IDBCommand
{
};

class IDataReader
{
};

// 工厂类 三个工厂放在一起
class IDBFactory
{
public:
    virtual IDBConnection *CreateDBConnection() = 0;
    virtual IDBCommand *CreateDBCommand() = 0;
    virtual IDataReader *CreateDataReader() = 0;
};

//支持SQL Server
class SqlConnection : public IDBConnection
{
};
class SqlCommand : public IDBCommand
{
};
class SqlDataReader : public IDataReader
{
};

class SqlDBFactory : public IDBFactory
{
public:
    virtual IDBConnection *CreateDBConnection() = 0;
    virtual IDBCommand *CreateDBCommand() = 0;
    virtual IDataReader *CreateDataReader() = 0;
};

//支持Oracle
class OracleConnection : public IDBConnection
{
};

class OracleCommand : public IDBCommand
{
};

class OracleDataReader : public IDataReader
{
};

class EmployeeDAO
{
    IDBFactory *dbFactory; // 一个工厂 创建的对象必为同一个数据库对应对象

public:
    vector<EmployeeDO> GetEmployees()
    {
        IDBConnection *connection = dbFactory->CreateDBConnection();
        connection->ConnectionString("...");

        IDBCommand *command = dbFactory->CreateDBCommand();
        command->CommandText("...");
        command->SetConnection(connection); //关联性

        IDBDataReader *reader = command->ExecuteReader(); //关联性
        while (reader->Read())
        {
        }
    }
};
