#include <weapon.h>

inherit AXE;

void create()
{
        set_name("魍魎巨斧",({"ghost-axe","axe"}) );
        set("long","由有道行之士，在極陰之地收集七七之數的鬼魅魍魎，封入巨斧內而成。\n");
          set_weight(1700);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","把");
                    set("material", "rock");
      set("value",900);
        }
          init_axe(8);
        setup();
}
