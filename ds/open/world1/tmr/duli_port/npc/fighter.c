#include <npc.h>
inherit F_VILLAGER;
void create()
{
        set_name("�氫�a", ({ "fighter" }) );
        set("long",@long
�@�ӷ����Z���氫�a�A�����b����Ǩ�@�ǪZ�N�A�ݼҼ˨�������F���C
long
);
        set_race("human");
        set("age", 24);
        advance_stat("gin",50);
        advance_stat("hp",50);
        set_attr("str",25);
        set("chat_chance", 5);
        set("chat_msg", ({
                "�氫�a�k���@���B���A�@�x���m�_�\�Ҩ�....\n",
                "�氫�a�u�ܡv�a�@�n�A���G�b�m���򥴮𪺥\�ҡA���G�~����䪺�H..\n",
                "�氫�a���ۻy�D�G�u�o�M�\�ҦA�m�@�}�l�A���ӴN��A�H�j���F�a�C�v\n",
        }));

        //set("title","");
        setup();
		set_level(3);
        carry_object(__DIR__"obj/fighter-cloth")->wear();
}

int accept_fight(object ob)
{
        do_chat("�氫�a�\�F�Ӭ[�աA���D�G�u�ٽЫ��ɤ@�G�A�ӧa�C�v\n");
        return 1;
}

