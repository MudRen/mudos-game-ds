#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "男護士" , ({"nurse"}) );
set("long", "一個在這間醫院�堣u作的男護士，他正在忙碌地工作。\n");       
        set("race", "人類");
        set("gender", "男性"); 
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


