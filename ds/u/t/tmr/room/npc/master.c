#include <ansi.h>
#include "/u/a/anfernee/anfernee.h"
inherit GUILDMASTER;    // �~�� GUILDMASTER �ä��ݭn�A�~�� NPC

void create()
{
        set_name("�s��ɮv", ({"master"}) );
    set("gender", "�k��");
    set("combat_exp", 100000);
    set("long",
    "�L�O�Ѧ�s�⪺���ɱЮv�A���Ѱ򥻪��ޥ��V�m\n"
    "�A�i�H�ϥ�"HIY"list"NOR"�Ӭݬݦ�����ޥ��i�H���ѾǲߡC\n");
        set("no_join", 1);
        set("level", 200);
        set("age", 50);
        set_skill("blade", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set("guild_skills", ([  // // ����, ����1�i�Ǫ��W��, �W��
        "dodge":({30,5,40}),
        "blade":({50,5,35}),
        "sword":({50,5,35}),
        "parry":({30,5,40}),
        "unarmed":({40,5,40}),
        ]) );
        set("chat_chance", 5);
/*  set("chat_msg", ({
    "�s��ɮv�w�w���D:"HIC"�w��U��ɪŮȦ�̦b�o�̾ǲߡC"NOR"\n",
        "�s��ɮv�w�w���b�ж��̺C�C�����ۡC\n",
    }) ); */
        set("inquiry/master", "�ڴN�O�s��ɮv\n");
        setup();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "�s��ɮv�D:"HIC"�w��U��ɪŮȦ�̦b���ǲ߰򥻪��;
                        break;
                case 1:
                        break;
               }
}
