inherit ROOM;

void create()
{
        set("short", "商店街－二手商店");
        set("long", @LONG
這裡是間二手商店，專門買賣舊貨，想買便宜貨或是身上有不要的裝備都可
    以在這個地方交易。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"west" : __DIR__"room42",
  "northeast" : __DIR__"room39",
  //"north" : __DIR__"room34",
  "east" : __DIR__"room43",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

