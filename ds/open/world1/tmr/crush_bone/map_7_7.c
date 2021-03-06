#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", HIY"皇帝大廳"NOR);
        set("long", @LONG
這是碎骨寨裡的皇帝大廳，廳內非常寬敞。你注意廳前
有面大桌，桌上似乎有皇帝的昭書(document)。
LONG
);
        set("exits",([
        "south" : __DIR__"map_8_7",
        ]));
        set("call_emperor",1);
        set("item_desc", ([ /* sizeof() == 1 */
  "document" : "一份上頭寫著派兵出城的昭書，需要加蓋\帝印(affix document)才能生效。\n",
]));

    set("objects", ([
        __DIR__"npc/orc_envoy" : 2,
    ]));

        set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
}

void init() {
        add_action("do_affix","affix");
}

int do_affix(string arg) {
        object ob, stamp;

        if(!arg || arg != "document" )
                return notify_fail("你想要做什麼？\n");

        stamp = present("_EMPEROR_STAMP_", this_player());
        if( !objectp(stamp) )
                return notify_fail("你沒有任何可以蓋\印的物品。\n");


        message_vision(CYN"$N"CYN"拿起碎骨帝印，擅自在昭書上蓋\了個大印！！\n"NOR, this_player());

        ob = find_living("_CRUSH_BONE_EMPEROR_");        
        if(objectp(ob) && !objectp(environment(ob))) 
                destruct(ob);

        if( objectp(ob) )
                return 1;
        
        ob = new(__DIR__"npc/orc_herald.c");
        ob->move(this_object());
        ob = new(__DIR__"npc/orc_herald.c");
        ob->move(this_object());
        ob = new(__DIR__"npc/orc_emperor.c");
        ob->move(this_object());

     message("world:world1:vision",
           HIR"\n\t"+ob->name()+HIR"大吼：「竟敢亂動我的帝印！！你這個大逆不道之徒！！"+this_player()->name(1) + "(" + this_player()->query("id") +") 受死吧！！」\n\n" NOR
        ,users() );
        
        destruct(stamp);        
        return 1;
}

