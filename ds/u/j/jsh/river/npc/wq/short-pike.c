#include <weapon.h>
inherit FORK;
void create()
{
        set_name("短槍",({"short pike","pike"}) );
        set("long","一桿尋常的鐵鑄短槍，一眼便知是尋常鐵匠打造出來的。\n");
          set_weight(5200);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("unit","桿");
          set("value",500);
                set("volume",4);
        set("material","iron");
        init_fork(12);
   }
        setup();
}

