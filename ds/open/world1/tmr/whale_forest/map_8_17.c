inherit ROOM;
void create()
{
	set("short", "木橋");
        set("long", @LONG
    你正走在一座用樟樹幹做的木橋上，瞧著木橋上光滑沒生苔的樣
子，似乎這橋常有人來往走動。
LONG
);
	set("exits",([
	"south" : __DIR__"map_9_17",
	"north" : __DIR__"map_7_17",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

