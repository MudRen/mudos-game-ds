inherit ROOM;

void create()
{
set("short", "愛門村小路");
        set("long", @LONG
這裡是愛門村北邊的小路，沿著這條路過去就可以走上西邊的丘陵。往
北看去仍然是一片的桃樹，有的也已經結出了桃子。碩大的果實令人忍不住
饞嘴地流出的口水來。
LONG
        );
        set("exits", ([
     "east":__DIR__"al2",
     "west":__DIR__"al12",
]));

        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
