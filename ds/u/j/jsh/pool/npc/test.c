#include <ansi.h>
inherit NPC; 
void create() 
{ 
       set_name(HIR"���"NOR,({"blood snake","snake"}));
       set("gender","���~");
       set("level",52);
       set("max_hp",33333); 
       set("age",432+random(32));      
       set("attitude","unfriendly");
       set("devil",40); 
       set("limbs", ({ "�Y��", "����", "����","�I��","�y��" }) );
       set("verbs", ({ "bite","claw"}) ); 
       set("long",@LONG        
�����q�������s�A�P�I�G��O�P�X�@���A�����I�G��[���r�I

LONG
); 
        setup();
}  
void die()
{
   object ob,obj;
   obj=new(__DIR__"obj/snake-waist");
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        } 
        ob->add("popularity",4);
        message("world:world1:vision",
   HIR"\n\t"+ob->name(1)+"��D�G����a�I�I�P�I�G�P�X�@�������I�I\n\n"+NOR
        ,users());
       obj->move(environment(this_object() ) );
       obj=new(__DIR__"obj/snake-liver");
       obj->move(environment(this_object() ) );
        ::die();
        return;
}
void special()
{
        object me=this_object();
        object* target; 
        int dam = 400 + random(me->query_skill("unarmed"));   
        if(me->is_busy() ) return;
        target=query_enemy();
       {
message_vision(HIW"\n�@�ѥ��j��"HIB"�Ŧ��q"HIW"�b$N�f�����_���Y�I�I"HIR"�Q�X�I�I"HIW"�e�V���⤣�Ϊ�$n�I�I\n"NOR,me,target);
        target->receive_damage("hp",dam,me);
        message_vision("�y��$N" +dam+ "�I���N�ˡC\n",target); 
        }
    return;
}

