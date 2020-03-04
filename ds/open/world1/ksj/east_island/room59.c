#include <room.h>
inherit ROOM;

void create()
{
  set("short","�s��");
  set("long",@LONG
�o�̬O�X���s�s�}���p�s���A�s�����æӦ���A�O���~���ʩҧ�
�����p���A��ǳ��O����ξ��O�A�s���W�~���F�\�h�۶��A����F�W
�s�����A���ݭn���ܦn�������\�Ҥ~����k�k�V�C
LONG);
  set("exits",([ 
      "southwest":__DIR__"room58",
      "eastup":__DIR__"room89",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  set("objects",([
      __DIR__"npc/eq/big-stone":1,
     ]) );
  setup();
}            

int valid_leave(object me, string dir)
{
  object stayer;

  if( objectp(stayer=present("big stone", this_object())) && dir == "eastup" )
  {
    message_vision("$N�Q�n���s���Y�e�i�A���O�]���۾׹D�ӵL�i�`��C\n"
                   "���D��ӤO�j�L�񪺤H�Ӳ������ۡA�_�h�O�L�k�e�i�F�C\n",me);
    return notify_fail("");
  }
  return ::valid_leave(me, dir);
}
