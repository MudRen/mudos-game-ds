#include <npc.h>

inherit F_SOLDIER;

void create()
{
    set_name("�u��ĵ��", "duli police", "police");

    set_race("human");

    set_skill("twohanded sword", 60);
    set_skill("blunt", 100);
    set_skill("sword", 100);
    set_skill("parry", 90);
    set_skill("unarmed", 80);
    set_skill("dodge", 90);
    set_skill("blade", 70);
    set_skill("berserk", 150);
    set("title","�����˪L");
    set("long",@long
    �o�O�@�ӭt�d�޲z�i�J������_��˪L�J�f���u�áA�ѩ��~�ӶǻD
�˪L�̦��Y�H�����]���ǡA�ϱo�H�ߴq�q�A�ҥH��ĵ�F�����S���X�ժZ
���O��ĵ�����O�@�w�����d���C
long
);
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
        (: command, "berserk" :)
    }));
    // ������
    //set("vendetta_mark", "duli_port");
    setup();
    set_level(15);
	carry_object("/d/obj/longpike")->wield("twohanded pike");
	carry_object("/d/obj/armor")->wear();
}

int accept_fight(object ob)
{
        return 1;
}


