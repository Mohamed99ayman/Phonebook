#ifndef _ISVALIDH_
#define _ISVALIDH_
int isValid(char s[])
{
    int length=strlen(s),j,i=0, ind1=0, ind2=0;
    while(s[i]!='\0')
    {
        if (s[i]=='@')
        {
            j=0;
            ind1=i+1;
            break;
        }
        j=1;
        i++;
    }
    if(j==1)
    {
        return 0;
    }
    if (( (s[0]<'a') || (s[0]>'z') )&&( (s[0]<'A') || (s[0]>'Z')))
        return 0;
    else
    {
        for (i=1; i<length; i++)
        {
            if ((( (s[i]<'a') ||(s[i]>'z') )&&( (s[i]<'A') || (s[i]>'Z')))&& ((s[i]<'0') || (s[i]>'9'))&&(s[i]!='_')&&(s[i]!='.')&&(s[i]!='@'))
                return 0;
        }
    }
    if ((( (s[ind1]<'a') || (s[ind1]>'z') )&&( (s[ind1]<'A') || (s[ind1]>'Z'))))
        return 0;
    else
    {
        for (j=ind1; j<length; j++)
        {
            if (s[j]=='.')
            {
                ind2=j+1;
                break;
            }
            else if ((( (s[j]<'a') || (s[j]>'z') )&&( (s[j]<'A') || (s[j]>'Z'))))
                return 0;
        }
        if (tolower(s[ind2]) == 'c' && tolower(s[ind2+1]) == 'o'&& tolower(s[ind2+2]) == 'm'&& s[ind2+3] == '\0')
            return 1;
        else
            return 0;
    }
}
int isint(char*ptr)
{
    while((*ptr)!='\0')
    {
        if (isdigit(*ptr)!=0)
        {
            ptr++;
            continue;
        }
        else
        {
            return 0;
            break;

        }
    }
    return 1;

}
#endif

