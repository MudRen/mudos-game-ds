#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIY"秘寶之箱"NOR,({"treasure box","box"}));
        set("unit", "個");
        set("long",@LONG
        
  一個用來存放放置較為特殊或是月族領導者們的私人物品。你可
  以把珍貴的物品放入箱中保存或是從箱內拿出你所需要的物品。

  放東西: put [東西] in box
  拿東西: get [東西] from box

LONG
);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        set_max_encumbrance(999999);
	setup();
        add_money("coin",10000000000);
}


