#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("路人", ({ "traveller","路人" }) );
        set("long","一位正在趕路的人。\n");
        set("level",1);
        set("age",35);

        set("combat_exp", 10); 
        set("chat_chance",10);
        set("chat_msg",({
            "路人說:好累啊!....\n",
        }) );                               
        set_skill("combat", 0);
        set_skill("parry", 0);
        set_skill("unarmed", 0);
        set_skill("dodge", 0);
         
        setup(); 
carry_object("/u/t/tako/gsword")->wield();        }



