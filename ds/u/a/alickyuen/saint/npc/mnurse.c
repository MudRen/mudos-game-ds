#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�k�@�h" , ({"nurse"}) );
set("long", "�@�Ӧb�o����|�ؤu�@���k�@�h�A�L���b���L�a�u�@�C\n");       
        set("race", "�H��");
        set("gender", "�k��"); 
        set("age",25);         
        set("attitude", "friendly");
        set("level", 15);
        set("combat_exp",300);
// set_skill("medicine",100); 
    set("chat_chance", 10 );  
  set("chat_msg", ({       
     (: random_move :),
}) );
        setup();
        
}


