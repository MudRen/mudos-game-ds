#include <room.h>
inherit ROOM;

void create()
{
  set("short","�s��");
  set("long",@LONG
�o�̬O�s���@���T�򪺤s���A���W���O�H�ۤl�B�d�کM����A��
�ǭZ�K�����O�M��L�̥i���H�ɦ�����ʪ��|�]�X�ӡA�e�誺����M
�p��¨�����ˡA���O�Q����F�����L�����C
LONG);
  set("exits",([ 
      "east":__DIR__"room91",
      "southwest":__DIR__"room89",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  set("objects",([
      __DIR__"npc/berserk-dog":3,
     ]) );
  setup();
}            
