#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(RED"紅色皮衣"NOR, ({ "leather coat","coat" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long",@long
  一件連身的深紅色皮衣。
long
);
                set("unit", "件");
                set("material","gold");
                set("value",1);

             }
        set("armor_prop/con",3);
        set("armor_prop/int",3);
        set("armor_prop/dodge",5);
        set("armor_prop/shield",10);
        set("armor_prop/armor",10);
        setup();
}

int query_autoload() { return 1; }

