// greyrobe.c �Ǧ�D�T

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(WHT"�Ǧ�D�T"NOR, ({"pao", "cloth", "dao pao"}) );
        set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�@�󴶴��q�q���ǧG�D�T�C\n");
                set("material", "cloth");
                set("armor_prop/armor", 2);
        }
        setup();
}
