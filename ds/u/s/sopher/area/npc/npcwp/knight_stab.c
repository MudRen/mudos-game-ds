#include <weapon.h>
#include <ansi.h>
inherit FORK;

void create()
{
      set_name(HIY"�M�h�Դu"NOR, ({ "knight stab","stab" }) );
      set_weight(1000);
      if( clonep() )
      set_default_object(__FILE__);
      else {
             set("unit","��");
             set("value",10000);
             set("material","steel");
        }
       init_fork(50);

       setup();
}    
