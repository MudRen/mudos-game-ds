#include <ansi2.h>
inherit NPC;
void create()
{
 set_name(HIW+BLK"闇夜"NOR+YEL"巨鱷"NOR,({"dark-night crocodile","crocodile"}));
 set("long","牠就是居住在這東北澤林的巨大鱷魚，多年被一個不知名的人封\n"
            "印於此，如今再次的回到這個世界，想必會帶來不少後患。\n");
 set("age",200+random(100));
 set("race", "野獸");
set("attitude","aggressive");
 set("level",50+random(20));
 set("title",HIW"東北"NOR"澤林"); 
 set("nickname","沼澤之王"); set("limbs", ({ "頭部", "身體", "前足", "後足", "尾巴" }) );
 set("verbs", ({ "bite", "claw" ,"crash"}) );
 set("evil",500);
 set("dodge",100); 
 set("unarmed",100);
 set("parry",100); 
 set("max_hp",15000+random(3000));

 set("addition/wit",random(7)); 
 set("addition/bar",-3); 
  set("addition/hit",random(60)); 
  set("addition/dodge",random(60)); 
 setup();
}
int special_attack(object me, object target, int hitchance)
{
 
 if(!me || !target) return 0;
 if(!random(5)){
 message_vision("\n$N"+YEL"張開大口朝$n咬了下去••\n",me,target);
 if( random(target->query("dodge"))>60 ){
 message_vision("\n$N"+HIB"側身回避，狼狽的躲掉了這一擊•\n",target); 
 target->start_busy(1); } else {
 message_vision("\n$N"+HIR"閃躲不及被$n"HIR"狠狠的咬了一口，全身骨頭近乎全數斷裂！\n",target,me);
 target->receive_damage("hp",target->query("hp")/10);
 target->receive_wound("head",1+random(98));
 target->receive_wound("body",1+random(98));
 target->receive_wound("left_arm",1+random(98));
 target->receive_wound("left_leg",1+random(98));
 target->receive_wound("right_arm",1+random(98));
 target->receive_wound("right_leg",1+random(98));
 target->start_busy(random(3));
 }
}return 0;
 
}
void die()
{
        object ob,newob,newob1;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        if( ob ) message("world:world1:vision", 
        
        HIG"\n\t【"HIW"東北"NOR"澤林"HIG"】
"HIW"\n\t東北澤林內的怪獸"+this_object()->query("name")+HIW"終於被"NOR+ob->name(1)+HIW"給誅殺了！\n\n"+NOR,users());
        ob->add("popularity",7); 
        ob->set_temp("ko_crocodile",1);
        tell_object(ob,HIG"\t你得到了７點聲望！\n"NOR);
        switch( random(100) ) {
        case 0..5:
        newob1=new(__DIR__"obj/teeth"); 
        newob1->move(this_object());
        break;
        case 6..20:
        newob=new(__DIR__"obj/fur"); 
        newob->move(this_object());
        break;
        default:
        new(__DIR__"obj/scroll")->move(this_object());
        break;
        }
        ::die();
        return;
}

