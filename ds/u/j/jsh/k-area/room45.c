inherit ROOM;

void create()
{
        set("short", "碎石子路");
        set("long", @LONG
這裡是港都 賽安尼爾斯外的道路，路上鋪滿著碎石子，隱隱有車輪的痕跡，
    雜草稀疏地從石縫中長出，看來這條路很少人走。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room41",
  "southeast" : __DIR__"room46",
  //"north" : __DIR__"room34",
  //"east" : __DIR__"room45",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

