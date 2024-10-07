
#include <iostream>

void my_toupper(char **str)
{
        int i =0;
   
        while((*str)[i])
        {
           if ((*str)[i] >= 'a' && (*str)[i] <= 'z')
			    (*str)[i] -= 32;
		    i++;
        }
}

int main(int ac,char **av)
{
    int i;
    i = 1;
    
    if(ac != 1)
    {
        while(i < ac)
        {
            my_toupper(&av[i]);
            std::cout <<av[i];
            i++;
        }
        std::cout<< std::endl;

    }
    else
        std::cout <<"* LOUD AND UNBEARABLE FEEDBACK NOISE *" <<std::endl;
    return 0;
}