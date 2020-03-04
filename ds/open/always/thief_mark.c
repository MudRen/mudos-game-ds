// �{�N���|¾�~�H�� (�p�����|-Thief)
// �s�g��: Luky 1999.9.5
//
//
#include <weapon.h>
#include <ansi.h>
#define THIEF_D "/daemon/thief.c"
inherit DAGGER;

void create()
{
set_name("�U��P��",({"multi-function dagger","dagger","guild_mark"}));
set_weight(1000);
set("long",@LONG
�o�O�@��H�x�s�骺�P���A�P���O�H���ÿ����y�۷��T�@�ΡC
�P�������`�����æ��@�Ƕ}��u��A�O�p���̤��i�ʤ֪��򥻤u��C
�A�i�H��(help thief)�d�ݤp�����|�i�Ϊ����O�C
LONG
);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "iron");
		set("unit", "��");
		set("value",0);
		set("no_sell",1);
		set("no_drop",1);
		set("limit_con",1);
		set("limit_str",1);
		set("limit_int",1);
		set("limit_dex",1);
		set("backstab_bonus",15); //�ʤ���
	}
	set("no_get",1);
	init_dagger(7);
	setup();
}

void init()
{
 if(this_player()!=environment(this_object())) return;
//      add_action("do_help","help");
 	add_action("do_hide","hide");
 	add_action("do_sneak","sneak");
 	add_action("do_backstab","backstab");
 	add_action("do_team_backstab","team_backstab");
 	add_action("do_peep","peep");
 	add_action("do_steal","steal");
 	add_action("do_pick","pick");
}

int do_help(string arg)
{
	return THIEF_D->do_help(this_player(),arg);
}

int query_autoload() { return 1; }
string query_guild() { return "thief"; }

int do_backstab(string arg)
{
	return THIEF_D->do_backstab(this_player(),arg);
}

int do_team_backstab(string arg)
{
	return THIEF_D->do_team_backstab(this_player(),arg);
}

int do_sneak(string arg)
{
	return THIEF_D->do_sneak(this_player(),arg);
}

int do_hide(string arg)
{
	return THIEF_D->do_hide(this_player(),arg);
}

int do_peep(string arg)
{
	return THIEF_D->do_peep(this_player(),arg);
}

int do_steal(string arg)
{
	return THIEF_D->do_steal(this_player(),arg);
}

int do_pick(string arg)
{
	return THIEF_D->do_pick(this_player(),arg);
}
