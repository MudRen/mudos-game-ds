inherit ROOM;

void create()
{
        set("short", "碎石子路");
        set("long", @LONG
走到這裡發現路好像縮小了，原來是兩旁的雜草佔掉了一些路面，路當中
    隆起一堆黃土，上面長滿齊腰的雜草。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"room46",
  //"southeast" : __DIR__"room47",
  //"north" : __DIR__"room34",
  "east" : __DIR__"room48",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

