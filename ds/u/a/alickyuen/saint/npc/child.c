#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�p�k��" , ({"child"}) );
set("long", "�@�ӤQ�X�����p�k�ġC\n");       
        set("race", "�H��");
        set("gender", "�k��"); 
        set("age",11); 
        set("env/wimpy", 80);        
        set("attitude", "friendly");
        set("level", 5);
        set("combat_exp",300); 
    set("chat_chance", 10 );  
  set("chat_msg", ({       
(:command("jump"):),  
(:command("flip"):),  
(:command("cac"):),
     (: random_move :),
}) );
        setup();
        
}


