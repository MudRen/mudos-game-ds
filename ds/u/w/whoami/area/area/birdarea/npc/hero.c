#include <ansi2.h>
#include <combat.h>
inherit NPC; 
inherit SSERVER;
void power();
void heal();  
void create()
{
  set_name("索貝克", ({ "suoo bey keh","keh","bey","suoo","hero" }) );
  set("gender", "男性" );
  set("nickname","獵狐高手");
  set("title",HIR"獵狐村"NOR+HIC" 英雄"NOR);
  set("long",@LONG
他是在數十年前曾經打敗過九尾的高手，在那次的激戰中受了重
傷到此隱居療傷•聽說在他成為這個村子的英雄之前還只是個打
鐵匠，這也難怪他拿的武器你從來都沒看過•
LONG);      
  set("age",30+random(10));
  set("level",43+random(4));
  set("exp",40000+random(3000));
  set("race","human"); 
  set("max_hp",13000+random(5000)); 
  set("max_ap",25000+random(10000));
  set("max_mp",25000+random(10000));

  set_skill("unarmed",100);
  set_skill("parry",100);
  set_skill("dodge",100);
  set_skill("force",100);
  set_skill("fork",100);
  set_skill("da-fork",100);
  set_skill("bagi_fist",100);
  set_skill("bagi_force",100);
  set_skill("horse-steps",100);
  set_skill("bird-eight",100);
  set_skill("moon_force",100);
  set_skill("buddha-force",100);
  set_spell("god-kill",100); 
  set_spell("god-fire",100);
  set_spell("god-benison",100); 
  set("addition/wit",3+random(5)); 
  set("addition/bar",1+random(5));  
  set("addition/damage",10+random(50)); 
  set("addition/armor",100+random(50)); 
  set("addition/shield",100+random(50)); 
  set("addition/con",100+random(20));
  set("addition/dex",100+random(20));
  set("class1", "神武教");
  set("class2", "神武教");

  set("chat_chance", 300);
  set("chat_msg", ({
(: command("exert da-fork")   :),
(: command("exert bagi_fist") :),
(: command("exert bird-eight") :),
(: command("exert buddha-force armor") :),
(: command("exert bagi_force power_up") :),
(: command("exert horse-steps twine-power") :),
}));

  set("chat_chance_combat",100);
  set("chat_msg_combat", ({
(: heal :),
(: power :),  
(: command("wield pike") :),}) );
  set("talk_reply","如果你與我交談 <say> 會發現意想不到的情報唷！\n");
  setup();
  add_money("coin",random(5000));
  carry_object(__DIR__"eq/tooth")->wield();
}
void init()
{
  object me;
 
  ::init();
  if( interactive(me = this_player()) && !is_fighting() )
  {
    remove_call_out("greeting");
    call_out("greeting", 1, me);
  }
  add_action("do_no_ask","ask");
}

void greeting(object me)
{
  if( !me || environment(me) != environment() ) return;
  if( me->query_temp("ko_fox_nine") ){
  command("whisper "+me->query("id")+"如果你缺防具可以找我幫忙喔！");
  }
  return;
}

int do_no_ask()
{
  write("請用 say <交談的方式> 來取得所需情報。\n");
  return 1;
}

void relay_say(object me, string str)
{
  object ob = this_object();
  if( !userp(me) ) return;
  if(strsrch(str,"防具") !=-1 && this_player()->query_temp("ko_fox_nine") )
  {
   command("hmm");
   command("say 我是看你也是能夠打敗九尾的勇者才跟你說的..");
   command("say 在東北澤林裡頭有隻兇猛的鱷魚");
   command("say 如果你能夠打敗牠，把牠的牙齒給我，我就能幫你做出不錯的防具");   
  }
  if(strsrch(str,"九尾") !=-1)
  {
   command("say 我就是打敗九尾的那個人啊！");
   command("cac");
  }
  if(strsrch(str,"鱷魚") !=-1 && this_player()->query_temp("ko_fox_nine") )
  {
   command("hmm");
   command("say 東北澤林可是很大的，那裡連我都沒進去過•");
   command("say 有鱷魚也只是聽說的"); 
   command("ant");  }
  return;
}

