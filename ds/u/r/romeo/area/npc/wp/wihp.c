#include <weapon.h>

inherit WIHP;

void create()
{
        set_name("����@",({"moon-wihp","wihp"}) );
        set("long","����ѤE�Ѥ��۳y�������@�A�]��`���s�뤧�Φӱo�W�C\n");
          set_weight(1500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","��");
                    set("material", "rock");
      set("value",900);
        }
          init_wihp(8);
        setup();
}

