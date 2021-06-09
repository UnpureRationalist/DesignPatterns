enum TaxBase
{
    CN_Tax,
    US_Tax,
    DE_Tax,
    FR_Tax //更改
};

class SalesOrder
{
    TaxBase tax;

public:
    double CalculateTax()
    {
        //...
        // 静态的 不利于扩展
        if (tax == CN_Tax)
        {
            //CN***********
        }
        else if (tax == US_Tax)
        {
            //US***********
        }
        else if (tax == DE_Tax)
        {
            //DE***********
        }
        else if (tax == FR_Tax)
        {   //更改
            //...
        }

        //....
    }
};
