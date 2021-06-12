#include <vector>
using std::vector;

class EmployeeDO
{
};

class EmployeeDAO
{
public:
    vector<EmployeeDO> GetEmployees()
    {
        // 不适用于多种数据库的支持
        SqlConnection *connection = new SqlConnection();
        connection->ConnectionString = "...";

        SqlCommand *command = new SqlCommand();
        command->CommandText = "...";
        command->SetConnection(connection);

        SqlDataReader *reader = command->ExecuteReader();
        while (reader->Read())
        {
        }
    }
};
