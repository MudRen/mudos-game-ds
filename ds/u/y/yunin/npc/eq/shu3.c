#include <ansi.h>
#include <armor.h>
inherit LEGGING;
void create()
{
        set_name(HIR"��ù�j�L��"NOR ,({ "shut lo leggings","leggings" }) );
        set("long","�|�j������@���P�D�ۨϥΪ�����C\n");
        set_weight(1800);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
        set("material", "cold");
        set("volume",3);
        set("unit", "��");
        set("value",3900);
        }
        set("armor_prop/armor",3);
        set("armor_prop/con",1);
        setup();
}


