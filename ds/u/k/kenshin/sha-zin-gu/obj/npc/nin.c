#include <path.h>
#include <ansi.h>
inherit NPC;

void create()
{
  set_name(WHT"寧采和"NOR, ({ "nin tsai ho","tsai","ho" }) );
  set("gender", "男性" );
  set("long",@LONG
武林新生代奇才之一，與疾風神童萬鮮靈並列齊名，不過在一次的
意外中失去了一切，便決定退隱江湖，不在過問世俗之事，便在暇
日谷這一地隱居，世人稱『暇日谷主』。　
LONG
);
  set("title",HIY"暇日谷主"NOR);
  set("age",32+random(3));
  set("level",48);
  set("race","human");
  set("chat_chance", 20);
  set("chat_msg", ({
"寧采和面目無色，滿臉憂鬱！！\n",
}));
  set_skill("unarmed",100);
  set_skill("parry",100);
  set_skill("dodge",100);
  set_skill("combat",100);
  set("Merits/wit",2);
  setup();
  add_money("coin",3333+random(1111));
  carry_object(__DIR__"wp/wp1")->wield();
  carry_object(__DIR__"eq/8-mirror")->wear();
}

void init()
{
  add_action("do_no_ask","ask"); 
  } 
int do_no_ask(string arg)
{
  write("別問我，想知道自己說些有關的理論出來(say)!!\n");    return 1;
}

void relay_say(object me, string str)
{
  object ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;

  if(strsrch(str,"祕寶") != -1)
  {
    command("tsk");
    command("say 真厲害，我退隱數年從哪聽到我有很珍貴的東西!?"); 
    return;  
  }
  if(strsrch(str,"小虎子") !=-1 || strsrch(str,"虎小弟") != -1)
  {
    command("emote 寧采和氣的跺腳!!");
    command("say 死徒弟!!真愛出賣我!!怎樣...你想得到嘛!?"); 
    return; 
  }
  if(strsrch(str,"想") != -1)
  {
    command("say 嗯....");
    command("say 答應我一件事，我就給你!!"); 
    return;   }
  if(strsrch(str,"什麼事") != -1)
  {
  command("say 你到暇日谷的東邊墓地，幫我找到我愛人的死前所佩帶的耳環，我就把此樣珍貴之物給你!!");  //沒有""
  }
  return;
}  
int accept_object(object who,object ob)
{
                object obj;
                obj=this_object();
                if(ob->query("name")!="耳環")
                {
                 command("? "+who->query("id"));
                 return 1;
                }
                else  
                if(obj->is_busy() || obj->is_fighting())                                   {
                  command("whisper "+who->query("id")+" 請你等一下。");
                  return 0;
                                                            }  
                 else                    
       message_vision("$N給了寧采和一個"+ob->query("name")+"。\n",who);
       command("say 這...不是妙如的耳環嘛?..我真是太高興了.!!");
               obj->set_temp("earring_quest",1); 
               obj->start_busy(6);
               destruct(ob); 
               call_out("earring_quest",1,obj);                                 return 1;

}  
void earring_quest()
{
      int i;
      object me,obj,item;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("earring_quest");
      switch( i ) {
                case 1:
                command("say 這....不是妙如的耳環嘛..!?");
                command("say 敢問"+RANK_D->query_respect(me)+"怎樣得到此物呢!?");
                obj->set_temp("earring_quest",i+1);
                call_out("earring_quest",1,me);
                break;
                case 2:
                message_vision(HIC"$N把在墓地隧道的事情告訴寧采和..!!\n"NOR,me);
                obj->set_temp("earring_quest",i+1);
                call_out("earring_quest",1,me);
                break;
                case 3:
                command("hmm");
                command("say 嗯!!我早猜到會演變成這樣..所以我並不感到悲傷,我還為妙如能順利轉生感到高興!!");
                obj->set_temp("earring_quest",i+1);
                call_out("earring_quest",1,me);
                break;
                case 4:
                                command("say 不過..還是謝了!!");
                                command("bow");
                                command("say 話說回來,我也要守當初的承諾,送你我最珍貴的防具!!\n");
                                item=new(__DIR__"eq/mo-ring");
                                item->move(obj); 
                                command("give ring to "+ me->query("id") ); 
                                obj->delete_temp("earring_quest");  
                               break;  
            }
} 
void greeting(object ob)
{ 
object me=this_player();
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0: 
                        message_vision(HIB"\n寧采和一式重擊打向你,威力驚人無比!!\n"+NOR,me);
                        me->receive_damage("hp",300);
                        this_object()->kill_object(environment(me));
                        break;
                
        }
}
int special_attack(object me,object target,int hitchance)
{
  int damage;
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(7))

    {
      message_vision(HIR"寧采和口中喃喃自語：五將星鬼，與我定下誓約，助我斬妖除魔吧！！
            "HIR"寧采和與【火將福鬼】達成協議，頃刻間熊熊烈火燃燒成形，形成小烈鬼往$N的頭部俯衝。
            "HIC"寧采和與【水將福鬼】達成協議，頃刻間滔滔猛水聚集成形，形成小水鬼往$N的臉部俯衝。
            "HIY"寧采和與【土將福鬼】達成協議，頃刻間成千巨土匯集成形，形成小土鬼往$N的身體俯衝。
            "NOR""YEL"寧采和與【木將福鬼】達成協議，頃刻間上萬巨木組合成形，形成小巨鬼往$N的腰部俯衝。
            "HIW"寧采和與【冰將福鬼】達成協議，頃刻間冷冽寒冰風暴成形，形成小冰鬼往$N的足部俯衝。\n"NOR,target);
                      if(random(target->query_dex()) >35){
                      damage=300-target->query_armor()+random(100);
                      target->receive_damage("hp",damage,target);
                      message_vision("\n五下總合共造成$N"HIR""+damage+""NOR"點的傷害。\n",target);
} 
else
    {
    message_vision(HIG"\n$N使出雁子般的輕盈，避開了這波強烈的攻擊！！\n"NOR,target);
    return 1;
    }
        return 1;
  }
  return 0;
}



void die()
{
   object ob;
   if( !ob = query_temp("last_damage_from") ) ob = this_player(1); 
   if( !ob )
   {
     ::die();
     return;
   }
   message("world:world1:vision",
HIG"\n【觀星者云】上空八方云星殞落，外傳寧采和消逝去了！！\n\n"NOR,users());

   ob->add("popularity",3+random(2));
   ::die();
   return;
}

