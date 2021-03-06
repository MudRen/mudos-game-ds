#include <ansi2.h>
#include <combat.h>
inherit NPC;
inherit SSERVER;
varargs int receive_damage(string type, int damage, object who);
void normal_ai();
void combat_ai();

void create()
{
  set_name(HBK"黑天狗"NOR, ({"black tengu","tengu","_BLACK_TENGU_"}) );
  set("long",@LONG
天狗中的最強者，也是眾天狗的首領，體型明顯較一般天狗強壯，穿
著純黑的衣服，雙手揮舞著奇怪的兵刃。
LONG
);
  set("race", "人類");
  set("unit","隻");
  set("age",150);
  set("attitude", "aggressive");
  set("evil",70);
  set("title",HIW"天狗首領"NOR); 
  set("gender", "男性" );
  set("level",60);
  set("int",86);
  set("con",140);
  set("str",120);
  set("dex",100);
  set_skill("unarmed",90);
  set_skill("blade",90);
  set_skill("sword",90);
  set_skill("dodge",100);
  set_skill("parry",80);
  set_temp("apply/hit",40);
  set_temp("apply/dodge",60);
  add("addition_armor",150);
  add("addition_shield",50);
  set("talk_reply","竟闖來此，真是不知死活！\n");
  set("inquiry/鬼人","就是秋川．旭那老頭，龜縮在南方的竹林裡。\n");
  set("chat_chance", 80);
  set("chat_msg",({
     (: normal_ai() :),
     }) );
  set("chat_chance_combat",200);
  set("chat_msg_combat", ({
     (: combat_ai() :),
     }) );
  set("can_defend", 1);
  setup();
  set_living_name("_NPC_BLACK_TENGU_");
  carry_object(__DIR__"eq/hide-bone-katana")->wield();
  carry_object(__DIR__"eq/black-tengu-cloth")->wear();
  carry_object(__DIR__"eq/angry-mask")->wear();
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if( this_player()->query("tengu-enemy") ) this_object()->kill_ob(this_player());
  if(userp(this_player()) )
    this_object()->kill_ob(this_player());
  if( this_player()==this_object()->query_temp("last_opponent") )
  {
    message_vision(HIG"(已有防備)"HBK"黑天狗"HIW"朝著$N吐出一團白煙，$N一時間雙眼無法視物！！\n"NOR,this_player() );
    this_player()->add_busy(random(2)+1);
  }
}

void normal_ai()
{
  object me,target,ob1,ob2,ob3,z;
  me = this_object();
  ob1=find_living("_NPC_PROTECT_TENGU1_");
  ob2=find_living("_NPC_PROTECT_TENGU2_");
  ob3=find_living("_NPC_PROTECT_TENGU3_");

  if(me->is_busy()) return;
  if( !me->query_temp("weapon") && objectp(z=present("katana",me)) )
  { 
    command("wield katana");
  }
  if( !me->query_temp("weapon") && objectp(z=present("sword",me)) )
  { 
    command("wield sword");
  }

  if( me->query("hp") + 300 < me->query("max_hp") )
  {
    message_vision("\n$N"HIG"拿出秘製的傷藥，塗在身上的傷口。\n\n"NOR,me);
    me->receive_heal("hp",300);
    me->start_busy(3);
    return;
  }

  switch( random(30) )
  {
     case  0: 
           message_vision("$N說道：要不是鬼人的阻擋，我早就攻入村莊了。\n",me);
           break;
     case  1:
           message_vision("$N說道：可恨的鬼人，上次大戰中殺了我不少手下。\n",me);
           break;
     case  2:
           message_vision("$N摸著胸前的傷疤說道：鬼人的刀法真是出神入化，無人能敵。\n",me);
           break;
     case  3:
           message_vision("$N舞動身後的黑色雙翼，捲起一陣旋風。\n",me);
           break;
     case  4:
           if( objectp(ob1) || objectp(ob2) || objectp(ob3) )
           {
             message_vision("$N對著"HIC"守護天狗"NOR"說道：沒事了，你們下去吧。\n",me);
             destruct(ob1);
             destruct(ob2);
             destruct(ob3);
           }
           break;
   }
  return;
}

