#include <ansi.h> 
inherit NPC; 
void create() 
{ 
       set_name(HIY"�l����"NOR,({"master dan","dan"}));
       set("race","human"); 
       set("title",HIC"�W�K"NOR);
       set("level",50+random(5));
       set("max_hp",25000); 
       set("age",45);      
       set("attitude","friendly");
       set("devil",20); 
       set("chat_msg", ({
                       (: this_object(), "random_move" :), 
                        "�l�������۹D�G�쩳���⥦�a�i�h�O�H...��...\n" }) );
       set("long",@LONG      
���y�U���Z�����W�K�C
LONG
); 
        setup(); 
        set_living_name("pool_npc");
        carry_object(__DIR__"obj/soul-claw")->wield();
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
   HIG"\n\t���W�K��"+HIY"�l����"+HIW"���b"+HIR""+ob->name(1)+""+HIW"����̡I\n\n"+NOR
        ,users());
        ob->add("popularity",2); //�n��
        ::die();
        return;
}
