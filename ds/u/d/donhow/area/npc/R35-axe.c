#include <ansi.h>
#include <weapon.h>
inherit AXE;

void create()
{
set_name( RED "R-35" NOR,({"R-35 axe","axe"}));
set("long","一把由Hans出產的工具,之前是拿來開礦所用,後來被應用到戰場上
            由於Hans加入了另一種晶片,比之前的R-35還更猛了些\n");
set_weight(2000);   //設重量
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",30000);    //設價錢
set("material","iron");
init_axe(999);
        }
}
