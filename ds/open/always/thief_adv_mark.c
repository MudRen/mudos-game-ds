// �{�N���|¾�~�H�� (�p�����|-Thief)
// �s�g��: Luky 1999.9.5
//
// �i����-Tmr
#include <weapon.h>
#include <ansi.h>
#define THIEF_D "/daemon/thief_adv.c"
inherit DAGGER;

void create()
{
        set_name("�s�骺���P",({"advanced thief dagger","dagger","ADVANCED_THIEF_MARK"}));
        set_weight(1000);
        set("long",@LONG
�o�O�@��H�x�s�骺�P���A�P���O�H���ÿ����y�۷��T�@�ΡC
�A�i�H��(help advanced thief)�d�ݤp���i���|�i�Ϊ����O�C
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
//        if(this_player()!=environment(this_object())) return;
//        add_action("do_help","help");
       if(wizardp(this_player())) add_action("do_backstab","stillhunt");

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

