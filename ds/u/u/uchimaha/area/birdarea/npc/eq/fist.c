#include <weapon.h>
inherit FIST;

void create()
{
    set_name("�N��",({"eagle claw","claw"}) );
   set("long","�@����N�����l�C\n");
        set_weight(2000);
  if (clonep() )
             set_default_object(__FILE__);
    else {
        set("unit","��");
        set("value",600);
        set("material", "leather");
        init_fist(20);
   }
setup();
}
