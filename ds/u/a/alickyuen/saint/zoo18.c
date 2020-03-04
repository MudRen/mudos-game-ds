// Room: /u/a/alickyuen/area/zoo18.c
//updated by 26/12
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", HIC"ST。Secret＠CyberZoo"NOR);
        set("long", @LONG
這是小屋內的一間空房間，這裡非常簡陋，只有一個衣櫃。但你看到
了一個人正站在房間的正中央，他鬼鬼祟祟的不知他在打什麼主意。同時
，你也看到這裡有一個二個的籠子放在地上，而你看到籠子裡竟然有．．
．．．．
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"zoo17",
]));
create_door("out","大鐵門","enter",DOOR_CLOSED);
set("objects", ([
__DIR__"npc/seller2.c" :1,
]));
        set("light",1);
        set("world", "future");
        set("no_clean_up", 0);
        set("item_desc",(["衣櫃":"一個普通的衣櫃,裡面放著一些衣服。\n",])); 
        setup();
}

void init()
{
        add_action("do_search","search");
}

int do_search(string arg)
{
object ring;
        object me;
        me=this_player();
        if (!arg || arg != "衣服") 
                   return 0;
        if(query_temp("getring")) 
                return notify_fail("找了又找，終究一無所獲...\n");
        message_vision("$N在衣服裡找了找，終於給你找到了一隻綠色的戒指。\n\n" ,me);
        ring=new(__DIR__"obj/ring");
        ring->move(me);
        set_temp("getring",1);      
        return 1;  
}

void reset()
{
        if(query_temp("getring") )
                delete_temp("getring");
}

