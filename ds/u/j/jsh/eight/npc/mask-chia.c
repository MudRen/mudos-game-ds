#include <ansi.h>
inherit NPC; 
void create() 
{ 
       set_name(HIC"�äѭ{"NOR,({"turn-sky chia","chia"}));
       set("gender","human"); 
       set("title",HIR"�K�j"NOR);       set("level",45);
       set("max_hp",25000); 
       set("age",50+random(3));      
       set("attitude","friendly");
       set("long",@LONG       
test
LONG
); 
        setup(); 
 carry_object(__DIR__"obj/eight-mask")->wear();
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
        ob->add("popularity",3);
        message("world:world1:vision",
   HIG"\n\t�i�K�E�j�E�{�j"+HIC"�äѭ{"+HIR"���b"+ob->name(1)+"����̡C\n\n"+NOR
        ,users());
        ::die();
        return;
}

