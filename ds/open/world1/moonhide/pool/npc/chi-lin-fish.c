#include <ansi.h>
inherit NPC; 
void create() 
{ 
       set_name(HIY"�Q�ﳽ"NOR,({"chi lin-fish","fish"}));
       set("race","beast");
       set("level",40);
       set("max_hp",12000);  
       set("age",120);      
       set("attitude","friendly");
       set("devil",20); 
       set("limbs", ({ "�Y��", "����", "����" }) );
       set("verbs", ({ "bite","claw"}) ); 
       set("chat_msg", ({
                       (: this_object(), "random_move" :), 
                        "�Q�ﳽ�۵ۡG���೽�������..A_A�C\n" }) );
       set("long",@LONG        
���H�P�}�̡A�ݳ̤[���@�����A����������O����
��A�ҥH�H�a�s���Q�ﳽ�C
LONG
); 
        setup();  
set_living_name("pool_npc");
 carry_object(__DIR__"obj/ticket"); 
 carry_object(__DIR__"obj/ticket");
 carry_object(__DIR__"obj/ticket");
 carry_object(__DIR__"obj/ticket");
 carry_object(__DIR__"obj/ticket"); 
 carry_object(__DIR__"obj/chi-lin-armor")->wear(); 
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
        ob->add("popularity",2);
        message("world:world1:vision",
   HIC"\n\t�����H�P�}��  "+HIY"�Q�ﳽ"+HIW"�b"+HIR""+ob->name(1)+""+HIW"����U�A�w�g�ܦ��@�Φ���F�C\n\n"+NOR
        ,users());
        ::die();
        return;
}
