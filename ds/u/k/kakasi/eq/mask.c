#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
        set_name(RED"�g��"HIW"�U"HIY"��"NOR,({"sha-lon mask","mask",}) );
        set("long",@LONG
�X��d�d�誺�K���@�㤧�@�C
LONG
);
        set_weight(291);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_int",15);
                set("unit", "��");
                set("value",3100);
                set("volume", 2);
                set("material", "gold");
        }
        set("armor_prop/armor",5);
        set("armor_prop/int",2);
        set("armor_prop/dex",2);
  setup();
}
