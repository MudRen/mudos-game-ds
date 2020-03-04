// Room: /u/l/luky/room/pearl_24.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIM"珊瑚大道"NOR);
set("long", @LONG

��╲                                                   ╱��
�� :╲    這條路的兩旁長滿了七種顏色的各式珊瑚，你   ╱: ��
�� : :▏本想摘一株回家當紀念，可是又怕被別人看到， ▕: : ��
�� : :▏只好打消了這個念頭。西北方有座美麗的建築物 ▕: : ��
�� :╱  ，南方飄來陣陣的香味。                       ╲: ��
��╱                                                   ╲��

LONG
);
set("exits", ([ /* sizeof() == 2 */
"north" : __DIR__"pearl_23",
"south" : __DIR__"pearl_6",
]));
set("no_clean_up", 0);
set("light",1);
setup();
replace_program(ROOM);
}
