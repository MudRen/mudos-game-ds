#include <ansi2.h>

inherit NPC;

void create()
{
        set_name("�����s", ({ "shan" }) );
        set("gender", "�k��" );
        set("title", "�Τ�");
        set("age", 54199);
        set("long","���j�ɥN�ҩ��s���ߤ@�ΤѱڤH�A�A�i�H�V�L�ǲ�(learn)�ԻR(combat dance)�C\n");
        set("level",1);
        set("attitude", "friendly");
        setup();
}

void init()
{       
    add_action("do_learn", "learn");
}

int do_learn(string str)
{
    if( !str || str != "combat dance")
        return notify_fail("�A�n�V�����s�ǲߤ���H\n");

    if( this_player()->query("level") < 50 ) 
        return notify_fail("�ǲ߾ԻR�������Ť��Q�H�W�C\n");

    if( this_player()->query("war_art") < 999 )
        return notify_fail("�A���԰����N���� 999 �I�A�L�k�ǲߡC\n");

    if( this_player()->query_skill("combat-dance") )
        return notify_fail("�A�w�g�ǹL�ԻR�F�C\n");

    this_player()->add("war_art", -999);
    this_player()->set_skill("combat-dance", 20);

    message_vision(HIW"$N�V$n�бЦ����u�ԻR�v���R�аʧ@�C\n"NOR, this_player(), this_object());

    return 1;
}
