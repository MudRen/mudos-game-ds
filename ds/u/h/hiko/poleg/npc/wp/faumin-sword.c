#include <weapon.h>
inherit SWORD;
void create()
{
   set_name("楓銘劍",({"fau min sword","sword"}));
   set("long","這是一把有著楓葉雕飾並還有銘文的劍。\n");
   set_weight(3000);   //設重量
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("volume",2);
              set("value",3500);
                set("material","iron");
        }
init_sword(25);
        setup();
}

