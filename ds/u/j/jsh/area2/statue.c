#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(MAG"紫砂雕像"NOR, ({"statue"}) );
      set("long", @LONG 
一隻大型的巨鵰[0;1m�[1mA[0m旁邊有一個斷了右臂且披著一匹破
披風的人[0;1m�[1mA[0m左肩還背著一柄巨劍[0;1m�[1mA[0m不知道是誰 ?
LONG
 );

        set_weight(99);
        set("unit", "座");
        set("no_sell", 1);
        set("no_give", 1);
        set("no_get", 1);
        set("no_drop", 1);

        setup();
}

