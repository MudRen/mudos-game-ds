inherit ROOM;

void create()
{
        set("short", "道路");
        set("long", @LONG
這裡是港都外的道路，再往西走就進到港都了，你看到路上不斷地有商人、馬
    車進出港都，在這邊你就可以聽到市場吵鬧的聲音了。 
LONG

        );
        set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"room54",
  //"east" : "/open/world1/jangshow/barer/road1",
  //"north" : __DIR__"room34",
  "southwest" : __DIR__"room28",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

