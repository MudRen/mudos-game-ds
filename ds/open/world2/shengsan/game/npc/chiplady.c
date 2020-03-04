// chiplady.c			Shengsan@DS	1999.4.4
// �w�X�p�j

#include <ansi.h>
inherit NPC;
inherit __DIR__+"chiplib.c";

int to_say_chip();

void create()
{
	set_name("�e��",({ "mill","chip lady","lady" }));
        set("level",9);
	set("title","�w�X�p�j");
	set("race", "�H��");
	set("gender","�k��");
	set("age", 19);
	set("long",
@LONG
�i�R���R���p�j, �A�i�H������o���w�X. ( ask mill about chip )
LONG
        );
	set("attitude", "friendly");

	set("inquiry",([
           "�w�X": (: to_say_chip :),
           "chip": (: to_say_chip :),
	]));
        setup();
        seteuid(getuid());
}

void init()
{
	add_action("do_change","change");
}


int do_change(string schip)
{
	object me;
	int chip;
	me = this_player();

	if(!schip)
	{
		command("think");
		command("say "+me->query("name")+"�A�A�n�X�T�w�X�ڡH");
		return 1;
	}
	if(sscanf(schip,"%d",chip)!=1)
	{
		command("?");
		command("say "+me->query("name")+"�A�A�n�F���ڡH");
		return 1;
	}
	if(me->can_afford(chip*10)==0)
	{
		command("say "+me->query("name")+"�A�A���G�S������h���ӶR�w�X�H");
		return 1;
	}

	me->receive_money(chip*(-10));
	Game_receive_chip(chip,me);

	message_vision("$N���X"+F_VENDOR->price_string(chip*10,me->money_type())+"��"+query("name")+"�C\n",me);
	command("smile");
	command("say "+me->query("name")+"�A�o�ǬO�A�n���w�X�C");
	return 1;
}


int to_say_chip()
{
	object me = this_player();
write(@HELP

        ��  �O                         ��    ��
=====================================================================
	change <�w�X��>		�Ψ��W�����ӧI���w�X
=====================================================================

HELP);
	command("say �ثe�O"+F_VENDOR->price_string(10,me->money_type())+"���@�T�w�X�C");
	return 1;
}
