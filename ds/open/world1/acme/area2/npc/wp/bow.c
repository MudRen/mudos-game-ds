#include <weapon.h>
inherit BOW;
void create()
{
   set_name("穿山弩",({"put kop bow","bow"}));
   set("long","這是一把能夠百步穿揚的神弩，可用(shoot)射出箭。\n");
   set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value",230);
             set("value",1500);
                set("material","wood");
                set("limit_int",6);
		set("volume",3);
                set("limit_dex",6);
                set("limit_str",4);
     }
init_bow(30);
        setup();
}
