#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
        set_name(HIW"����"NOR,({"steel stick","stick"}) );
          set("long","�o�O�@��ѦH�������y������!\n");
          set_weight(2000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","��");
                set("volume",2);
      set("value",1200);
        }
init_staff(15);
        set("armor_prop/str",1);
        set("material","steel");
        setup();        
}
