#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","廣場");
 set("long",@LONG
這裡是苗家村的主要廣場，孩童到處在這裡嬉戲，據說
苗家村自封建時代時就已存在，外面天翻地覆，這兒卻始終
如一，由於宗族的力量，苗家村一直在十萬大山中與世無爭
的存在著，在廣場中有一個水缸，讓勞累的你一看就感到口
渴囉....
LONG
    );
 set("exits",([   "northwest":__DIR__"ten18",
               "east":__DIR__"ten12",
    ]));
set("objects", ([__DIR__"obj/pot.c" : 1,
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

