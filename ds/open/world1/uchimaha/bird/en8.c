#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit MOBROOM;
void create()
{
 set("short","東北澤林");

 set("long",@LONG
 你現在來到一處土石眾多的地方, 一陣陣的風撲面
 而來, 原來樹上有一堆的蟬正在那嘰嘰的叫著, 但是到
 了這裡, 卻連一隻蟬都沒有, 氣分中帶了一點恐怖, 在
 路旁有一個歪歪斜斜的木牌(sign)。 
 
LONG
    );
 set("item_desc",([
        "sign":"你朝這木牌看了看, 發現上面有幾個大字,

       "HIR"狐 狸 穴     請勿靠近"NOR"

你不禁冷汗直流, 你想想也許\該\回\頭了.\n",
     ]));
 set("exits",(["north":__DIR__"en9",
               "south":__DIR__"en7",
              ]));
 
 set("no_clean_up", 0);
 set("outdoors","land");
 set("chance",80);
        set("mob_amount",3);    
        set("mob_max",15);
        set("mob_object",({     
            __DIR__"npc/fox2",
        }) );
        set("no_clean_up", 0);
        set("outdoors","land");
 setup();
}
void init()
{
        ::init();
        add_action("d_creat","creat");
        add_action("d_stop","stop");
}

int d_stop(string arg)
{
 this_object()->set_temp("stop_creat",1);
 tell_object(this_player(),"怪物地雷已關閉!\n");
 return 1;
}
int d_creat(string arg)
{
this_object()->set_temp("stop_creat",0);
 tell_object(this_player(),"怪物地雷已開啟!\n");
 return 1;
}
