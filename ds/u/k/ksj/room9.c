inherit ROOM;

void create()
{
  set("short","ksj 的放牧場");
  set("long",@LONG
一片青綠的大草原，適合放養動物。
LONG
    );
  set("exits",([ 
      "north": __DIR__"room6",
      "west": __DIR__"room8",
     ]));
  set("light",1);
  setup();
}
