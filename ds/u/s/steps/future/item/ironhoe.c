#include <weapon.h>
inherit STAFF;
void create()
{
          set_name("鐵鋤",({"iron hoe","hoe"}));
          set("long","一把普通的鐵鋤，可以用來挖掘和翻鬆泥土。\n");
          set_weight(5000);
          if (clonep() )
          set_default_object(__FILE__);
          else {
          set("unit","把");
          set("value",100);
          set("material","iron");
          init_staff(10);
          } 
          setup();
}
