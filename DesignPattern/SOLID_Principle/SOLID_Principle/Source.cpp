#include"SingleResponsibilityPrinciple.h"
#include"DependencyInjectionPrinciple.h"
#include "InterfaceSeggregationPrinciple.h"
#include "LiskovSubstitution.h"
#include"OpenClose.h"


//For SRP
int main()
{
    Journal journal{ "Dear Diary" };
    journal.add("I ate a bug");
    journal.add("I cried today");

    //journal.save("diary.txt");

    PersistenceManager pm;
    pm.save(journal, "diary.txt");
    return 0;
}