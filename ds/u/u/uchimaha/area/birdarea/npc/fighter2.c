#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�j�{��" , ({ "fighter" }) );
        set("level",16);
        set("race","�H��");
        set("gender","�k��");
        set("age",28);
        set_skill("dagger",35);
        set_skill("parry", 35);
        set_skill("dodge", 70);
        set_skill("sky-dagger", 30);
        set_skill("bird-eight", 60);
        map_skill("dagger","sky-dagger");
        map_skill("dodge","bird-eight");
        set("long",@LONG
�L�O�ѱ��Ъ��j�{��, �ݰ_�ӻ��\����, �ӥB�Z�\�]���@�w���y���F�C
LONG
           );
        set("chat_chance", 8);
        set("chat_chance_combat", 80);
        set("chat_msg_combat",({
            "�j�{�̹�A�ܹD�G�ڭn���A���Ѩ��Ѥѱ��Ъ��F�`!!\n", 
        }) );
        setup();
        carry_object(__DIR__"eq/dagger4.c")->wield();
        carry_object(__DIR__"eq/surcoat2.c")->wear();
        carry_object(__DIR__"eq/wrists.c")->wear();
}

