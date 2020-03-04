inherit ROOM;

void create()
{
        set("short", "固山寨");
        set("long", @LONG
不遠處，一群討伐軍士兵正在操練，這些士兵分作兩隊，正
在進行對練，而兩隊士兵手上赫然拿的是真刀真槍，金鐵相交的
的聲音不絕於耳。
LONG);
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"camp019",
  "west" : __DIR__"camp012",
]));
        set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

