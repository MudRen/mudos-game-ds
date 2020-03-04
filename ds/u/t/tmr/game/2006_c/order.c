// 2006/12/14

#include <ansi.h>
inherit ITEM;

int do_wehre();

void create()
{
        set_name("追殺令",({"killer order","order"}) );
        set("long",@long
夢幻七域２００６聖誕節活動－獵殺聖誕老人之追殺令。
你可以使用locate的指令，查出散落在各地的聖誕老人。
long
);
        set_weight(10);
        set("unit","塊");
        set("value",5000);
        setup();
}

void init()
{
        add_action("do_where","locate");
}

int do_where() {
        object me;
        object ob, *mans, where, *ob_list;
        string msg;

        me = this_player();
        mans = filter_array( children("/u/t/tmr/game/2006_c/oldman.c"), (: clonep :) );
        ob_list = sort_array( mans, (:
                        strcmp( environment($1) ? file_name(environment($1)) : "",
                                        environment($2) ? file_name(environment($2)) : "" )
                :) );
        msg = "共有"+ sizeof(ob_list)+"隻聖誕老人：\n";

        if(wizardp(me)) {
                foreach(ob in ob_list) {
                        if( !environment(ob) || !ob->visible(this_player()) ) continue;
                        where = environment(ob);
                        msg += sprintf("%14s%-12s - %10s %-45s\n",
                                ob->name(),
                                "("+ ob->query("id") +")",
                                 (string)where->query("short"), (string)file_name(where));
                }
        } else {
                foreach(ob in ob_list) {
                        if( !environment(ob) || !ob->visible(this_player()) ) continue;
                        where = environment(ob);
                        msg += sprintf("%14s%-12s - %10s\n",
                                ob->name(),
                                "("+ ob->query("id") +")",
                                 (string)where->query("short"));
                }
        }
        msg += "\n";

        me->start_more(msg);
        return 1;
}

