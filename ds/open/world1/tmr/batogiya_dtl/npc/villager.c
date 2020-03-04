#include <npc.h>

inherit F_VILLAGER;

void create()
{
    set_name("����", ({ "villager" }) );
    set_race("human");
    set("age", 6);
    set("long", "�@�Ӧ�b�������������A���G�L�Ҩƨƪ��b��W�C��\n");
    setup();
    switch( random(5) ) {
       case 0: carry_object(__DIR__"obj/cloth")->wear(); break;
       case 1: carry_object(__DIR__"obj/armor")->wear(); break;
       case 2: carry_object(__DIR__"obj/belt")->wear(); break;
       case 3: carry_object(__DIR__"obj/boots")->wear(); break;
       case 4: carry_object(__DIR__"obj/gloves")->wear(); break;
    }
    carry_money("coin", 500);
}

int accept_fight(object ob)
{
    do_chat("���������������D�G�u�����I�N�̧A�]�Q��ڥ��H���I�v\n");
    return 1;
}

