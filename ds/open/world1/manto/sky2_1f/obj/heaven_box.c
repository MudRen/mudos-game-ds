#include <ansi.h>
inherit ITEM;
inherit BOX_LOG;

void create()
{
    set_name(HIY"天地寶箱"NOR,({"heaven box","box"}));
        set("unit", "個");
        set("long",@LONG
        
  一個用來給新手存放裝備及物品的箱子。你可以把放入箱中保存
  或是從箱內拿出你所需要的物品。

  放東西: put [東西] in box
  拿東西: get [東西] from box

  這個寶箱有著特殊的功能:
         ** checkuse <box or shelf's id> {-w|-l|-m}
         ** cleanup <box or shelf's id> {get|put|all}
LONG
);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        set_max_encumbrance(999999);
        set_max_capacity(400); // 2003.4.16  10000->400  by ksj
        set("club_id", "sky");  // BOX_LOG 用
        set("demand_level", 3);  // BOX_LOG 用
        set("access_log",1);
        setup();
}
