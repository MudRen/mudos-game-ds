#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
        set_name(HIW"法天棍"NOR, ({ "fa-tian cape","cape" }));
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "暇日谷王師傅所打造的棍，此棍鋒利，但是勁道不足，所以只適合初習爪的棍專用。\n");
                set("value", 2000);
                set("material", "steel"); 
                }
        init_staff(30);
        set("weapon_prop/bio", 1);
                setup();
}

