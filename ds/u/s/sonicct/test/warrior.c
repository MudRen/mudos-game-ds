#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIR"�Ԥh�ɮv"NOR, ({"master warrior","warrior","master"}) );
	set("long", 
    "�L�O�Ԥh���ɱЮv�A���Ѱ򥻪��ޥ��V�m�C�A�i�H��\n"
    "��"HIR"list"NOR"�Ӭݬݦ�����ޥ��i�H���Ѿǲ�(train)\n"
    "�C�]�i�H��advance <level���ݩ�> �Ӥɯ�, �ɯūe��ĳ\n"
    "���ϥ�level ���O�Ӭd�\\�һݭn���g��ȡC\n"
    );

	set("race", "�H��");
	set("no_join", 1);
	set("age", 37);
set("level",50);
        set("attitude", "heroism");
        set_skill("parry",100);
set_skill("fogseven",100);
set_skill("fork",100);
        set_skill("dodge",100);
        set("guild_skills", ([
        "dodge":({50,5,35}),
        "parry":({30,5,40}),
        "unarmed":({40,5,40}),
        ]) );
set("chat_chance_combat", 80);
set("chat_msg_combat", ({
(:command,"exert fogseven":),
}) );

	setup();
carry_object("/u/s/sonicct/test/finallance.c")->wield();
}
void init()
{
        object ob;

        ::init();
                if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("d_advance","advance");
        add_action("d_list","list");
        add_action("d_train","train");
}
int d_advance(string arg)
{
 return GUILDMASTER->do_advance(this_object(),this_player(),arg);
}

int d_list(string arg)
{
 return GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
}

int d_train(string arg)
{
 return GUILDMASTER->do_skill_train(this_object(),this_player(),arg);
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "�Ԥh�ɮv�D:"HIC"�w��U��Ԥh�b���ǲߧޥ��C"NOR"\n");
                        break;
                }
}
