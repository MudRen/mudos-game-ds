inherit ROOM;

void create()
{
        set("short", "碎石子路");
        set("long", @LONG
這一段路上有些泥窪，加上雜草覆蓋走起來怪不舒服的，路旁一棵枯樹傾倒
    佔住大半的路面。 
LONG

        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"room50",
  "east" : __DIR__"room52",
  //"north" : __DIR__"room34",
  //"west" : __DIR__"room47",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

