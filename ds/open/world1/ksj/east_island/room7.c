#include <room.h>
inherit ROOM;

void create()
{
  set("short","��D");
  set("long",@LONG
�o�̬O��������D�A�b�o��w�g�i�H�ݨ���l�̭����@�ǩЫΤ�
�ؿv�A�H�ӤH���ݰ_�ӫܼ��x�A���ɦ��Ӯa�p�c�D�۳f���X�J���l�A
���F�i�H���X���l�e������C
LONG);
  set("exits",([ 
      "out":__DIR__"room6",
      "west":__DIR__"room11",
     ]));
  set("no_clean_up",0);
  set("outdoors","land");
  set("objects",([
      __DIR__"npc/villager":3,
     ]) );
  setup();
}            

int valid_leave(object me, string dir)
{
  if( me->query("village") )
  {
    if( dir == "out")
      return notify_fail("");
  }
  return ::valid_leave(me, dir);
}
