inherit ROOM;

void create()
{
  set("short","ksj ���񪪳�");
  set("long",@LONG
�@���C�񪺤j���A�A�X��i�ʪ��C
LONG
    );
  set("exits",([ 
      "north": __DIR__"room5",
      "west": __DIR__"room7",
      "east": __DIR__"room9",
     ]));
  set("light",1);
  setup();
}
