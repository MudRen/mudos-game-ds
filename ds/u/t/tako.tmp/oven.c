#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(YEL" �N�c "NOR,({ "bread oven","oven" }));
        set_weight(30000);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","�@�y�N�ѥ]�Ϊ�����,�ū׫ܰ�,���n�N��C\n");
                set("no_get",1);
                set("no_drop",1);
                set("no_dest",1);
                set("no_sac",1); 
                set("value", 100000);
                set("unit","�y");
        }
        setup();
}




