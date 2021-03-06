#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
  set_name( "竹柺杖" , ({ "bamboo stick","stick" }) );
  set_weight(200);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", "竹製枴杖，輕但不耐用，平常被用來作為老人家的第三隻腳。\n");
    set("material", "bamboo");
    set("value",400);
    set("volume",1);
  }
  init_staff(8);
  setup();
  set_temp("broken",1);
}

void attack(object me, object victim)
{
  ::attack();
  if(!me) return;
  if(!victim) return;
  if(random(3)) add_temp("broken",1);
  if(query_temp("broken") > 10)
  {
    message_vision(HIW"\n『啪』的一聲，$N從中斷成兩截！\n\n"NOR,this_object());
    if( stringp(this_object()->query("equipped")) ) this_object()->unequip();
    destruct(this_object());
  }
  return;
}
