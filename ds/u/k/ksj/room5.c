inherit ROOM;

void create()
{
  set("short","ksj ���񪪳�");
  set("long",@LONG
�@���C�񪺤j���A�A�X��i�ʪ��C
LONG
    );
  set("exits",([ 
      "east": __DIR__"room6", 
      "north": __DIR__"room2",
      "south": __DIR__"room8", 
      "west": __DIR__"room4",
     ]));
  set("light",1);
  setup();
}
