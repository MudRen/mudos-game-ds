#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�p��" , ({ "waiter" }) );
        set("level",10);
        set("race","�H��");
        set("gender","�k��");
        set("age",30);
        set_skill("dagger",20);
        set_skill("parry", 20);
        set_skill("dodge", 40);
        set("long","�L�O�M�����U�H�{���p��, ���O�A�ݥL�}�B����, ���D�L�O�Ӧ��m�Z���H�C\n"
           );
        set("chat_chance", 200);
        set("chat_msg_combat",({
            "�p�̳ܹD�G�ڭn���A���D�p�̬O���n�S��!!\n", 
        }) );
        setup();
        carry_object(__DIR__"eq/dagger2.c")->wield();
}

