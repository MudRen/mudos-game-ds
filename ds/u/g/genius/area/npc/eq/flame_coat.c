#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
        set_name(RED"闇焰法袍"NOR,({"dark flame coat","coat","surcoat"}) );
        set("long",@LONG
這是一件暗紅色的大法師袍，外側隱約可以看到一個火焰形狀的灰色
標記。XXXXXXXXXXXXXXX(其他敘述)
LONG
);
        set_weight(1600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
                set("limit_con",3);
                set("armor_prop/dodge", 5);
                set("armor_prop/armor", 15);
                set("armor_prop/shield",40);
                set("armor_prop/int",3);
                set("value",5432);
        }
      set("wear_msg", RED"$N披上$n"RED"，頓時氣氛變的十分陰沉。\n"NOR);
      set("unequip_msg",CYN"$N將"RED"$n"CYN"脫了下來，恢復了平常的神態。\n"NOR);
      setup();
}   
int query_autoload() { return 1; }
