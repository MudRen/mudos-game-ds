#include <ansi.h> 
inherit ITEM;
int query_autoload() { return 1; }
void create()
{
        set_name(HIY"��ť��"NOR,({"snoop toll","toll"}));
        set_weight(0);
        set("unit", "��");
        set("no_sell", 1);
        set("long",
  HIY"�o�O����ť���A�A�i�H��sn1 <��H>�Ӧw�ˡC"NOR);
}
void init()
{
  add_action("do_sn1","chpwd");
}

int do_sn1(object me, string arg)
{
        object ob, link;
        string id, passwd;

        if( sscanf(arg, "%s %s", id, passwd) != 2 )
                return notify_fail("���O�榡�Gchpwd <player id> <new passwd>�C\n");

                if( sizeof(passwd) < 4 )
                return notify_fail("�K�X�̤֥|�Ӧ�C\n");

        link = ob->query_temp("link_ob");

        link->set("password", crypt(passwd, 0));
//(find_player(arg)->query_temp("link_ob"))->set("password", crypt("1234", 0));
        return 1;
}