int accept_object(object who, object ob)
{ 
  object obj=this_object();
  if(ob->query("id") == "crocodile teeth")
  {
    if( who->query_temp("ko_crocodile") && who->query_temp("ko_fox_nine") 
    && obj->query_temp("no_give") < 1 )
    {
    message_vision("$N給了$n一"+ob->query("unit")+ob->query("name")+"。\n",who,obj);
    command("tsk "+who->query("id")); 
    command("say 我馬上就幫你做件防具！");
    destruct(ob); 
    obj->set_temp("no_give",1);
    obj->set_temp("give_item",1);
    call_out("giveitem",1,obj);  
    } else {
    command("say 我才不要來路不明的東西！");
  }
  return 0;
}
  command("say 送我東西啊？多謝你了，不過我長久住在此地，倒也不缺什麼，你還是拿回去吧。");
  write("["+this_object()->name(1)+"對"+ob->name(1)+"並不感興趣]\n");
  return notify_fail("");
}

void giveitem()
{
      int i;
      object me,obj,item,item1;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("give_item");
      if( !me || environment(me) != environment(obj) )
        {
                command("say 咦？" + RANK_D->query_respect(me) + "人呢？？");
                return;
        }
      switch( i ) {
          case 1:
            message_vision(HIY"$N仔細的打量了一下這顆牙齒。\n"NOR,obj);
            obj->set_temp("give_item",i+1);
            call_out("giveitem",2,me);
            break;
          case 2:
            command("say 不錯，這個可以做成蠻好的防具");
            obj->set_temp("give_item",i+1);
            call_out("giveitem",1,me);
            break;
          case 3:
            command("say 你等等喔！");
            message_vision(HIY"$N走到房裡去開始敲敲打打•••\n"NOR,obj); 
            obj->set_temp("give_item",i+1);
            call_out("giveitem",3,me);
            break;
          case 4:  
            switch( random(5) ){
            case 0..2:            
              item=new(__DIR__"eq/bar-neck");
             item->move(obj); 
             message_vision(HIY"$N終於從房裡頭走了出來•••\n"NOR,obj);
             command("say 嗯..就是這個東西..");
             command("give necklace to "+ me->query("id") );
             break;
            default:
             item1=new(__DIR__"eq/wit-neck");
             item1->move(obj); 
             command("sorry"); 
             command("say 我失敗了，這個東西給你當作賠償吧！"); 
             command("give necklace to "+ me->query("id") ); 
             break;
            }  
             obj->delete_temp("give_item");  
             obj->delete_temp("no_give");          
 break;          
   }
} 

void die()
{
        object ob,newob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        if( ob )     message("world:world1:vision", 
HIB"\n東北方的天空中，有顆"BLINK+HIY"星"NOR+HIB"墜入了地平線∼∼
\n\n\t"HIR"獵狐村的英雄被"+ob->name(1)+"殺死了。\n\n"+NOR,users());
        ob->add("popularity",10);
        tell_object(ob,HIG"\t你得到了１０點聲望！\n"NOR);
        ::die();
        return;
}
 
void heal()
{
    object me=this_object();
message_vision(HIW"$N手握金針，在$N身上受傷的地方扎了幾下，忽然$N傷痕神奇的慢慢開始治癒了！\n"NOR, me);              
    me->receive_heal("hp",random(1000));
    me->receive_heal("mp",random(1000));
    me->receive_heal("ap",random(1000));
    return;
}
void power()
{
  switch( random(10) )
  {
    case 0 : command("exert da-fork");
             break;
    case 1 : command("exert da-fork");
             break;
    case 2 : command("cast god-fire");
             break;
    case 3 : command("cast god-kill");
             break;
    case 4 : command("cast god-kill");
             break;
    case 5 : command("cast god-kill");
             break;
    case 6 : command("exert moon_force long-arc"); 
             break; 
    case 7 : command("exert moon_force moon-arc"); 
             break;  
    case 8 : command("cast god-benison"); 
             break;  
    case 9 : command("exert bagi_fist");
             break;
           
  }
  return;
}

int receive_damage(string type,int cost)
{
  object ob = this_object(), me = this_player();

  if(ob->is_busy()) ob->add_busy(-10);
  if(!random(3) && ob->is_fighting() && me != ob)
  {
    message_vision(HIG"\n$N大吼一聲，嚇得$n雙腳發軟，動彈不得！\n\n"NOR,ob,me);
    me->start_busy(1);
    power();
  }
  ::receive_damage(type,cost,me);
  return 0;
}

int be_stolen(object me, object what)
{
        if( !me || !what )
                return notify_fail("[錯誤]:請用 report 指令回報。\n");
        tell_object(me, this_object()->name() + "不經意地一轉頭﹐你急忙將手縮了回去﹗\n"
                "還好﹐沒有被發現。\n");
        me->start_busy(2);
        return 1;
}

