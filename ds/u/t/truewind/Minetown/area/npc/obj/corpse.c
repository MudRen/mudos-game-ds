#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"染血的屍體"NOR,({"blodded body","body"}));
        set("long","一具剛死不久的屍體，身上幾處傷口還染滿了紅色的血跡。\n");
        set_weight(1000);
        set("value",0);
        set("unit","具");
        setup();
}