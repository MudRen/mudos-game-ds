#include <npc.h>

inherit F_VILLAGER;

void create()
{
    set_name("�p��", ({ "child" }) );
    set_race("human");
    set("age", 6);
    set("long", "�@�Ӧ�b���������p�Ĥl�A�ѯu�L�����ҼˡA�L���L�L���W���C\n");
    setup();
    carry_money("coin", 50);
}

int accept_fight(object ob)
{
    do_chat("�p�į����������D�G�u�����I�ݧګ��~��A�C�v\n");
    return 1;
}

