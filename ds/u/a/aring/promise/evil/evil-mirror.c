#include <ansi.h> 
inherit ITEM;
int query_autoload() { return 1; }
void create()
{
        set_name(HIY"邪魔鏡"NOR,({"evil mirror","toll"}));
        set_weight(0);
        set("unit", "個");
        set("no_sell", 1);
        set("long",
  HIY"這是個竊聽器，你可以用sn1 <對象>來安裝。"NOR);
}

