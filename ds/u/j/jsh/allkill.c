#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"全攻器"NOR,({"item of killall","killall","item"}));
        set("long",
        "一次可以攻擊同一格所有的 NPC。\n"); 
        set_weight(5000);
                set("no_drop",1);
                set("can_give",1);
                set("unit","個");
        setup(); 
 
} 
int query_autoload() { return 1; }
void init()
{
 add_action("do_killall","killall");
}
void do_killall(object me)
{
  object *inv;
  int i, damage;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  message_vision(HIR"$N開始攻擊這裡所有的東西！\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      if( inv[i]->query_temp("invis")>2 ) continue;
      message_vision(HIW"$N開始攻擊"+inv[i]->query("name")+"\n"NOR,inv[i]); 
      me->kill(inv[i]);
      COMBAT_D->report_status(inv[i]); 
    }
       me->start_busy(1); 
   }
  return;
}

