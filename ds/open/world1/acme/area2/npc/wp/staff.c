#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name("青鋼杖",({"green steel staff","staff"}));
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("limit_str",8);
               set("limit_con",6);
               set("unit", "把");
               set("long", "這是一把用青鋼所冶鍊而成的長杖，相當沉重。\n");
		set("volume",4);
              set("value",2000);
               set("material", "copper");
        }
    init_staff(30);
   setup();
}
