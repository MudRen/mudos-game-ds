#include <weapon.h>
inherit SWORD;
void create()
{
   	set_name("�j�C",({"big sword","sword"}));
   	set("long","��@�몺���C�٭n���A���O�����O�]������C\n");
   	set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("limit_str",15);
          	set("value",2500);
                set("volume",3);
                set("material","iron");
        }
	init_sword(28);
        setup();
}
