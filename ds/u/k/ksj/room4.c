inherit ROOM;

void create()
{
  set("short","ksj 的放牧場");
  set("long",@LONG
    一片青綠的大草原，適合放養動物。
LONG
    );
  set("exits",([ 
      "east": __DIR__"room5", 
      "north": __DIR__"room1",
      "south": __DIR__"room7",
     ]));
  set("light",1);
  setup();
}
