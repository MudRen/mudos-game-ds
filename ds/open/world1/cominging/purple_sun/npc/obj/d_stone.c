inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(WHT"元氣石"NOR, ({ "stone", "open-war-stone" }));
        set("long", "一塊形狀奇特的石頭, 上面的凹洞還顯的很有規律. \n");
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "顆");
                set("value", 1);
                set("no_sell", 1);
                set("no_sac", 1);
        }
        setup();
}


