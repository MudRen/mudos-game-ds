#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIC"百寶盒"NOR,({"basic_box","box"}));
        set("unit", "個");
        set("long",@LONG

  這是Basic..的寶物盒..啥東西都擺到裡面..你也可以擺喔!_!

  《放入(put)--->put xxx in box..【xxx】為物品id》
  《拿出(get)--->get xxx from box..【xxx】為物品id》

LONG
);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        set_max_encumbrance(12345678);
        set_max_capacity(100000000);
        setup();
}
