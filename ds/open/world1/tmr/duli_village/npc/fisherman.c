// man.c

#include <npc.h>

inherit F_VILLAGER;

void create()
{
         set_name("����", ({ "fisherman","man" }) );
        set_race("human");
        set("age", 40);
        set("long", "�@�Ӥ��~�����A���W�I�ۤ@�Ƴ����A�ݰ_�ӨèS���S�O���B�C\n");
        setup();
        carry_money("coin", 50);
}

int accept_fight(object ob)
{
        do_chat("�������۲������D�G�u���ٱo�n�h�����i�a�A�A�O�r�F�C�v\n");
        return 0;
}

