#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�C���a��", ({"Hob Goblin","hob","goblin"}) );
        set("long", "�����b�⤽�إH�W,�Q�������Ӧb�a�U�ͬ����j���ȱڤH�I\n");
        set("race", "���]");
        set("gender", "�k��"); 
        set("age", 83);
        set("attitude", "agreesive");
        set("level", 2);
        set("evil", -99);
        set("combat_exp",200);
        set("env/wimpy", 25);        
        set("chat_chance", 1 );    
        set("chat_msg", ({   
        (:command("say ��"):),
        (:command(""):),
        (:command(""):),
}) );
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({
        (:command(""):),
        (:command(""):),
        }) );
        setup(); 
 }

