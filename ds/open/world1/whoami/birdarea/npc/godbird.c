#include <ansi2.h>
inherit NPC;
void create()
{
 set_name(HIY"神梟"NOR,({"god bird","god","bird"}));
 set("long","他是傳說中的大鳥，沒人知道牠從何處來，也沒人
知道牠是哪種鳥，大家只因為牠的身型奇特、體型
高大，而給他一個稱號為﹝神梟﹞，他看起來肚子
餓了，傳聞中他喜歡吃一種綠色的小蟲。\n");
 set("age",500+random(600));
 set("race", "野獸");
 set("level",30+random(20));
 set("title","傳說之鳥");
 set("limbs", ({ "頭部", "身體", "翅膀", "腳", "尾部" }) );
 set("verbs", ({ "bite", "claw" }) );
 set("evil",-50);
 set("dodge",100); 
 set("unarmed",100);
 set("parry",100); 
 set("max_hp",20000+random(3000));
 set("addition/wit",random(7)); 
 set("addition/bar",2+random(2)); 
 set("addition_damage",140+random(20)); 
 set("addition_armor",120+random(15)); 
 set("addition/hit",random(60)); 
 set("addition/dodge",random(60)); 
 setup();
}
int special_attack(object me, object target, int hitchance)
{
 int x = random(80);
 
 if(!me || !target) return 0;
 if(!random(3)){
  switch( random(7) ){
  case 0..1: 
   message_vision("\n\n$N"+HIW"用極快的速度衝向天際••\n"
                         +HIB"接著便高速俯衝而下朝$n撞去！",me,target);
   if( random(target->query_dex()) >=50 ) {
     message_vision("\n"HIR"被"NOR"$N"+HIR"驚險的躲過了這次的攻擊！\n",target);
     } else {
     message_vision("\n$N"+HIY"受到強烈撞擊，生命有如風中殘燭！\n",target);
     target->receive_damage("hp",200+random(200));
     target->receive_wound("head",3);
     target->receive_wound("body",random(3));
     }
   break;
  case 2..4:
   message_vision("\n\n$N"+HIW"用翅膀朝向$n拍了過去••",me,target);
   if( random(target->query_skill("dodge")) >=70 ) {
   message_vision("\n$N"+HIR"輕巧的躲過了攻擊！\n",target);
   } else {
   message_vision("\n$N"+HIY"被$n的翅膀打的頭昏眼花，分不清東西南北了！\n",target,me);
   target->receive_damage("hp",100+random(100));
   target->start_busy(random(3)+2);    
   target->receive_wound("head",random(3));
   }
   break;
  default:
   message_vision("\n\n$N"+HIW"揮動翅膀，這裡吹起好大一陣的狂風••\n",me,target);
    if( random(target->query_con()) >= 80 ) {
   message_vision("\n$N"+HIW"勉強的撐住身體不被風給吹走•\n",target);
   } else {
   message_vision(HIC"\n狂風吹得"NOR"$N"HIC"沒法站穩腳，被風給吹走了！\n",target);
    target->start_busy(random(3)); 
    target->receive_wound("head",random(30));
    target->receive_wound("body",random(30));
    target->receive_wound("left_arm",random(30));
    target->receive_wound("right_arm",random(30));
    target->receive_wound("left_leg",random(30));
    target->receive_wound("left_leg",random(30));
    target->move("/open/world1/whoami/birdarea/en"+x);
    message_vision("\n\n$N很狼狽的從空中跌了下來•••\n",target);
    }
     break;
  }
  }  
return 0;

}
void die()
{
       object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( ob ) message("world:world1:vision", 
        HIW"\n\t【"HIB"神　　話"NOR+HIW"】"HIW"\t傳說中的"HIY"神梟"NOR+HIW"如今竟慘死在"NOR+ob->name(1)+HIW"的手下•\n\n"+NOR,users());
        ob->add("popularity",4);
        switch( random(10) ) {
        case 0..7:  break;
        default:  new(__DIR__"obj/fur2")->move(this_object());  break;
        }
        ::die();
        return;
}

