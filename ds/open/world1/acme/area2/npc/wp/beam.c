#include <weapon.h>
inherit WHIP;
void create()
{
set_name("秤桿",({"beam"}));
set("long","這是一把用來秤量東西的秤桿。\n");
set_weight(2000);   //設重量
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("limit_int",10);
set("unit", "把");
set("value",1500);
set("material","iron");
        }
init_whip(30);
        setup();
}
