#include <armor.h>
#include <ansi.h>

inherit PANTS;

void create()
{
        set_name(HIR"�t��"HIW"����" NOR ,({ "christmas pants","pants" }) );
        set("long",@LONG
�o�O�@��j�����ǡA��o�D�`�߮�v�v�C 
LONG);
        set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("material", "leather");
                set("volume",2);
                set("unit", "��");
                set("value",1);
        }
        set("armor_prop/armor",1);
        setup();
}

