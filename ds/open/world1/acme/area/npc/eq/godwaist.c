#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
	set_name(CYN"���Z�@�y"NOR ,({ "god waist","waist" }) );
        set("long","���Z�дx���H�Ұt�a���@�y�C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(8000);
                set("material", "skin");
                set("unit","��");
                set("value",2000);
                set("volume",1);
                set("armor_prop/armor", 4);
                set_temp("apply/hit",3);
                set("limit_int",20);
        }
        setup();
}

