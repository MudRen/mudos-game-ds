#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�p�{��" , ({ "second fighter","fighter" }) );
        set("level",8);
        set("race","�H��");
        set("gender","�k��");
        set("age",28);
        set_skill("dagger",20);
        set_skill("parry", 20);
        set_skill("dodge", 50);
        set_skill("bird-eight", 40);
        map_skill("dodge","bird-eight");
        set("long",@LONG
�L�O�ѱ��Ъ��p�{��, �ݰ_�ӻ��\����, ���O�Z�\�o�����ˡC
LONG
           );
        set("chat_chance", 8);
        set("chat_chance_combat", 80);
        set("chat_msg", ({"�p�{�̥�½�k�Ī��A���b�m�߭�Ǫ����\\n",
        })); 
        set("chat_msg_combat",({
            "�p�{�̹�A�ܹD�G�ڭn���A����ڤ��O����n�ۭt���I\n", 
        }) );
        setup();
        carry_object(__DIR__"eq/dagger2.c")->wield();
}

