#include <ansi.h>
inherit NPC;

void create()
{
        set_name( "���k" , ({"beauty"}) );
set("long", "�@�ӤQ�����R���֤k�A�o�n���b���@�ӤH\n");       
        set("race", "�H��");
        set("gender", "�k��"); 
        set("age",18); 
        set("env/wimpy", 50);        
        set("attitude", "friendly");
        set("level",10);
        set("combat_exp",500);
        set_skill("unarmed", 10);
        set_skill("dodge", 10);
        set_skill("parry", 10); 
    set("chat_chance", 2 );  
  set("chat_msg", ({       
(:command("sigh"):),  
"�ݨӬ��k���߱��Q���J��F\n",
}) );
        set("chat_chance_combat", 2);
        set("chat_msg_combat", ({
        (:command("say Don't kill me"):),
        }) );
        setup();
        
}

