#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIC"道具陳列架"NOR,({"item shelf","shelf"}));
        set("unit", "個");
        set("long",@LONG
        
  一個用來存放各式各樣道具的架子。你可以把珍貴的道具放在架
  上保存或是從架子中拿出你所需要的道具。

  放東西: put [東西] in item shelf
  拿東西: get [東西] from item shelf

LONG
);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        set_max_encumbrance(999999);
        set_max_capacity(400);  //2003.4.16 10000->400  by ksj
        setup();
}
