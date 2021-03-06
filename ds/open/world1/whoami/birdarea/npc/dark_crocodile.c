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
  set("level", 50);
  set("title",HIW"東北"NOR"澤林"); 
  set("nickname","沼澤之王"); set("limbs", ({ "頭部", "身體", "前足", "後足", "尾巴" }) );
  set("verbs", ({ "bite", "claw" ,"crash"}) );
  set("evil",150);
  set("dodge",100); 
  set("unarmed",100);
  set("parry",100); 
  set("max_hp",15000 );
  setup();
  set_temp("apply/damage", 100); 
  set_temp("apply/armor", 150); 
  set_temp("apply/shield", 150); 
}

int special_attack(object me, object target, int hitchance)
{
 if(!me || !target) return 0;
 if(random(10) < 3 || target->is_busy() ){
         message_vision("\n$N"+YEL"張開大口朝$n咬了下去……\n",me,target);
         if( random(target->query_skill("dodge"))>60 || random(target->query_dex()) > 65 ){
                 message_vision("\n$N"+HIB"側身回避，狼狽的躲掉了這一擊……\n",target); 
                 target->start_busy(1);
          } else {
                 message_vision("\n$N"+HIR"閃躲不及被$n"HIR"狠狠的咬了一口，全身骨頭近乎全數斷裂！\n",target,me);
                 target->receive_damage("hp", target->query("max_hp")/8);
                 target->receive_wound("head", 1+random(20));
                 target->receive_wound("body", 1+random(20));
                 target->receive_wound("left_arm", 1+random(20));
                 target->receive_wound("left_leg", 1+random(20));
                 target->receive_wound("right_arm", 1+random(20));
                 target->receive_wound("right_leg", 1+random(20));
                 target->start_busy(random(3));
         }
        }
 return 0;
}

void die()
{
        object ob;
        object sc;
        int rnd;
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if( ob )  message("world:world1:vision", HBK"\n\t【東北澤林】"HIW"野蠻冷血的巨獸"+this_object()->query("name")+HIW"終於被"HIW+ob->name(1)+HIW"給誅殺了！\n\n"+NOR,users());
        ob->add("popularity",3); 
        ob->set_temp("ko_crocodile",1);
        
        rnd = random(200);
        if( rnd == 1) { // 1/200
                new(__DIR__"obj/teeth")->move(this_object()); 
        } else if(rnd==2) {     // 1/200
                new(__DIR__"obj/fur")->move(this_object());
        }

        sc = ENHANCE_D->createScroll(45);
        sc->move( this_object() );

        ::die();
        return;
}

