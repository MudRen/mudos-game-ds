#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(RED"����֦�"NOR, ({ "leather coat","coat" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long",@long
  �@��s�����`����֦�C
long
);
                set("unit", "��");
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

