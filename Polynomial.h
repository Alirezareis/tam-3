//                                                               //                   
//                                                               //                   
//                                                               //                   
//                                                               //                   
//                      POLYNOMIAL CLASS                         //                                   
//                         2022/06/04                            //                                
//                        ALIREZA REISI                          //                          
//                     AMIRHOSSEIN BAHRAMI                       //                             
//                                                               //                   
//                                                               //                   
//                                                               //                   
//                                                               //                   
//                                                               //
#include "../tamrin3/Polynomial.cpp"
void Polynomial::push_back(Term input)
{
    Terms.push_back(input);
}
void Polynomial::pop_back()
{
    Terms.pop_back();
}
int Polynomial::size()
{
    return Terms.size();
}