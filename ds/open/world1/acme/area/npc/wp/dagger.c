#include <weapon.h>
inherit DAGGER;

void create()
{
set_name("匕首",({"dagger"}));
set("long","這是一般尋常人所佩帶來防身用的匕首。\n");
set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",400);
set("material","iron");
        }
init_dagger(8);
        setup();
}
int query_autoload() { return 1;} // save eq by alick
