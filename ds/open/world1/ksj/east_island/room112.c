#include <room.h>
inherit ROOM;

void create()
{
  set("short","�X���s��");
  set("long",@LONG
�o�̬O�X���s���s���A�|�B�����b��A�G�������ճ��A�j�l���N
�����a�����¶�b���ۤ����A�A�`�N�즳�����������n���Q����F��
�i�L�����A��o������ơA�a�W�s�P�����\�h�j���ʪ����e���C
LONG);
  set("exits",([ 
      "east":__DIR__"room115",
      "west":__DIR__"room111",
      "north":__DIR__"room113",
      "south":__DIR__"room110",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","snow");
  setup();
}            
