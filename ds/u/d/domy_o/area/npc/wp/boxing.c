#include <weapon.h>

inherit FIST;

void create()
{
    set_name("������M",({"boxing fist","boxing","fist"}) );
   set("long","�`����������M�C\n");
        set_weight(2000);
  if (clonep() )
             set_default_object(__FILE__);
    else {
        set("unit","��");
         set("value",1000);
        set("material","iron");
      init_fist(10);
   }
setup();
}


