inherit ROOM;
void create()
{
        set("short", "狐穴");
        set("long", @LONG

LONG
);
        set("exits",([ 
        "northwest" : __DIR__"map_0_0", 
        "southwest" : __DIR__"map_2_0",
        "northeast" : __DIR__"map_0_2",
        ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

