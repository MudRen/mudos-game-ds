inherit ROOM;

void create()
{
   set("short","貨櫃屋");
   set("long", @LONG
這裡是存放物品的地方。
LONG );
  set("light", 1);
  set("exits", ([/* sizeof() == 2 */
"south" : "/u/s/sexking/workroom.c",
]));
    setup();
}
