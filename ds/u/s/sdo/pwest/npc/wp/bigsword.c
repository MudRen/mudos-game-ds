#include <weapon.h>
inherit SWORD;
void create()
{
   	set_name("大劍",({"big sword","sword"}));
   	set("long","比一般的長劍還要重，但是攻擊力也比較高。\n");
   	set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("limit_str",15);
          	set("value",2500);
                set("volume",3);
                set("material","iron");
        }
	init_sword(28);
        setup();
}
