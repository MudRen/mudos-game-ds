#include <ansi.h>
inherit NPC;
void create()
{
        set_name(MAG"紫晶"NOR"蟒",({"amethyst python","python"}));
        set("race", "野獸");
        set("age", 500+random(1000));
        set("long", "一隻長年幻化成匕首的巨蟒，只有它所認可的人才有機會看到它•\n");
        set("limbs", ({ "頭部", "身體", }) );
        set("verbs", ({ "bite", "hoof", "crash"}) ); 
        set_skill("unarmed",100+random(100));
        set_skill("dodge",100+random(100));
        set_skill("parry",100+random(100)); 
        set("no_kill",1);

        setup();
}

void init()
{
        call_out("check",2,this_object());
        ::init();
}

void check()
{
        object me,ob,wp;
        int durable;

        me = this_player();
        ob = this_object();
        durable = ob->query_temp("durable");
        wp = new(__DIR__"dagger3");
       
        if(!ob->is_fighting())           
        {
        message_vision("\n$N身體蜷曲了起來，再度變成了一把匕首•\n",ob);
        wp->set_durable(durable);
        wp->move(environment(me));  
        destruct(ob);        
        } else {
        call_out("check",10,ob);
        }
}

void die()
{
        object ob,wp;
        int durable = this_object()->query_temp("durable");
        wp=new(__DIR__"dagger3");
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        message_vision("\n$N身體蜷曲了起來，再度變成了一把匕首•\n",this_object());
        wp->set_durable(durable-random(10));
        wp->move(environment(this_object()));
        destruct(this_object()); 
        return;
}

int special_attack(object me, object target, int hitchance)
{
  int tdex,tdodge,damage;
  if(!me) return 0;
  if(me->is_busy()) return 0;
  if(!random(5))
 switch( random(3) ){
  case 0: 
  message_vision("\n$N身上的"MAG"紫水晶鱗片"NOR"閃出一陣"HIW"刺眼的光芒"NOR"…\n"NOR,me); 
  if( random(tdex + tdodge) < 100 && !target->is_busy() )  {
  message_vision("$N被這強烈的光芒射中，動作突然變得些許\遲緩•\n\n",target);
  target->start_busy(1+random(3));
  } else {
  message_vision("$N眼睛一閉，避開了這耀眼的強光•\n\n",target);
  }
  break;
  case 1:
  message_vision("\n$N張改大口朝$n撲了過去…\n",me,target);
  if( random(tdex + tdodge) < 150 )  { 
  damage = random(1000);  message_vision("$N反應不及，身上留下了一個巨大的蟒蛇咬痕•\n\n",target);
  me->attack();  
  target->receive_damage("hp",damage);
  target->receive_wound("head",random(2)); 
  target->receive_wound("body",random(2));
  target->apply_condition("blooding", random(10));  } else {
  message_vision("$N翩翩的一個翻身，遊刃有餘的躲過了這次的攻擊•\n\n",target);
  }
  break;
 }
  return 0;
}

