inherit ROOM;

void create()
{
      set ("short", "����");
      set ("long", @LONG
�o�̥|�P���O�P�P�ճ��A�@���կ������A�O�H���@�ثܵΪA���Pı�A
���O�]���Ѯ�H�N�A�O�A���ѦۥD���o�_�ݨӡA�_�観�@�����㪺�D���A��O
�ߤ@���X���C
LONG);
      
  set("exits", ([ 
  "northeast" : __DIR__"snow3",
  "south" : __DIR__"snow1",
  ]));

 set("outdoors", "snow"); 
 set("no_clean_up", 0);

  setup();
}

