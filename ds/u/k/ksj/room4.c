inherit ROOM;

void create()
{
  set("short","ksj ���񪪳�");
  set("long",@LONG
    �@���C�񪺤j���A�A�X��i�ʪ��C
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
