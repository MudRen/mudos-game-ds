#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(YEL" 布丁器 "NOR,({ "pooding oven","oven" }));
        set_weight(30000);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","一座做布丁的機器,旁邊還有果凍粉。\n");
                set("no_get",1);
                set("no_drop",1);
                set("no_dest",1);
                set("no_sac",1); 
                set("value", 100000);
                set("unit","座");
        }
        setup();
}



