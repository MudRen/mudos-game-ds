#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(HIY"防具陳列架"NOR,({"equip shelf","shelf"}));
        set("unit", "個");
        set("long",@LONG
        
  一個擺放著許多防具的鐵架。你可以把一些防具放在架上保存或是從
  架子中拿東西出來。

  放東西: put [東西] in equip shelf
  拿東西: get [東西] from equip shelf

LONG
);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        set_max_encumbrance(999999);
        set_max_capacity(400); //2003.4.16 10000->400 by ksj
        setup();
}
