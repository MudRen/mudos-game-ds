#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short",HIC"�m�C���s���n"NOR);
  set ("long", @LONG
���G�o��N�O�ȪŶ��������A�ݨ�b�Ǫ�����쳣���G�u��
���A���T���q�߲z�تA���Ӽh��D���\�O�`�p�A����̤��O�K���
���s�������p���ݮݦp�͡C
LONG
);
  set("exits", ([
  "northwest" : __DIR__"4f_8",
    ])); 
   
  set("no_clean_up", 0);
  set("light",1);
  setup();
 }



