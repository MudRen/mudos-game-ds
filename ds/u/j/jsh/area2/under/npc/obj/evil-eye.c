#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR"�c�]"HIW"��"HIY"��"NOR,({"evil eye","eye"}));
        set("long",@long
���]���k���y�A�i�}�ҭ�ù���C
long
                );

        set_weight(1000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("door","evileye");
                set("value", 5600);
        }
        setup();
}


