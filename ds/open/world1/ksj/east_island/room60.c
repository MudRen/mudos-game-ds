#include <room.h>
inherit ROOM;

void create()
{
  set("short","�����");
  set("long",@LONG
�o�Ӧa�q�O�p��t�e�ɳ̯U�i���a�I�A���_�N�O�M�I�������X��
�s�A���n�h�O�޲��������ˡA�ҥH��������ܦb���a�سy����A�H
�Q��Ѫ��A�ƹL�ҾE�A����W���O�E�դΧ|�}�A���L�p�ߤ@�I���ٯ�
�q��C
LONG);
  set("exits",([ 
      "west":__DIR__"room61",
      "south":__DIR__"room58",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  setup();
}            
