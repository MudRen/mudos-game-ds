// Room: /open/world1/tmr/xiangyang/westjie1.c

inherit ROOM;

void create()
{
        set("short", "西大街");
        set("long", @LONG
這是一條寬闊的青石板街道，向東西兩頭延伸。西邊是一
個大十字街口。東面是襄陽的中央廣場，北邊是人稱郭大俠郭
靖的府邸大門，不時地有人從那裡進進出出。南面是一家當鋪，
聽說裡面常能買到你所需的東西。
LONG
        );
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/poorman" : 1,
]));
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"westjie2",
  "north" : __DIR__"dangpu",
  "east" : __DIR__"westjie1_e1.c",
//    "north" : __DIR__"guofugate",
]));
        set("current_light", 1);
        set("no_clean_up", 0);
        set("outdoors", "xiangyang");

        setup();
        replace_program(ROOM);
}

