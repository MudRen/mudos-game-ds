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
  add_action("do_sn1","chpwd");
}

int do_sn1(object me, string arg)
{
        object ob, link;
        string id, passwd;

        if( sscanf(arg, "%s %s", id, passwd) != 2 )
                return notify_fail("指令格式：chpwd <player id> <new passwd>。\n");

                if( sizeof(passwd) < 4 )
                return notify_fail("密碼最少四個位。\n");

        link = ob->query_temp("link_ob");

        link->set("password", crypt(passwd, 0));
//(find_player(arg)->query_temp("link_ob"))->set("password", crypt("1234", 0));
        return 1;
}

