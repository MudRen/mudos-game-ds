inherit ROOM;

void create()
{
  set("short","ksj ���񪪳�");
  set("long",@LONG
�@���C�񪺤j���A�A�X��i�ʪ��C
LONG
    );
  set("exits",([ 
      "west": __DIR__"room2",
      "south": __DIR__"room6",
     ]));
  set("light",1);
  setup();
}
