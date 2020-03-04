#include <ansi2.h>
#include <combat.h>
varargs int receive_damage(string type, int damage, object who);
inherit NPC;
inherit SSERVER;
void normal_ai();
void combat_ai();

void create()
{
  set_name("秋川．旭" , ({ "akikawa asahi","asahi","master" }) );
  set("long",@long
多年以前從東方大陸漂流定居在這個小島，以小島上特產的刀融合忍
法，開創出刀法的新境界，名之為－出神流。由於對刀法的狂熱以及
風俗的差異，離群獨自生活在這片竹林中，雖然頭髮已經銀白但身體
看來仍然健壯，尤其雙眼迥迥有神而精光內隱。
long
);
  create_family( HIC "出神流" NOR ,2,"師範");
  set("level",60);
  set("race","人類");
  set("age",65);
  set("title",HIM"鬼人"NOR);
  set("class1","出神流");
  set("gender","男性");
  set("str",140);
  set("con",120);
  set("int",87);
  set("dex",100);
  set_temp("apply/hit",80);
  set_temp("apply/dodge",80);
  set_skill("blade", 100);
  set_skill("parry", 100);
  set_skill("block", 100);
  set_skill("dodge", 100);
  set_skill("unarmed",100);
  set_skill("shinin-ryuu-blade",100);
  set_skill("monkey-dodge",100);
  map_skill("blade","shinin-ryuu-blade");
  map_skill("dodge","monkey-dodge");
  set_temp("apply/armor",150);
  set("talk_reply","你能通過櫻花林到這裡倒也不簡單阿。\n");
  set("inquiry/日向．朝霞","朝霞阿，不知道她現在過得如何，村莊裡的生活會對她比較好。\n");
  set("inquiry/日向．霧子","唉．．．．．\n");
  set("inquiry/天狗","有它們陪我練刀，生活倒也不無聊。\n");
  set("inquiry/山崽","嗯？那是什麼東西？\n");
  set("chat_chance", 50);
  set("chat_msg",({
     (: normal_ai() :),
     }) );
  set("chat_chance_combat",100);
  set("chat_msg_combat", ({
     (: combat_ai() :),
     }) );
  setup();
  carry_object(__DIR__"eq/dragon-marking-waist")->wear();
  carry_object(__DIR__"eq/sakura-ranbu-katana")->wield();
}

void init()
{
  ::init();
  if( this_player()->query_temp("kill_black_tengu") )  {
    remove_call_out("give_pill");
    call_out("give_pill",0,this_player());
  }
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if( this_player()->query("asaka") ) call_out("speaking",0);

}

void normal_ai()
{
   object me;
  me = this_object();
  if( me->is_busy() ) return;

  if( !me->query_temp("weapon") )
  { 
    command("wield katana");
  }
  if( me->query("hp") + 300 < me->query("max_hp") )
  {
    me->start_busy(3);
    message_vision("\n$N"HIG"從懷中取出幾顆藥丸，一口吃了下去。\n\n"NOR,me);
    me->receive_heal("hp",300);
    return;
  }
  switch( random(30) )
  {
     case  0: 
           message_vision("$N揮動長刀以快捷的速度演練招式，每個動作都夾帶強大氣勢。\n",me);
           break;
     case  1:
           message_vision("$N朝你的方向橫揮一刀，強烈風壓使你差點站不住腳。\n",me);
           break;
     case  2:
           message_vision("$N收招歇息，你注意到刀上竟然有電光閃動！\n",me);
           break;
     default: break;
  }
  return;
}

void combat_ai()
{
  object me,target,z;
  me=this_object();
  target = offensive_target(me);
  if(!me) return;
  if(!target) return;
  if(me->is_busy()) return;
  if(!objectp(z=present("katana",me)) )  
  {
    message_vision("\n$N從腰間拔出另一把刀。\n"NOR,me);
    new(__DIR__"eq/ya-katana")->move(me);
  }
  if( objectp(z=present("katana",me)) &&  z->query_durable() < 0 )
  {
    message_vision("\n$N將刀往屋內一丟。\n"NOR,me);
    destruct(z);
  }
  if( !me->query_temp("weapon") && objectp(z) )
  { 
    command("wield katana");
    return;
  }
  if( random(target->query_dex()) < 9)
  {
    me->start_busy(1);
    message_vision(HIM"\n$N對$n使出"HBK"影縛術"HIM"，$n一時全身無法動彈！\n\n"NOR, this_object(), target);
    target->add_busy(3);
    return;
  }
  else if( !random(8) )
  {
    me->start_busy(1);
    message_vision(HIW"$N內力運轉不息，準備使出連擊。\n"NOR,me,target );
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_BERSERK);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_BERSERK);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_BERSERK);
    return;
  }
  else if(!random(8))
  {
    me->start_busy(1);
    message_vision(HIR"$N凝神尋找$n週身的破綻。\n"NOR,me,target );
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
    COMBAT_D->report_statue(target);
    return;
  }
  return;
}

void speaking()
{
  object me,ob1,ob2,env,boots;
  me=this_object();
  ob1=find_living("_NPC_ASAKA_");
  ob2=ob1->query_leader();
  env=environment(ob2);

  command("pat asaka");
  command("look asaka");
  command("say 你是朝霞吧，我看看，都長這麼大啦。");
  command("say 辛苦妳了，孩子，快先進去歇息一下吧。");
  ob1->set_leader(0);
  if( env=environment(me) )
  {
    message_vision("$N轉過身來對著$n說道：感謝你完成我多年來的心願\n"
                  +"，我這有個東西請你收下吧。\n"NOR,me,ob2);
    boots=new_ob(__DIR__"eq/kilin-boots");
    boots->move(me);
    command("give boots to "+ ob2->query("id") );
    return;
  }
  destruct(ob2);
  return;
} 
/*
// report too much 修改 by JS@DS
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
    message_vision(HIW"\n$N以快捷的身法，瞬間已閃躲到攻勢之外。\n" NOR,this_object());
  }
  if(objectp(who) )
    ::receive_damage(type,damage,who);
  else
    ::receive_damage(type,damage,who);
  return damage;
}
*/
void give_pill(object ob)
{
  int i;
  message_vision("\n秋川．旭對著$N說道：閣下真是不簡單，這些丹藥給你養養身子。\n" NOR,ob);
  for(i=0;i<3;i++)
  {
    new(__DIR__"eq/ginseng-pill")->move(this_object());
    command("give pill to "+ ob->query("id") );
  }
  ob->delete_temp("kill_black_tengu");
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
  HIC"\n\t【東方島】："HIW"有鬼人之稱的"+HIG" 出神流創人 "HIW"秋川．旭 竟敗在"HIY+ob->name(1)+HIW"之手，實在難以置信。\n\n"+NOR
    ,users());
  ob->add("popularity",10);      
  tell_object(ob,HIG"你得到 10 點聲望。"NOR);
 ::die();
  return;
}


