// cloth.c
#include <armor.h>

inherit HANDS;

void create()
{
set_name("�񴹤�M",({"green gloves","gloves"}));
set("long","�@���`��⪺��T��M�C\n");
set_weight(3900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
 set("unit", "��");
set("value",3900);
set("material", "cloth");
set("armor_prop/attack",2);
set("limit_lv",50);
        }
        setup();
}


