#include <ansi.h>

inherit ITEM;
void create()
{
        set_name(HIG"��"HIW"�m"HIC"��"NOR,({ "five color stone","stone" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","�o�O�@���֦������C�⪺���Y�A�b�]�ߤ]���ө����\\��C\n");
                set("unit","��");
                set("value",5000);
        }
        setup();
}

void init()
{
        if(!this_object()->query_light()) this_object()->start_light(1);
}

