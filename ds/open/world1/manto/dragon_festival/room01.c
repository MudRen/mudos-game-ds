inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIY"獨醒亭"NOR);
        set("no_fight", 1);
  set("light",1);
        set("long", @LONG

    此亭四周松柏參天，修竹常青，山石秀麗，碧水環流，一派迷人的
江南景色。而大廳中立有屈原塑像，似乎正吟誦著「路漫漫其修遠兮，
吾將上下而求索」的千古佳句。兩旁的廳柱則懸有清朝郭嵩燾撰寫的楹
聯：
          哀郢矢孤忠，三百篇中獨宗變雅開新格；
          懷沙沉此地，兩千年後唯有灘聲似舊時。

LONG
        );
    set("exits",([
 "out" : __DIR__"room02",
]));
        set("objects", ([ 
  __DIR__"mob03" : 1,
]));
        set("no_clean_up", 1);
        setup();
        replace_program(ROOM);
}
