#include <ansi.h>
inherit NPC;

void create()
{
        set_name( "�p�k��" , ({"child"}) );
set("long", "�@�ӤQ�X�����p�k�ġA�{�b���M��L�p�Ķ]�Ӷ]�h�x�Ц��{�A��Ӧo�b�����g�á\�C\n");       
        set("race", "�H��");
        set("gender", "�k��"); 
        set("age",11); 
        set("env/wimpy", 80);        
        set("attitude", "friendly");
        set("level", 2);
        set("evil", -333);
        set("combat_exp",300);
        set_skill("sword", 2); 
        set_skill("blade", 1);
        set_skill("unarmed", 3);
        set_skill("dodge", 3);
        set_skill("parry", 3); 
    set("chat_chance", 2 );  
  set("chat_msg", ({       
"�p�k�Ĥ@�U�S�]���{\n",
(:command("say Got You�I�I�I"):),  
(:command("say �O�]�ڡI�I"):),  
(:command("cac"):),
}) );
        set("chat_chance_combat", 2);
        set("chat_msg_combat", ({
        (:command("cry"):),
        }) );
        setup();
        
}


