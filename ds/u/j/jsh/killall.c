#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"����"NOR,({"item of killall","killall","item"}));
        set("long",
        "�@���i�H�����P�@��Ҧ��� NPC�C\n"); 
        set_weight(5000);
                set("no_sell",1);
                set("can_give",1);
                set("unit","��");
        setup(); 
 
}  
int query_autoload() { return 1; } 
void init()
{
 add_action("do_killall","killall");
}
int do_killall(string arg)
{
  object *inv,me=this_player();
  int i;
  inv = all_inventory(environment(this_object()));
  if(!inv) return;
  if(!me) return;

  message_vision(HIR"$N�}�l�����o�̩Ҧ����H�I\n"NOR,me); 
  switch(random(2))
  {
  case 0:
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      if( inv[i]->query_temp("invis")>2 ) continue;
      inv[i]->kill_ob(me);
      COMBAT_D->report_status(inv[i]);  
    } 
   }
   me->start_busy(2);   break;
   case 1:
      message_vision(HIB"\n$N�ߥ��x��..���������F..\n\n"NOR,inv[i]);
      me->start_busy(3);
  } 
  return 1; 
   
}

