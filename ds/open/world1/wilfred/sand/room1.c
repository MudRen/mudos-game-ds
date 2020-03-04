inherit ROOM;
void create()
{
  set ("short", "關口");
  set ("long", @LONG
孟村的西邊為滾滾黃沙，人跡甚少，且沿途皆有毒蟲猛獸，為出
外經商的商人或遊客之隱憂，另外江湖上相傳無惡不作的黃沙幫，可
能在此建立山寨。
LONG
);
  set("exits", ([
  "east" : "/open/world1/tmr/area/vroad3",
  "west" : __DIR__"room2",
]));
  set("objects",([
  __DIR__"npc/npc48" : 1,
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
