#include <room.h>
inherit ROOM;

void create()
{
  set("short","�s��");
  set("long",@LONG
�o�̬O�s���@���T�򪺤s���A���W���O�H�ۤl�B�d�کM����A��
�W�N�O�X���s���s�y�����F�A�q�o�̬ݹL�h�A�s�yŢ�n�۲H�H������
�C
LONG);
  set("exits",([ 
      "northeast":__DIR__"room99",
      "up":__DIR__"room102",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  setup();
}          

int valid_leave(object me, string dir)
{
  if( me->query("orochi_beast_1") )
  {
    if( dir == "up")
      return notify_fail("");
  }
  return ::valid_leave(me, dir);
}  
