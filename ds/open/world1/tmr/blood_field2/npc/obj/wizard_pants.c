#include <armor.h>

inherit PANTS;

void create()
{
        set_name("�g�q�u��", ({ "toast pants", "pants" }) );
        set_weight(2500);
		set("long","�۷�u�����u�ǡA�O�g�H�ڸs����g�q�̷R�諸�p��ǡC");

        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("value", 500 );
        }

        set("armor_prop/armor",5);
        set("armor_prop/dex",1);
        setup();
}

