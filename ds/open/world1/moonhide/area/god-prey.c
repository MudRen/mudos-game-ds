#include <ansi.h> 
inherit NPC;  
int CALL_PREY(string arg);
void create()
{
  set_name(CYN"神鵰"NOR, ({"god prey","prey"}) );
  set("long","古墓派楊過與小龍女的神禽，保護著古墓，不受外人侵擾。\n");
  set("race", "beast");
  set("unit","隻");
  set("age",80);
  set("level",50+random(this_player()->query("level")/3)); 
  set("max_hp",9000);
  set_skill("dodge",150);
  set_skill("unarmed",100);
  set("Merits/wit",10);
  set("limbs", ({ "頭部", "腹部","胸部","爪子","尾巴" }) );
  set("verbs", ({ "bite","claw" }) ); 
        set("chat_chance_combat",9);
        set("chat_msg_combat",({
    (: random_move :),
}));  
  setup(); 
  //carry_object(__DIR__"leather")->wear();
}
int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
    if(!me || !target) return 0;
    if(random(10)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance*30) > tdex+tcon)
    {
      message_vision(CYN"\n\n$N"+HIW"忽然一飛數十丈高！\n"
                    +HIW"迴旋式的向下墜落，以極快的速度..\n"
                    +HIR"衝撞$n，造成沉重的內傷！\n\n"+NOR,me,target);  
     target->receive_damage("hp",600+random(333), this_object());
    } else {
//     this_object()->CALL_PREY();
    }
    return 1;  
}
 
int CALL_PREY(string arg)
{
     object me=this_player(),ob=this_object(),CP_PREY;
     if( ob->is_fighting() )
     { 
     message_vision(CYN"神鵰"+HIW"突然展翅高飛，剎那間分成兩道黑影！\n\n"+NOR,me);
     CP_PREY=new(__DIR__"empty-god-prey"); 
     CP_PREY->move(ob);
     CP_PREY->kill_ob(environment(this_player())); 
     this_player()->kill_ob(this_object()); 
     }
     return 1;
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
    HIB"\n\t森林裡的群獸突然群起鳴叫•••原來是•••\n\n"
    +HIY"\t【古墓  神禽】"+CYN"神鵰"+HIW"被"+ob->name(1)+"殺掉了。\n\n"+NOR,users());
  ob->add("popularity",3);
  switch( random(100) )
  {
    case  0..1: new(__DIR__"leather")->move(this_object());
          break;
    case  2..40: new(__DIR__"leather2")->move(this_object());
          break;
    case  41..99: new(__DIR__"leather3")->move(this_object());
          break;
  }
/*      
  if( random(25) ) // 由原本random(8) 即16份一機會得到tec&bar eq 改成50分一機會
                   // by alickyuen@ds2003-02-18
    new(__DIR__"leather2")->move(this_object()); 
  else if( random(2) )
    new(__DIR__"leather")->move(this_object());
//        eqp->move(this_object());
//  2003.4.10 修正 prey 有時打不死之 bug  by  ksj
*/
  ::die();
  return;
}

