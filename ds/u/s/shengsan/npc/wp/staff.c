#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name(HIC"吸星法杖"NOR,({"staff"}));
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "把");
               set("long", "這是一把用來撐著走路用的手杖，尤其走山路時特別好用。\n");
               set("material", "wood");
        }
	init_staff();
	setup();
}
