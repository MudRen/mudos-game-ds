#include <weapon.h>
inherit FORK;
void create()
{
        set_name("���j",({"long pike","pike"}) );
        set("long","�@�ڪ������K�ΡA�b�Y���@�ݸˤW�F�j�Y�A�i�˨줭�B�~���ĤH�C\n");
          set_weight(5200);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("unit","��");
          set("value",500);
                set("volume",4);
        set("material","iron");
        init_fork(35);
   }
        setup();
}

