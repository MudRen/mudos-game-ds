inherit ROOM;

void create()
{
  set("short","ksj ���񪪳�");
  set("long",@LONG
�@���C�񪺤j���A�A�X��i�ʪ��C
LONG
    );
  set("exits",([ 
      "west": __DIR__"room1",
      "east": __DIR__"room3",
      "south": __DIR__"room5",
     ]));
  set("light",1);
  setup();
}
