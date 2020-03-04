#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIR"����"HIY"����"NOR,({"golden snake","snake"}) );
        set("long",@LONG
�@���Ӥj���r�D�A���ר����C�ئ��l�A����⪺�����A�����⪺
�D��A���r�ӱ��ӥB�r�ʫܱj�A�g�`�������b�C
LONG);
        set("race", "���~");    
        set("unit","��");
        set("age",8);
        set("level",23);
        set("attitude", "aggressive");  
        set("limbs", ({ "�Y��", "����","����"}) ); 
        set("verbs", ({ "bite" }) );     
        set("chat_chance", 10);
        set("chat_msg", ({
        HIR"����"HIY"����"NOR"���⪺�������n�ۧA�A�n���H�ɭn���L�Ӧ����C\n",
        }));                                
        setup();
        add_money("coin",500);
}

void init()
{
    ::init();
    if( environment(this_player())->query("no_kill") ) return;
    if( environment(this_player())->query("no_fight") ) return;
    if(!this_object()->visible(this_player())) return;
    if(userp(this_player()) )
      this_object()->kill_ob(this_player());
}

int special_attack(object me, object target, int hitchance)
 {
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(4))
  {
    message_vision("$N�p�@�������A���t�a�r�V$n\n", this_object(), target);
    target->apply_condition("poison", target->query_condition("poison")+(random(1)+1));
    target->receive_damage("hp",random(50)+30,target);
    target->apply_condition("blooding", target->query_condition("blooding")+random(2));
    return 1;
  }
  return 0;
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
        ob->add("popularity",1);
        tell_object(ob,HIG"�A�o�� 1 �I�n��C"NOR);      
        switch( random(99) ) {
case  0..4: new(__DIR__"eq/golden-snake-waist")->move(this_object()); //debug-js@ds
        break;}
        ::die();
        return;
 }
