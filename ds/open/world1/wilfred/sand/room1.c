inherit ROOM;
void create()
{
  set ("short", "���f");
  set ("long", @LONG
�s�������䬰�u�u���F�A�H��Ƥ֡A�B�u�~�Ҧ��r�βr�~�A���X
�~�g�Ӫ��ӤH�ιC�Ȥ����~�A�t�~����W�۶ǵL�c���@�����F���A�i
��b���إߤs��C
LONG
);
  set("exits", ([
  "east" : "/open/world1/tmr/area/vroad3",
  "west" : __DIR__"room2",
]));
  set("objects",([
  __DIR__"npc/npc48" : 1,
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
