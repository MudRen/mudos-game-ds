#include <weapon.h>
inherit SWORD;
void create()
{
   set_name("柳葉劍",({"lau yip sword","sword"}));
   set("long","這是一把形狀如柳葉般細細長長的劍。\n");
   set_weight(3000);   //設重量
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
		set("volume",2);
              set("value",1500);
                set("material","iron");
        }
init_sword(23);
        setup();
}
