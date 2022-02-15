inherit ROOM;

void create()
{
  set("short", "海岸");
  set("long", @LONG   
這裡是港口的海岸邊，腳底下是用石塊鋪成的道路，岸邊放有許
多大岩石用來抵擋海浪的侵襲，海浪不時地拍打岸邊激起陣陣水花。
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room1",
      "northwest" : __DIR__"room8",
      "southeast" : __DIR__"room10",
     ]));
  set("outdoors","land");
  setup();
}
