#include <weapon.h>
inherit FORK;
void create()
{
        set_name("長槍",({"long pike","pike"}) );
        set("long","一根長長的鐵棒，在頭的一端裝上了槍頭，可傷到五步外的敵人。\n");
          set_weight(5200);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("unit","桿");
          set("value",500);
                set("volume",4);
        set("material","iron");
        init_fork(35);
   }
        setup();
}

