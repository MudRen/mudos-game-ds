inherit ROOM;
void create()
{
	set("short", "林中小路");
        set("long", @LONG
    你正走在一座用樟樹幹做的木橋上，瞧著木橋上光滑沒生苔的樣子，
似乎這橋常有人來往走動。橋下的河水正潺潺地流過去，水面上幾片落葉
載浮載沉的隨水流移動。

LONG
);
	set("exits",([
	"west" : __DIR__"map_12_15",
	"east" : __DIR__"map_12_17",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

