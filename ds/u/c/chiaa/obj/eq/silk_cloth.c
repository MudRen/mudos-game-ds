//u/c/chiaa/obj/eq/silk_cloth.c
#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(MAG"��"HIC"��"NOR"��"NOR, ({ "cloth" }) );
        set("long","�@���a�۷�����A,��b���W�X�G�S���Pı.\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(500);
                set("unit", "��");
                set("value", 4000);
                set("material", "silk");
                set("armor_prop/shield",3);
                set("armor_prop/armor", 8);
        }
        setup();
}
