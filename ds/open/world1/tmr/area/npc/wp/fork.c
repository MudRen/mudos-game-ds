#include <weapon.h>
inherit FORK;
void create()
{
        set_name("�u�j",({"short pike","pike"}) );
        set("long","�@��M�`���Kű�u�j�A�@���K���O�M�`�K�K���y�X�Ӫ��C\n");
          set_weight(5200);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("unit","��");
          set("value",500);
		set("volume",4);
        set("material","iron");
        init_fork(12);
   }
        setup();
}


