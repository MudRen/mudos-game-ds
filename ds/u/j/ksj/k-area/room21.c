inherit ROOM;

void create()
{
        set("short", "瞭望台");
        set("long", @LONG
這裡有一座木頭架成的高台，是海軍用來監看海岸用的，台上備
    有狼煙，有事發生的時候能迅速的通知分部，台下有幾名海軍在
    站崗。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room10",
  //"southeast" : __DIR__"room24",
  //"northeast" : __DIR__"room16",
  "east" : __DIR__"room22",
])); 
        set("light",1);
        set("outdoors","land");

        setup();
        //replace_program(ROOM);
}


