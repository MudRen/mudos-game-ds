#include <weapon.h>
inherit SWORD;
void create()
{
   	set_name("���C",({"long sword","sword"}));
   	set("long","�@���H�B�i�������C�C\n");
   	set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("limit_str",10);
          	set("value",2000);
                set("volume",2);
                set("material","iron");
        }
	init_sword(20);
        setup();
}
