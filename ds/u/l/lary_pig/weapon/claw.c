#include <weapon.h>
#include <ansi.h>

inherit FIST;

void create()
{
  set_name("��",({"Claw", "claw" }) );
  set("long","
�@��Z�N�a�Ϊ����C
\n");
      set_weight(0);
  if (clonep() )
             set_default_object(__FILE__);
    else {
      set("unit","��");
      set("value",0);
      set("material","iron");
      init_fist(99);
   }
setup();
}
