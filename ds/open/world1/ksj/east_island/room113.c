#include <room.h>
inherit ROOM;

void create()
{
  set("short","�X���s��");
  set("long",@LONG
�o�̬O�X���s���s���A�|�B�����b��A�G�������ճ��A�j�l���N
�����a�����¶�b���ۤ����A�A�`�N�즳�����������n���Q����F��
�i�L�����A��o������ơA�A���G�ݨ즳�¼v�b���_���̰ʡC
LONG);
  set("exits",([ 
      "east":__DIR__"room114",
      "southwest":__DIR__"room111",
      "south":__DIR__"room112",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","snow");
  setup();
}            
