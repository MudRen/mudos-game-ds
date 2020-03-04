// TURTLEF.c
#include <path.h>
#include <ansi.h>
inherit NPC;

    void create()
{set_name(HIY"海龜長老"NOR,({"elder turtle","turtle"}) );
set("gender", "男性");
set("level",50);
//set("ridable",1);
set("age",100);
set("evil",-300);
set("long", "一隻笨重的大海龜，背上還有一些小孔。\n");
//set_temp("apply/armor",240);
set_temp("apply/damage",180);
set("limbs", ({ "頭部", "身體", "前腳", "後腳","腹部"}));
set("verbs", ({ "bite"}));
set("chat_chance",10);
set("chat_msg",({
(:command,"say 你們找我是想問我什麼事嗎? ":),
"老海龜很生氣的看著你.\n",
}) );
 setup();
 load_object(__DIR__"halfshark");
 set_heart_beat(1);
}

void init()
{
add_action("do_ask","ask");
}

int do_ask(string arg)
{
 object obj,me;
 mixed msg;
 string who;
 me=this_player();
 msg=({
  " 嗯.. 讓我想想..",
  " 賽拉是上個世紀最偉大的建築師.. 本鎮的修道院就是他建造的..",
  " 對了!!上次有個傢伙偷拿了一張有關於修道院秘密的字條給我.可惜我看不懂..",
 });
 if(arg=="turtle about sala" || arg=="elder about sala" )
 {
 message_vision("$N向"HIY"海龜長老"NOR"打聽有關『sala』的消息。\n",me);
 call_out("do_say",2,msg[0]);
 call_out("do_say",5,msg[1]);
 call_out("do_say",8,msg[2]);
 if(!query("no_give"))
 {
  call_out("do_give",11,me);
 } else 
 {
  who=query("no_give");
  call_out("do_shake",11,who,me);
 }
 return 1;
 }
 return 0;
}
int do_shake(string who,object me)
{
 tell_object(environment(this_object()),HIY"海龜長老說道: "
 +"我已經把那張只拿給"+who+"了.. 你晚了一步喔..\n"NOR);
 message_vision("海龜長老拍拍$N的肩膀..\n",me);
 return 1;
}

int do_say(string str)
{
tell_object(environment(this_object()),HIY"海龜長老說道: "+str+"\n"NOR);
return 1;
}

int do_give(object me)
{
 object obj;
 tell_object(environment(this_object()),HIY"海龜長老說道: "
 +"就是這個.. 你拿去好了, 反正我留著也沒什麼用.\n"NOR);
 this_object()->command("say "," 就是這個.. 你拿去好了, 反正我留著也沒什麼用.");
 obj=new(__DIR__"item/paper");
 if ( (obj->query_weight()+me->query_encumbrance())>me->query_max_encumbrance() )
 {
  command("look "+this_player()->query("id"));
  command("say 可是你身上東西太多了, 大概給你也拿不動..下次吧!");
  return 1;
 }
 obj->move(me);
 message_vision("海龜長老給$N一張紙.\n",me);
 this_object()->set("no_give",me->query("id"));
 return 1;
}

void heart_beat()
{
 object *enemy,ene;
 object me;
 int damage;
 int i;
 if(!me=this_object()) return;
 if(me->is_fighting())
 {
  if(me->query("hp")<30000 && me->query_temp("change")<1)
  {
   message_vision(HIR"\n\n好傢伙!!! 看來不拿出真本事是不行了..\n\n"
   +HIB+" 大 海 龜 的 背 上 突 然 伸 出 許\ 多 毒 刺 !!! \n "NOR,me);
   me->set_temp("change",1);
   me->add("str",30);
   me->add("dex",30);
   me->set("max_hp",30000);
   me->add_temp("apply/damage",200+random(100));
   me->add_temp("apply/armor",200+random(100));
   me->set_name(HIM"刺龜"NOR,({"needle turtle","turtle"}));
   me->set("long","一隻背上長滿毒刺的海龜。"HIR"(牠似乎非常生氣)\n"NOR);
  }
  ene = me->query_temp("last_damage_from");
  if(!ene) return;
  if(!present(ene->query("id"),environment(me)) ) return ;
  
  if(me->query_temp("change")==1)
  {
   if( me->is_fighting() )
   if(random(300)>200)
   {
    damage=1400+random(1000)-ene->query_temp("apply/armor");
    if(damage<500) damage=500+random(300);
    if(random(100)>62)
    {
     message_vision("$N"HIC"突然往你的方向衝過來,重重的向$n一撞,造成"HIR+damage+HIC"傷害!\n"
     NOR,me,ene);
     ene->receive_damage("hp",damage,me);
     COMBAT_D->report_status(ene,1);
    }
   }
  }
//if(me->query("hp")<0)
//command("begin war");
  ::heart_beat();
 }
 if(me)
 {
  if(me->query("hp")<0)
  me->die();
 }
}

void die()
{
object ob;
if( !ob = query_temp("last_damage_from") )
 ob = this_player(1);
ob->set_temp("kill_turtle",1);
if( !ob ) return;
shout(HIC"\n\n\n          大海中傳來一陣哀嚎∼∼∼\n\n"
+HIR"              啊∼啊∼∼∼∼\n\n"
HIB"        平靜的海面掀起了陣陣的狂濤巨浪 \n\n"NOR);
shout(HIW"大海龜痛苦的大叫: 你∼∼ 愚蠢的"HIY+ob->query("name")+HIW"啊!! 海神是不會放過你的!!!"+
HIR"\n\n      我神海克力斯啊∼∼請幫我守護這片大海吧!!! \n\n"NOR);
environment(this_object())->set("war",1);
    ::die();
}
