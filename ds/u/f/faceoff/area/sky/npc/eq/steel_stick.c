#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
        set_name(HIW"鋼棍"NOR,({"steel stick","stick"}) );
          set("long","這是一把由劣等鋼打造的鋼棍!\n");
          set_weight(2000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","把");
                set("volume",2);
      set("value",1200);
        }
init_staff(15);
        set("armor_prop/str",1);
        set("material","steel");
        setup();        
}
