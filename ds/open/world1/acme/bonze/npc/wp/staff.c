#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name("烏木禪杖",({"black wood staff","staff"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("limit_str",8);
               set("limit_con",6);
               set("unit", "把");
               set("long", "這是一把用上好烏木所製成的長杖，威力相當不錯。\n");
		set("volume",6);
               set("value",6000);
               set("material", "wood");
		set("limit_str",30);
		set("limit_int",15);
		set("limit_con",25);
        }
    init_staff(60,TWO_HANDED);
   setup();
}
