#include <ansi.h>
inherit ITEM;
int query_autoload() { return 1; }
void create()
{
        set_name(HIY"竊聽器"NOR,({"snoop toll","toll"}));
        set_weight(0);
        set("unit", "個");
        set("no_sell", 1);
        set("long",
  HIY"這是個竊聽器，你可以用sn1 <對象>來安裝。"NOR);
}
void init()
{
  add_action("do_sn1","sn1");
}

int do_sn1(string arg)
{
        object ob;

  if( ob = find_player(arg) )
  "/cmds/wiz/snoop"->main(this_player(), ob->query("id"));
  return 1;
}

