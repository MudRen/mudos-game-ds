inherit ROOM;

void create()
{
        set("short", "碎石子路");
        set("long", @LONG
走到這一段路，前方長滿雜草幾乎快看不到路面，當微風吹過就像綠色波浪
    一般起伏，但行走起來可是很不方便。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"northwest" : __DIR__"room46",
  "southeast" : __DIR__"room49",
  //"north" : __DIR__"room34",
  "west" : __DIR__"room47",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

