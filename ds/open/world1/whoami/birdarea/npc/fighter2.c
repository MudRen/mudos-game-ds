#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�j�{��" , ({ "fighter" }) );
        set("level",25);
        set("race","�H��");
        set("gender","�k��");
        set("age",28+random(3));
        set_skill("dagger",35);
        set_skill("parry", 35);
        set_skill("dodge", 80);
        set_skill("skyowl-needle", 30);
        set_skill("wing-eight", 80);
        map_skill("needle","skyowl-needle");
        map_skill("dodge","wing-eight");
        set("long",@LONG
�L�O�ѱ��Ъ��j�{��, �ݰ_�ӻ��\����, �ӥB�Z�\�]���@�w���y�ڤF�C
LONG);
        set("chat_chance", 8);
        set("chat_chance_combat", 80);
        set("chat_msg_combat",({
            "�j�{�̹�A�ܹD�G�ڭn���A���Ѩ��Ѥѱ��Ъ��F�`!!\n", 
        }) );
        setup();
          carry_object(__DIR__"eq/moon-needle.c")->wield();
        carry_object(__DIR__"eq/surcoat2.c")->wear();
        carry_object(__DIR__"eq/wrists.c")->wear();
}


