#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("�Ѿ¹D��", ({ "sky cloth","cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�@�󲽤ѮɩҬ諸����.\n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/shield",4);
                set("armor_prop/armor", 5);
        }
        setup();
}

