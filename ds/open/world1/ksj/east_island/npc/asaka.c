#include <ansi.h>
#include <combat.h>
varargs int receive_damage(string type, int damage, object who);
inherit NPC;
inherit SSERVER;
void normal_ai();
void combat_ai();

void create()
{
  set_name("日向．朝霞" , ({ "hyuuga asaka","asaka" }) );
  set("long",@long
綁著一條長長的馬尾，身材高挑的妙齡少女，但是她臉上卻沒有同齡
女孩所應該有的純真浪漫，反而是一種久經滄桑的堅毅表情，美麗和
服的腰間配上一把太刀給人一種難以親近的感覺。
long
);
  create_family( HIC "出神流" NOR ,2,"弟子");
  set("level",40);
  set("race","人類");
  set("age",20);
  set("title",HIC"出神流"NOR);
  set("class1","出神流");
  set("gender","女性");
  set("asaka",1);
  set("apeman-enemy",1);
  set("str",80);
  set("con",90);
  set("int",55);
  set("dex",71);
  set_temp("apply/hit",40);
  set_temp("apply/dodge",40);
  set_skill("blade", 90);
  set_skill("sword", 90);
  set_skill("parry", 90);
  set_skill("dodge", 90);
  set_skill("unarmed",80);
  set("addition_damage",30);
  set("addition_armor",120);
  set("talk_reply","您好。");
  set("inquiry/秋川．旭","阿！那是我父親的名字，但我我已不記得他的面貌了。\n");
  set("inquiry/鬼人","村子裡的人都這樣稱呼我父親，聽說是因為他的刀法出神入化。\n");
  set("inquiry/柳生．星明","柳生叔叔自小撫養我長大，但關於父親的事情他始終不提。\n");
  set("inquiry/柳生．奧太郎","太郎是我從小到大的玩伴，也是切磋刀法的對手。\n");
  set("inquiry/出神流","那是父親自創的刀法，我只略懂一二。\n");
  set("chat_chance", 50);
  set("chat_msg",({
     (: normal_ai() :),
     }) );
  set("chat_chance_combat",100);
  set("chat_msg_combat", ({
     (: combat_ai() :),
     }) );
  setup();
  set_living_name("_NPC_ASAKA_");
  carry_object(__DIR__"eq/chrysoprase-earring")->wear();
  carry_object(__DIR__"eq/kiku-ichimonji-katana")->wield();
  carry_object(__DIR__"eq/genki-pill");
  carry_object(__DIR__"eq/genki-pill");
  carry_object(__DIR__"eq/genki-pill");
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if( this_player()->query("tengu") ) this_object()->kill_ob(this_player());
  if( this_player()->query("apeman") ) this_object()->kill_ob(this_player());
/*
  if( this_player()==this_object()->query_temp("last_opponent") )
  {
    if( this_object()->is_busy() ) return;
    message_vision(HIG"(已有防備)"NOR"日向．朝霞一個屈身翻轉，繞到$N背後攻個措手不及！！\n"NOR,this_player() );
    this_player()->add_busy(random(2)+1);
  }
*/
}

int accept_object(object who,object ob)
{
  object obj,letter;
  obj=this_object();

  if(obj->is_busy() || obj->is_fighting())
  {
    command("whisper "+who->query("id")+" 我沒空，別來煩我。\n");
    return 0;
  }
  if(ob->query("id") == "hoshiakari's letter")
  {
    message_vision("$N拿給日向．朝霞一封 "+ob->query("name")+"。\n",who);
    command("hmm");
    message_vision("日向．朝霞拿起信仔細地看了一遍，眼框不由得充滿淚\水。\n",who);
    if( who->query("level") <30 )
    {
      command("say 感謝你的傳達，我會自己想法子找父親的。");
      return 1;
    }
    command("say 你可知我父親現在何處？");
    who->set_temp("go_with_asaka",1);
    destruct(ob);
    return 1;
  }
  return 0;
}

void relay_say(object me, string str)
{
  object ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;

  if( (strsrch(str,"知") != -1) && (me->query_temp("go_with_asaka") == 1) )
  {
    command("say 請帶我隨行，讓我見父親一面！");
    call_out("do_follow",1,me);
    me->delete_temp("go_with_asaka");
    return;
  }
  return;
}

int do_follow(object me)
{
  this_object()->set_leader(me);
  call_out("no_follow",300);
//  command("follow "+me->query("id"));
  return 1;
}

int no_follow()
{
  command("say 怎麼搞的這久還沒到？不跟了！");
  this_object()->set_leader(0);
  return 1;
}

void normal_ai()
{
  object me,z;
  me = this_object();
  if( me->is_busy() ) return;

  if( !me->query_temp("weapon") && objectp(z=present("katana",me)) )
    command("wield katana");
  if( me->query("hp") + 1500 < me->query("max_hp") )
    command("eat pill");
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
    command("wield katana");
  if( me->query("hp") + 1500 < me->query("max_hp") )
    command("eat pill");
  if(!random(15))
  {
    me->start_busy(1);
    message_vision(HIR"$N怒氣一起，雙眼緊緊盯住$n。\n"NOR,me,target );
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
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
  if(random(100)<30)
  {
    damage/=4;
    message_vision(HIW"\n$N以柔軟的身段，險險避開了直接攻擊。\n" NOR,this_object());
  }
    if(damage<1) damage = 1;
  if(objectp(who) )
    ::receive_damage(type,damage,who);
  else
    ::receive_damage(type,damage,who);
  return damage;
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
  ob->add("popularity",2);      
  tell_object(ob,HIG"你得到 2 點聲望。"NOR);
  ::die();
  return;
}
