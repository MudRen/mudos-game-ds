#include <ansi.h>
inherit ITEM;

void init() {
        add_action("do_ignite1","DELETE1");
        add_action("do_ignite2","DELETE2");
}

int do_ignite1(string arg)
{
        int i;
        object *obs;
        obs = filter_array( children("/u/t/tmr/game/2006_c/oldman.c"), (: clonep :) );
        for(i=0;i<sizeof(obs);i++)
                destruct( obs[i] );
        tell_object(this_player(), "ok\n");
        return 1;
}

int do_ignite2(string arg)
{
        int i;
        object *obs;
        obs = filter_array( children("/u/t/tmr/game/2006_c/oldman2.c"), (: clonep :) );
        for(i=0;i<sizeof(obs);i++)
                destruct( obs[i] );

        tell_object(this_player(), "ok\n");
        return 1;
}

void create()
{
        set_name("DELETE沖天炮",({"first cannon","cannon"}) );
        set("long",@long
夢幻七域２００６聖誕節活動－獵殺聖誕老人之丙級沖天炮。
你可以使用ignite的指令來點燃發射沖天炮。
long
);
        set_weight(10);
        set("unit","根");
         set("value",1000);
        set("min",10);
        set("max",20);
        setup();
}


