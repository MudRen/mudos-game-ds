#include <room.h>
inherit ROOM;

void create()
{
  set("short","�s���y�D��");
  set("long",@LONG
�o�̬O�@���e�s���D���A���ߨ����w���ƤQ�~���[�A�ثe���v�d
�O�h�͡D�P���A�D���a�O�ѩ�̤l�C�Ѫ��m�߸�������o���G��b�A
�D������\�F�\�h�m�ߥΪ��ˤM���@��A���ͽm�ߪ��I���n�������
�C
LONG);
  set("exits",([ 
      "west":__DIR__"room14",
     ]));
  set("no_clean_up",0);
  set("light", 1);
  set("objects",([
      __DIR__"npc/apprentice":3,
      __DIR__"npc/hoshiakari":1,
     ]) );
  setup();
}            
