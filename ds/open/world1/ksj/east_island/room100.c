#include <room.h>
inherit ROOM;

void create()
{
  set("short","�s��");
  set("long",@LONG
�o�̬O�@�B���`���s���A�s���W�O�~�k�������A���ɦ��۶���
�y�u��s���e�A�|�P�������W���F�@�������p��A�ͩR�O��������
���|�B�k��A��w�����ۤ]�Q���}�F���_�C
LONG);
  set("exits",([ 
      "north":__DIR__"room98",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  set("objects",([
      __DIR__"warrior-ice-statue":1,
     ]) );
  setup();
}            
