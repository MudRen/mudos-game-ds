#include <weapon.h>
inherit FIST;

void create()
{
    set_name("�N��",({"eagle claw","claw"}) );
   set("long","�@����N�����l�C\n");
   set_weight(6000);
   if (clonep() )
             set_default_object(__FILE__);
   else {
        set("unit","��");
        set("value",1600);
        set("material", "leather");
    }
    init_fist(35);
setup();
}


