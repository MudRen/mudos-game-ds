#include <ansi2.h>
inherit NPC;
void create()
{
 set_name(HIY"神梟"NOR,({"god bird","god","bird"}));
 set("long","他是傳說中的大鳥，沒人之知到牠從何處來，也沒
人知道牠是哪種鳥，大家只因為牠的身型奇特、體
型高大，而給他一個稱號為﹝神梟﹞，他看起來肚
子餓了，傳聞中他喜歡吃一種綠色的小蟲。\n");
 set("age",235);
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
  set("addition/hit",random(60)); 
  set("addition/dodge",random(60)); 
 setup();
}
int special_attack(object me, object target, int hitchance)
{
 
 if(!me || !target) return 0;
 if(!random(5)){
  switch( random(7) ){
  case 0..1: 
   message_vision("\n\n$N"+HIW"用極快的速度衝向天際••\n"
                         +HIB"接著便高速俯衝而下朝$n撞去！\n",me,target);
   if( random(target->query("dex")) >=50 ) {
     message_vision("\n"HIR"被"NOR"$N"+HIR"驚險的躲過了這次的攻擊！\n",target);
     } else {
     message_vision("\n$N"+HIY"受到強烈撞擊，生命有如風中殘燭！\n",target);
     target->receive_damage("hp",200+random(200));     target->receive_wound("head",3);
     target->receive_wound("body",random(3));     }
   break;
  case 2..4:
   message_vision("\n\n$N"+HIW"用翅膀朝向$n拍了過去••\n",me,target);
   if( random(target->query_skill("dodge")) >=50 ) {
   message_vision("\n$N"+HIR"輕巧的躲過了攻擊！\n",target);
   } else {
   message_vision("\n$N"+HIY"被$n的翅膀打的頭昏眼花，分不清東西南北了！\n",target,me);
   target->receive_damage("hp",100+random(100));
   target->start_busy(random(3));    
   target->receive_wound("head",random(3));
   }
   break;
  default:
   message_vision("\n\n$N"+HIW"揮動翅膀，這裡吹起好大一陣的狂風••\n",me,target);
    if( random(target->query("con")) >=50 ) {
   message_vision("\n$N"+HIW"勉強的撐住身體不被風給吹走•\n",target);
   } else {
   message_vision(HIC"\n狂風吹得"NOR"$N"HIC"沒法站穩腳，被風給吹走了！\n",target);
    switch( random(8) ) { 
    case 0:    
    target->move("/open/world1/whoami/birdarea/en65");
    message_vision("\n\n$N很狼狽的從空中跌了下來•••\n",target);
    target->start_busy(random(3)); 
    target->receive_damage("hp",target->query("hp")*9/10);
    target->receive_wound("head",random(10));
    target->receive_wound("body",random(10));
    target->receive_wound("left_arm",random(10));
    target->receive_wound("right_arm",random(10));
    target->receive_wound("left_leg",random(10));
    target->receive_wound("left_leg",random(10));
    break;
    case 1:
    target->move("/open/world1/whoami/birdarea/en51");
    message_vision("\n\n$N很狼狽的從空中跌了下來•••\n",target);
    target->start_busy(random(3)); 
    target->receive_damage("hp",target->query("hp")*9/10);
    target->receive_wound("head",random(10));
    target->receive_wound("body",random(10));
    target->receive_wound("left_arm",random(10));
    target->receive_wound("right_arm",random(10));
    target->receive_wound("left_leg",random(10));
    target->receive_wound("left_leg",random(10));
    break;  
    case 2:
    target->move("/open/world1/whoami/birdarea/en30");
    message_vision("\n\n$N很狼狽的從空中跌了下來•••\n",target);
    target->start_busy(random(3)); 
    target->receive_damage("hp",target->query("hp")*9/10);
    target->receive_wound("head",random(10));
    target->receive_wound("body",random(10));
    target->receive_wound("left_arm",random(10));
    target->receive_wound("right_arm",random(10));
    target->receive_wound("left_leg",random(10));
    target->receive_wound("left_leg",random(10));
    break;  
    case 3..4:
    target->move("/open/world1/whoami/birdarea/en35");
    message_vision("\n\n$N很狼狽的從空中跌了下來•••\n",target);
    target->start_busy(random(3)); 
    target->receive_damage("hp",target->query("hp")*9/10);
    target->receive_wound("head",random(10));
    target->receive_wound("body",random(10));
    target->receive_wound("left_arm",random(10));
    target->receive_wound("right_arm",random(10));
    target->receive_wound("left_leg",random(10));
    target->receive_wound("left_leg",random(10));
    break;  
    case 5..6: 
    target->move("/open/world1/whoami/birdarea/en70");
    message_vision("\n\n$N很狼狽的從空中跌了下來•••\n",target);
    target->start_busy(random(3)); 
    target->receive_damage("hp",target->query("hp")*9/10);
    target->receive_wound("head",random(10));
    target->receive_wound("body",random(10));
    target->receive_wound("left_arm",random(10));
    target->receive_wound("right_arm",random(10));
    target->receive_wound("left_leg",random(10));
    target->receive_wound("left_leg",random(10));
    break;  
    default:
    target->move("/open/world1/whoami/birdarea/en78");
    message_vision("\n\n$N很狼狽的從空中跌了下來•••\n",target);
    target->start_busy(random(3)); 
    target->receive_damage("hp",target->query("hp")*9/10);
    target->receive_wound("head",random(10));
    target->receive_wound("body",random(10));
    target->receive_wound("left_arm",random(10));
    target->receive_wound("right_arm",random(10));
    target->receive_wound("left_leg",random(10));
    target->receive_wound("left_leg",random(10));
    break;      } 
    }
     break;
  }
  }  
return 0;
 
}
void die()
{
        object ob,newob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        if( ob ) message("world:world1:vision", 
        
        HIW"\n\t【"HIB"神　　話"NOR+HIW"】
        "HIW"\n\t傳說中的"HIY"神梟"NOR+HIW"如今竟慘死在"NOR+ob->name(1)+HIW"的手下•\n\n"+NOR,users());
        ob->add("popularity",7);
        tell_object(ob,HIG"\t你得到了７點聲望！\n"NOR);
        switch( random(20) ) {
        case 0..5:
        break;
        default:
        newob=new(__DIR__"obj/fur2"); 
        newob->move(this_object());
        break;
        }
        ::die();
        return;
}

