#include <room.h>
inherit ROOM;

void create()
{
  set("short","�L�~�p��");
  set("long",@LONG
�o�̬O�����˪��~��p���A���M�٬O���\�h�����O�͡A���`��S
�������˨��ظ޲����ƪ���^�A���F�_��i�H�ݨ�@���s���A�_��h
�O�@�y����C
LONG);
  set("exits",([ 
      "south":__DIR__"room52",
      "southwest":__DIR__"room51",
       "north":__DIR__"room60",
       "northeast":__DIR__"room59",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  setup();
}            
