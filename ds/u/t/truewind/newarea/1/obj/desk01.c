#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name(RED"紅檀木圓桌"NOR, ({ "table" }));
        set("long", @long
檀木加工製成的桌子，紅潤而有光澤。適合眾人一同圍坐聚餐。
long
);       
        set_weight(190000);
        set("value", 10000);
        set("no_sac",1);
        setup();
}

