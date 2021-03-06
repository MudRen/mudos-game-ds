#include <ansi.h>
inherit NPC;

void create()
{
        set_name("憑依泥偶",({"mud puppet","puppet","_MUD_PUPPET_"}) );
        set("long",@LONG
一個由泥土聚集而成，比一般人稍為高大一點的泥偶。
LONG);
        set("race", "monster");    
        set("unit","個");
        set("level",20+random(6));
        set("limbs", ({ "頭部", "身體","手部","腳部"}) ); 
        set("verbs", ({ "crash" }) );
        add("addition_armor",50);
        add("addition_damage",10);
        set("chat_chance", 50);
        set("chat_msg", ({
           (:command("defend oldwoman"):),
           }) );     
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
           (:command("defend oldwoman"):),
           }) );     
        setup();
        set_living_name("_NPC_MUD_PUPPET_");
}

void init()
{
    ::init();
    if( environment(this_player())->query("no_kill") ) return;
    if( environment(this_player())->query("no_fight") ) return;
    if(!this_object()->visible(this_player())) return;
    if(userp(this_player()) )
      this_object()->kill_ob(this_player());
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(4))
  {
   if( random(target->query_dex()) < 20)
   {
    message_vision(YEL"\n$N撲向$n的方向在地上形成一灘爛泥，$n一時雙足被泥濘拌住！\n\n"NOR, this_object(), target);
    target->add_busy(2);
    me->start_busy(3);
    return 1;
   }
   else
   {
    message_vision(YEL"\n$N撲向$n的方向在地上形成一灘爛泥，但是$n及時閃了開來。\n\n"NOR, this_object(), target);
    me->start_busy(3);
    return 1;
   }
  }
  return 0;
}

/*
void die()
 {
   message_vision("\n$N受創過重，崩解成一地的泥塊。\n",this_object());
   destruct(this_object());
   ::die();
   return;
 }

*/
