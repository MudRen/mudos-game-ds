#include <ansi.h> 
inherit NPC; 
void create() 
{ 
       set_name(HIY"子黃丹"NOR,({"master dan","dan"}));
       set("race","human"); 
       set("title",HIC"名匠"NOR);
       set("level",50+random(5));
       set("max_hp",25000); 
       set("age",45);      
       set("attitude","friendly");
       set("devil",20); 
       set("chat_msg", ({
                       (: this_object(), "random_move" :), 
                        "子黃丹喃喃自道：到底怎麼把它家進去呢？...唉...\n" }) );
       set("long",@LONG      
打造各式武器的名匠。
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
   HIG"\n\t◎名匠◎"+HIY"子黃丹"+HIW"死在"+HIR""+ob->name(1)+""+HIW"的手裡！\n\n"+NOR
        ,users());
        ob->add("popularity",2); //聲望
        ::die();
        return;
}
