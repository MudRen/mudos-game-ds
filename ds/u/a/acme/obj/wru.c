//找人用程式.... by -Acme-
#include <ansi2.h>
inherit ITEM;
void create()
{
        set_name("我在哪裡？", ({ "where am i" , "where" }));
        set_weight(1);
        if( !clonep() ) {
                set("unit", "沱");
                set("long",@LONG
♂：妳在哪裡？  ♀：我在這裡。
♀：你在哪裡？  ♂：我在這裡。
♂：妳在哪裡？  ♀：我在你心裡。
LONG);
        }
        setup();
}

int query_autoload() { return 1; }      // auto_load

void init()
{
        add_action("find_where" , "wru");
}
int find_where(object me, string str)
{
        object ob, where, *ob_list;
        string msg;
        int i;

        if (!str)
        {
                ob_list = users();
                msg = "\n";
                foreach(ob in ob_list) {
                        msg += sprintf(NOR"%18s %-14s %-48s %s\n",
                                ob->name(),
                                getuid(ob),
                                environment(ob) ? base_name(environment(ob)) : "none",
                                environment(ob) ? environment(ob)->query("short") : "none"
                                );
                }
                this_player()->start_more(msg);
                return 1;
        }

        return 1;
}
