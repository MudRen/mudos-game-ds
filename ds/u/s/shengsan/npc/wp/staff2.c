#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name(HIC"吸月法杖"NOR,({"staff2"}));
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "把");
               set("long", "這是一把用來撐著走路用的手杖，尤其走山路時特別好用。\n");
               set("material", "wood");
               set("add_value",100);	// 加價值 100
        }
	init_staff(100);		// 加傷害力 100
	setup();
}
