
#include <weapon.h>
inherit FORK;
void create()
{
        set_name("���j",({"field spear","spear"}) );
        set("long","�o�O�@������кj�A�A�X�b���a�����Ҿ԰��άO���y�C\n");
          set_weight(5200);
        if (clonep() )
             set_default_object(__FILE__);
        else {
       		set("unit","��");
         	set("value", 2000);
			set("volume", 4);
        	set("material","iron");
        	init_fork(40);
		}
        setup();
}

