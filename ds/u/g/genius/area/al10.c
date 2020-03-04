inherit ROOM;

void create()
{
set("short", "愛門村小路");
        set("long", @LONG
這裡有條岔路一直往西邊丘陵通去，西邊丘陵也種植了不少的花木。蒼
翠的林木使得整個山顯得非常協調，令人不禁為大自然生生不息的生命感到
一種極度的震撼。往稍西北邊望過去還可以看到一片火紅的花海，更是美麗
非常，令人嚮往。
LONG
        );
        set("exits", ([
     "north":__DIR__"al11",
     "south":__DIR__"al9",
     "northwest":__DIR__"m1",
]));

        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