void combat_ai()
{
  int hp,mp,ap,max_hp,max_mp,max_ap;
  object b,ob1,ob2,ob3,me,target;
  ob1=find_living("_NPC_PROTECT_TENGU1_");
  ob2=find_living("_NPC_PROTECT_TENGU2_");
  ob3=find_living("_NPC_PROTECT_TENGU3_");
  me=this_object();
  target = offensive_target(me);
  hp=this_object()->query("hp");
  mp=this_object()->query("mp");
  ap=this_object()->query("ap");
  max_hp=this_object()->query("max_hp");
  max_mp=this_object()->query("max_mp");
  max_ap=this_object()->query("max_ap");

  if( objectp(ob1) )
  {
    if(!environment(ob1) )  destruct(ob1);
  }
  else if( hp < (max_hp-2000) )
  {
    if(query_temp("wait_to_summon")) return;
    b=new(__DIR__"protect-tengu1" );
    b->move(environment(this_object()));
    message_vision("\n$N"HIW"由空中飛降而下，說道：守護天狗參上！\n" NOR,b);
    set_temp("wait_to_summon",1);
    call_out("delay",20);
    return;
  }
  if( objectp(ob2) )
  {
    if(!environment(ob2) )  destruct(ob2);
  }
  else if( hp < (max_hp-2500) )
  {
    if(query_temp("wait_to_summon")) return;
    b=new(__DIR__"protect-tengu2" );
    b->move(environment(this_object()));
    message_vision("\n$N"HIW"由空中飛降而下，說道：守護天狗參上！\n" NOR,b);
    set_temp("wait_to_summon",1);
    call_out("delay",20);
    return;
  }
  if( objectp(ob3) )
  {
    if(!environment(ob3) )  destruct(ob3);
  }
  else if( hp < (max_hp-3000) )
  {
    if(query_temp("wait_to_summon")) return;
    b=new(__DIR__"protect-tengu3" );
    b->move(environment(this_object()));
    message_vision("\n$N"HIW"由空中飛降而下，說道：守護天狗參上！\n" NOR,b);
    set_temp("wait_to_summon",1);
    call_out("delay",20);
    return;
  }
  if(me->is_busy()) return;
  if( !me->query_temp("weapon") )
  { 
    command("wield katana");
    command("wield sword");
  }
  if(!random(12))
  {
    COMBAT_D->do_attack(me,target,me->query_temp("weapon"),4);
    COMBAT_D->report_statue(target);
    return;
  }
  return;
}

varargs int receive_damage(string type, int damage, object who)
{
  int val;
  if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
  if( type!="hp" && type!="mp" && type!="ap" )
      error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");
  if( objectp(who) && type=="hp") set_temp("last_damage_from", who);
  if(random(100)<20)
  {
    damage=0;
    message_vision("\n$N"HIW"化為一團煙霧，閃開了這次的攻擊。\n" NOR,this_object());
  }
  if(objectp(who) )
    ::receive_damage(type,damage,who);
  else
    ::receive_damage(type,damage,who);
  return damage;
}

void delay()
{
  this_object()->delete_temp("wait_to_summon");
}

void die()
{
  object ob,ob1,ob2,ob3;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  ob1=find_living("_NPC_PROTECT_TENGU1_");
  ob2=find_living("_NPC_PROTECT_TENGU2_");
  ob3=find_living("_NPC_PROTECT_TENGU3_");
  if( objectp(ob1) && environment(ob1) )  destruct(ob1);
  if( objectp(ob2) && environment(ob2) )  destruct(ob2);
  if( objectp(ob3) && environment(ob3) )  destruct(ob3);
  message("world:world1:vision",
  HIM"\n\t【櫻花林】："+HBK" 黑天狗 "HIW" 死在智勇雙全的"HIY+ob->name(1)+HIW"手下，從此村民不再擔心天狗的侵犯了。\n\n"+NOR
    ,users());
  ob->add("popularity",7);      
  tell_object(ob,HIG"你得到 7 點聲望。"NOR);
  ob->set_temp("kill_black_tengu",1);
  ::die();
  return;
}
