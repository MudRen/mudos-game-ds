#include <npc.h>
#include "barbarian_base.c"

void create()
{
        set_name("���Z�H", ({ "barbarian captain","barbarian","captain" }) );
        set("long",@long
�b�A���e���o�ӳ��Z�H�ݰ_�Ӥ��L�H���j�²r�A���G�O�o�����Z
�H������C�@�L����ۤ@�Ǫ��ڥ����ܡA�����b��ݤ���Ʊ��C
long
);
        set_race("human");
        set("title","����");
        set("age", 35);
        set("chat_chance", 5);
        set("chat_msg", ({
                  "���Z�H���⻡�D�G�ute-o tsunai dara itemiyo�v\n",
                  "���Z�H������G�b�ۨ��ۻy�D�G�umo eruyo natsukino kagayaku okani�v\n",

        }));
        set_skill("twohanded blunt",60);        // �����Ϊk
        set_skill("parry",80);
        set_skill("dodge",50);
        setup();
        set_level(20);
        carry_object(__DIR__"obj/monster_pants")->wear();
         carry_object(__DIR__"obj/monster-waist")->wear();
        carry_object(__DIR__"obj/big-blunt")->wield();
}


