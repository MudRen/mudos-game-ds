#include <ansi.h> 
inherit NPC;
 
void create() 
{ 
  set_name(CYN"玄武"HIW"神龜"NOR,({"shang-woo god turtle","turtle"}));
  set("long",@LONG      
迷樣的東西，龍頭龜身，不知從何形容，原本冬眠的它
似忽吞下了喜愛的食物，爬出了水池。
LONG
  ); 
  set("race", "beast");
  set("level",45+random(15));
  set("max_hp",35000); 
  set("age",432+random(32));      
  set("attitude","unfriendly");
  set("devil",20); 
  set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴","龜殼" }) );
  set("verbs", ({ "bite","claw"}) ); 
  set("chat_msg", ({
     (: this_object(), "random_move" :), 
      "玄武神龜搖了搖尾巴，並注視著某樣東西。\n" }) );
  setup();
  set_living_name("pool_npc");
  carry_object(__DIR__"obj/turtle-armor")->wear();
}
   
int special_attack(object me,object target,int hitchance)
{
  int tdex,tcon; 
  if(!me || !target) return 0;
  if(random(10)) return 0;
  tdex=target->query_dex();
  tcon=target->query_con();
  if( random(hitchance*30) > tdex+tcon )
  {
    message_vision("\n\n$N大爪拍向自己的肚子，嘴裡隨即吐出一團"+HIR"火球！\n"
                    +HIW"疾速的飄向$n..\n"
                    +HIR"造成沉重的內傷！\n\n"+NOR,me,target);  
    target->receive_damage("hp",500+random(333), this_object());
    return 1; 
  }
}
 
void die()
{
  object ob,obj;
//  obj=new(__DIR__"obj/turtle-armor");
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  message("world:world1:vision",
  HIY"\n\t【水寒星洞】\n"
  CYN"\t\t\t玄武神龜 "+HIR "被"+ob->name(1)+"給擊斃了！\n\n"+NOR,users());
  ob->add("popularity",4); //聲望
  message_vision( "$N一頭撞在地上，頭上的玄石也隨之掉落" ,this_object() );
//  obj->move(environment(this_object() ) );
  obj=new(__DIR__"obj/turtle-liver");
  obj->move(environment(this_object() ) );
  ::die();
  return;
}

