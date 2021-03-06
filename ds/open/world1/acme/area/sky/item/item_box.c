//2006.5.30 add by whoami
#include <ansi.h>
inherit ITEM;
inherit BOX_LOG;

void create()
{
    set_name(HIM"道具箱"NOR,({"Item box","box"}));
        set("unit", "個");
        set("long",@LONG
  一個用來存放各式各樣道具的箱子。你可以把珍貴的道具放在箱裡保
  存或是從箱子中拿出你所需要的道具。
  
  放東西: put [東西] in item box
  拿東西: get [東西] from item box

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

