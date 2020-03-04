#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIG"山中廣場"NOR);

 set("long",@LONG
這裡是一個小小的山中廣場, 應該是以前給要通過龍井棧
道的旅人歇息的, 雖然現在龍井棧道已經斷了, 不過來十萬大
山旅遊的旅人還是相當多的, 因此這個小廣場仍然奉有茶水給
過往的旅人飲用.
LONG
    );
 set("exits",([ "west":__DIR__"ten_mountain3",
    ]));
 set("objects", ([__DIR__"obj/pot" : 1,
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}
