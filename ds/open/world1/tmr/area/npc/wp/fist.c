#include <weapon.h>

inherit FIST;

void create()
{
    set_name("����",({"tiger fist","fist"}) );
   set("long","�@���Kű������A�Ψӥ��H���G���h���C\n");
        set_weight(2000);
  if (clonep() )
             set_default_object(__FILE__);
    else {
        set("unit","��");
            set("value",600);
        set("material","iron");
      init_fist(10);
   }
setup();
}
