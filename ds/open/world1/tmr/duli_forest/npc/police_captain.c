#include <npc.h>

inherit F_SOLDIER;

void create()
{
    set_name("�u�òλ�", "duli police captain", "police","captain");
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
    �o�O�@�ӭt�d�޲z�i�J������_��˪L�J�f���u�òλ�A�ѩ��~��
�ǻD�˪L�̦��Y�H�����]���ǡA�ϱo�H�ߴq�q�A�ҥH��ĵ�F�����S���X
�ժZ���O��ĵ�����O�@�w�����d���C�ӳo�Ӳλ�N��O�@���u�äp�ժ�
�ժ��A�t�d�o���I�O�C
long
);
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: command, "berserk" :)
    }));
    setup();
    set_level(20);
    carry_object("/d/obj/longpike")->wield("twohanded pike");
    carry_object("/d/obj/armor")->wear();
}
void init()
{
    ::init();
    add_action("intercept", "go");
    add_action("intercept2", "north");
}
int accept_fight(object ob)
{
        return 1;
}

int intercept(string arg)
{
    if( (arg!= "north") || !this_player()->visible(this_object()) ) return 0;
    write( name() + "�N�A�d�F�U�ӡC\n");
    do_chat((: command, "say �g���˪L���]�~�X�S�A�����H�����n�H�N�i�h�C":) );
    return 1;
}
int intercept2()
{
    if(!this_player()->visible(this_object()) ) return 0;
    write( name() + "�N�A�d�F�U�ӡC\n");
    do_chat((: command, "say �g���˪L���]�~�X�S�A�����H�����n�H�N�i�h�C":) );
    return 1;
}

