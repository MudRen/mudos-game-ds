#include <ansi.h> 
inherit NPC;
void create()
{
  set_name(CYN"神鵰"HIW"(虛)"NOR, ({"empty-god prey","prey"}) );
  set("long","神鵰的特殊分身能力。\n");
  set("race", "beast");
  set("unit","隻");
  set("age",80);
  set("level",30+random(this_player()->query("level")/3)); 
  set("max_hp",10000);
  set_skill("dodge",150);
  set_skill("unarmed",100);
  set("limbs", ({ "頭部", "腹部","胸部","爪子","尾巴" }) );
  set("verbs", ({ "bite","claw" }) ); 
        set("chat_chance_combat",30);
        set("chat_msg_combat",({
    //(: follow god prey :),
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
     target->receive_damage("hp",100+random(200), this_object());
      return 1; 
    }
}
void die()
{
   object ob,eqp;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
                eqp=new(__DIR__"leather2");
        eqp->move(this_object());
        ::die();
        return;
}

