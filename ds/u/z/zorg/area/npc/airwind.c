#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��", ({"airwind", "air","wind","aw" }) );
        set("long", "He looks like a terrible person,�I\n");
        set("race", "�H��");
        set("gender", "�k��"); 
        set("age", 20);
        set("attitude", "friendly");
        set("level", 8);
        set("evil", -99);
        set("combat_exp",2000);
        set("title",HIW"�i"HIG"��"HIR"��"HIC"��"HIW"�j"NOR);
        set("env/wimpy", 25);        
        set("chat_chance", 9 );
        set("chat_msg", ({   
        (: this_object(), "random_move" :),     //�|�ۤv���� 
}) );
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({
        (:command("cac"):),
        }) );
        setup(); 
}



