#ifndef HEAD1_H
#define HEAD1_H

class head1
{
public:
    head1(){}
    ~head1(){}
    
    inline const char* getText()
    {
#ifdef DEF_RET_YES
        return "Yes";
#elif
        return "No";
#endif
        
    }
};

#endif
