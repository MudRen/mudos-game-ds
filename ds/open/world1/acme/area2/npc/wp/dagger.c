#include <ansi.h>
#include <weapon.h>
inherit DAGGER;
void create()
{
        set_name("虎柄椎" , ({ "tiger dagger","dagger" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "把");
               set("long", "這是在把柄處雕著虎頭的匕首，使將起來，定是虎虎生風。\n");
               set("value",1000);
               set("material", "iron");
        }
    init_dagger(23);
   setup();
}
