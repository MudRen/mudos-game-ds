inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
test 
�����s���y���R�W -���z
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"room40", 
  //"southwest" : __DIR__"room40", 
  //"east" : __DIR__"room38", 
]));
set("light",1);

        setup();
}

