#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
      set_name(HIW"������h����C"NOR, ({ "long sword" }) );
      set_weight(1000);
      if( clonep() )
      set_default_object(__FILE__);
      else {
             set("unit","��");
             set("value",10000);
             set("material","steel");
        }
       init_sword(80);
       
       setup();
}    
