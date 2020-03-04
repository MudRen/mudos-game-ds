#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"茅屋"NOR);

 set("long",@LONG
你一踏進這間茅屋, 立刻被滿屋子的雜物給嚇到了, 你微定心
神, 忽然想起數年前在江湖已買賣雜貨出名的陶章, 據說他後來看
破世間名利, 退隱到十萬大山中, 原來他就是退隱到此處和一群高
人為友....
LONG
    );
 set("exits",([ "north":__DIR__"eastroad3",
    ]));
 set("objects", ([__DIR__"npc/tao_chaung" : 1,
    ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}
