#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(HIC"魔戒"NOR, ({ "Dreamcast ring","ring" }) );
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","這枚戒子是大魔王索倫用火山漿作成的，持有者這枚戒子不能被索倫拿回...\n");
                set("unit", "只");
        set("value",10000);
        set_weight(600);
              set("material","jade");
                set("armor_prop/armor", 10);
         set("armor_prop/str",1);
         set("armor_prop/con",2);
         set("armor_prop/bar",1);
        }
        setup();
}


