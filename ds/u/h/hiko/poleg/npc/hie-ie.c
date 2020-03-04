#include <ansi.h> 
inherit NPC;
inherit SSERVER;
void do_heal();  // add -Jangshow
void create()
{
      set_name(HIB"易海" NOR,({"hie-ie","hie"}) );
      set("title",HIG "漁會頭目" NOR);   
      set("long",@LONG
「易海」是現任漁會頭目，生性平淡，少年時曾經因緣際會得到異
人相助，使得習到一身高強功夫，曾獨自擊倒許海賊，亦曾參加過
古劍亭，在村中是聲望最高的人物，目前由於閉關練功，因此較少
參與村中之事，而據說由他可得知神秘隱世嶼的一些事，使得許多
江湖之人不斷前來與他詢問，和「鹽俠」余滄是同鄉。 
LONG    
        );
        set("race", "human");    
        set("unit","位");
        set("age",38);
        set("level",50); 
        set("max_ap",6000); 
        set("max_mp",6000);
        set("Merits/bar",9);
        set("Merits/tec",5);        set("max_hp",15000);
        set("exp",70000+random(10000));
        set("limbs", ({ "頭部", "腹部","胸部","手部","腳部" }) );      
        add("addition_armor",200);
        add("addition_damage",100);  
        set("chat_chance", 50);
        set("chat_msg", ({
  (: command("exert jurlong-awi") :), 
  (: do_heal :),
  (: do_heal :),
}));
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
  (: command("exert jurlong-awi") :),  
  (: do_heal :),  
  (: command("exert jurlong-awi") :),  
  (: do_heal :),   
  (: do_heal :),
})); 
      map_skill("hammer","jurlong-awi");
      set_skill("jurlong-awi",100);     
      set_skill("hammer",100);   
      set_skill("dodge",100);  
      set_skill("peep",100);   
      set_temp("apply/hit",15);
      setup(); 
      carry_object(__DIR__"wp/jur-hie-hammer")->wield();} 

int special_attack(object me,object target,int hitchance) //特攻..自身沒武器時出
{ 
    int z,t,s; 
    object wp;
    target = offensive_target(me);  // 敵人
    me = this_object();
    wp=me->query_temp("weapon");
    if(!me || !target) return 0;
    if(wp) return 0;
    if(random(6)) return 0;
    z=target->query_dex();
    t=target->query_con();
    s=random(120);
   if( s > (t+z)/2 ) 
    {
      message_vision(HIY"\n$N"+HIR"怒吼一聲，運起"+HIY"絕浪心訣--破浪訣\n"
         +HIW"向$n擊出"+HIY"—"+HIC"浪"+HIY"—"+HIC"濤"+HIY"—"+HIC"天"+HIY"—"+HIW"！\n"
         +HIW"$n被強大的氣勁給"+HIR"完全擊中！\n"
         +HIC"不由得的猛然退了許\多步\n\n"+NOR,me,target);   
      target->receive_damage("hp",300+random(200),target);
      target->start_busy(1);
      COMBAT_D->report_status(target); 
      return 1; 
    }
    else
    {
      if( s+20 > (t+z)/2 )
       {
        message_vision(HIY"\n$N"+HIW"雙拳緊握，"+HIY"絕浪心訣--破浪訣"+NOR"擊出\n"
                    +HIG"頓時氣勁狂增"+HIC"全力一擊"+HIW"攻向$n..\n"  
                    +HIW"$n瞬時感到危險！全力脫離氣勁範圍\n"
                    +HIC"使得受到的傷害減低\n\n"+NOR,me,target);
        target->receive_damage("hp",200+random(me->query_str()+50),target);
        target->start_busy(1);
        COMBAT_D->report_status(target);
        return 1;
       }
      else    
       {
        message_vision(HIY"\n$N"+HIW"蓄勢已久，"+HIY"絕浪心訣--破浪訣"+NOR"擊出\n"
                    +HIG"一時聲勢驚人，全力準備攻向$n..\n"  
                    +HIC"$n卻早已發現，輕鬆閃過\n\n"+NOR,me,target);
        target->receive_damage("hp",100+random(me->query_str()),target);
        COMBAT_D->report_status(target);
        return 1;
       }
    }
}
void do_heal() //回血
{
        object ob;
        ob=this_object();
        if(!ob) return 0;
        if( (ob->query("hp") + 1500 < ob->query("max_hp") ) && ob->query("mp") > 20 ) 
        {
         message_vision(HIG"$N使用了"+HIY"絕浪心訣--迴浪訣"+HIC"使得體力大增\n"+NOR,ob); 
         ob->add("hp",250+random(200));
         ob->receive_damage("mp",20);
         ob->start_busy(1);  //start_busy -Jangshow
         return; // Jangshow
        }
          return 0;
}

void die()
{
        object ob;
        ob = this_player(1);
        if( !ob = query_temp("last_damage_from") )           
        if( !ob ) 
        {
                ::die();
                return;
        }
        if(ob->query_temp("killhieea")==2)
          { ob->set_temp("solo_hieea",1); }         
        message("world:world1:vision",
        "\n"HIY"【"HIC"沿海震訊"HIY"】"HIG"漁會頭目"HIW"「"HIC"易 海"   
        HIW"」被"+ob->name(1)+"用驚人實力擊倒了。\n\n"NOR,users());
        ob->add("popularity",5); 
        message_vision("$N"HIC"露出驚異眼神說︰"+HIW"果然江山代代有人出 . . 
        我死而無憾呀\n"+NOR,this_object());  // ob -by Jangshow        
        ::die();
        return;
}










