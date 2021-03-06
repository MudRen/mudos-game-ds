#include <ansi.h>
#include <combat.h>
#include <path.h>
inherit NPC;
inherit SSERVER;
void normal_ai();
void combat_ai();

void create()
{
  set_name("柳生．筧" , ({ "yagyuu ken","ken" }) );
  set("long",@long
新陰流的創始者，在當世刀法號稱天下無雙，二十幾年前將道場交給
獨子柳生．星明後，孤身前往討伐大蛇，其後渺無音訊，謠傳已經身
亡，由於長年冰封，外表仍然是中年形態，體型魁武。
long
);
  create_family( HIC "新陰流" NOR ,2,"高手");
  set("level",60);
  set("race","人類");
  set("age",68);
  set("title",HIR"刀法無雙"NOR);
  set("class1","新陰流");
  set("gender","男性");
  set("orochi-enemy",1);
  set("orochi_beast_3",1);
  set("str",130);
  set("con",130);
  set("int",87);
  set("dex",100);
  set_temp("apply/hit",50);
  set_temp("apply/dodge",50);
  set_skill("blade", 100);
  set_skill("sword", 100);
  set_skill("parry", 100);
  set_skill("dodge", 100);
  set_skill("unarmed",100);
  set_temp("apply/armor",100);
  set("chat_chance", 20);
  set("chat_msg",({
     (: normal_ai() :),
     (: random_move :),
     }) );
  set("chat_chance_combat",100);
  set("chat_msg_combat", ({
     (: combat_ai() :),
     }) );
  setup();
  set_living_name("_NPC_KEN_");
  carry_object(__DIR__"eq/red-armor")->wear();
  carry_object(__DIR__"eq/douzikiri-katana")->wield();
  carry_object(__DIR__"eq/genki-pill");
  carry_object(__DIR__"eq/genki-pill");
  carry_object(__DIR__"eq/genki-pill");
  carry_object(__DIR__"eq/genki-pill");
  carry_object(__DIR__"eq/genki-pill");
}

void init()
{
  ::init();
  if(!this_object()->visible(this_player())) return;
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if( this_player()->query("orochi") ) this_object()->kill_ob(this_player());
}

void normal_ai()
{
  object me,z;
  me = this_object();

  if( !me->query_temp("weapon") && objectp(z=present("katana",me)) )
  { 
    command("wield katana");
  }
  if( me->query("hp") + 1500 < me->query("max_hp") )
  {
    command("eat pill");
  }
  return;
}

void combat_ai()
{
    object me,target,z;
  me=this_object();
  target = offensive_target(me);
  if(!me) return;
  if(me->is_busy()) return;
  if( !me->query_temp("weapon") && objectp(z=present("katana",me)) )
  { 
    command("wield katana");
  }
  if( me->query("hp") + 1500 < me->query("max_hp") )
  {
    command("eat pill");
  }
  if(!random(15))
  {
    me->start_busy(1);
    message_vision(HIR"$N大叫一聲，全身凝聚氣力。\n"NOR, this_object() );
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
    COMBAT_D->report_statue(target);
    return;
  }
  return;
}

void die()
{
  object ob;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  message("world:world1:vision",
  HIC"\n\t【東方島】："HIW"刀法無雙的"+HIG" 新陰流老師範 "HIW"柳生．筧 隕落於"HIY+ob->name(1)+HIW"之手。\n\n"+NOR
    ,users());
  ob->add("popularity",5);      
  tell_object(ob,HIG"你得到 5 點聲望。"NOR);
  ::die();
  return;
}
