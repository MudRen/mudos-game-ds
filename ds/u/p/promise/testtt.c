#include <ansi.h>
inherit ITEM;
int query_autoload() { return 1; }
void create()
{
        set_name(HIY"��ť��"NOR,({"snoop toll","toll"}));
        set_weight(1) ;
        set("unit", "��");
        set("no_sell", 1);
        set("long",
  HIY"�o�O����ť���A�A�i�H��sn1 <��H>�Ӧw�ˡC"NOR);
}

void init()
{
  add_action("do_sn1","sn1");
}

int do_sn1(string arg)
{
        object ob;
  if( ob = find_player(arg) )
  "/cmds/wiz/promote"->main(this_player(), ob->query("id"));
  return 1;
}

