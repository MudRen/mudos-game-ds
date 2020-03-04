inherit ROOM;
void create()
{
  set ("short", "黃沙鎮外");
  set ("long", @LONG
這裡是黃沙鎮外的邊路，道上黃沙滾滾，大風吹起便如一道道的黃色
暴風，路上寸草不生，景色甚為荒涼，此處再往南便已偏離了黃沙道
的範圍，到黃沙平原中了，而北邊則是黃沙鎮。
LONG
);

  set("exits", ([
  "north" : __DIR__"room15",
  "south" : __DIR__"room25",
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}

