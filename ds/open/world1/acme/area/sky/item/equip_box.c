//2006.5.30 add by whoami
#include <ansi.h>
inherit ITEM;
inherit BOX_LOG;

void create()
{
    set_name(HIY"防具箱"NOR,({"equip box","box"}));
        set("unit", "個");
        set("long",@LONG
  一個擺放著許多防具的鐵箱。你可以把一些防具放在箱裡保存或是從
  箱子中拿東西出來。
  
  放東西: put [東西] in equip box
  拿東西: get [東西] from equip box

  這個箱子有著特殊的功能:
         ** checkuse 'box or shelf's id' {-w|-l|-m}
         ** cleanup 'box or shelf's id' {get|put|all}

LONG
);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        set_max_encumbrance(999999);
        set_max_capacity(400); //2003.4.16  10000 -> 400  by ksj
        set("club_id", "sky");
        set("demand_level", 3);
        set("access_log",1);
        setup();
}

