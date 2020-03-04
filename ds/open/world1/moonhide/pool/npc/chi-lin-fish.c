#include <ansi.h>
inherit NPC; 
void create() 
{ 
       set_name(HIY"麒麟魚"NOR,({"chi lin-fish","fish"}));
       set("race","beast");
       set("level",40);
       set("max_hp",12000);  
       set("age",120);      
       set("attitude","friendly");
       set("devil",20); 
       set("limbs", ({ "頭部", "身體", "魚尾" }) );
       set("verbs", ({ "bite","claw"}) ); 
       set("chat_msg", ({
                       (: this_object(), "random_move" :), 
                        "麒麟魚唱著：魚兒魚兒水中游..A_A。\n" }) );
       set("long",@LONG        
水寒星洞裡，待最久的一條魚，全身鱗片都是金黃
色，所以人家叫它麒麟魚。
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
   HIC"\n\t※水寒星洞※  "+HIY"麒麟魚"+HIW"在"+HIR""+ob->name(1)+""+HIW"的手下，已經變成一團肉醬了。\n\n"+NOR
        ,users());
        ::die();
        return;
}
