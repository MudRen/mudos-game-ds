#include <room.h>
inherit ROOM;

void create()
{
  set("short","�s��");
  set("long",@LONG
�o�̬O�s���@���T�򪺤s���A���W���O�H�ۤl�B�d�کM����A��
�ǭZ�K�����O�M��L�̥i���H�ɦ�����ʪ��|�]�X�ӡA����O�@�B�s
���A�¶·t�t�a�ݤ��M���̭�������C
LONG);
  set("exits",([ 
       "west":__DIR__"room95",
       "north":__DIR__"room96",
       "south":__DIR__"room93",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  setup();
}            
