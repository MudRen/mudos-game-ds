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
 carry_object(__DIR__"obj/snake-waist")->wear();
 carry_object(__DIR__"obj/snake-liver");
} 
void die()
{
   object ob,obj;
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
        ::die();
        return;
}

