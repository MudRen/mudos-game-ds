inherit ROOM;

void create()
{
        set("short", "耶子殼酒吧");
        set("long", @LONG
這個酒吧除了賣酒之外，還有賣一些外地的飲料，是從各地來到港
    都的旅客帶來的，所以店中會有些女人、小孩到這裡品嘗新奇的飲
    料。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room18",
  "southeast" : __DIR__"room23",
  //"northeast" : __DIR__"room16",
  "east" : __DIR__"room20",
]));  
        set("objects",([
    __DIR__"npc/room19-boss":1,
]));
        set("light",1);

        setup();
        //replace_program(ROOM);
}

