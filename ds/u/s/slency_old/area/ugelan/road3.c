// Room: /u/s/slency/area/ugelan/road3.c

inherit ROOM;

void create()
{
	set("short", "�C�۵�D");
	set("long", @LONG
�o�O�@���c�ت���D�C���_��@�ݦ��@�Ӥj�j���۵P�W�g�ۡi����
���j�A�ܩ��㪺�O�@���M�樾�㪺�ө��A��D�������@�ʦʦ~����A��
�֤W���h�h�K�P�����F���몺����A�ܦh�H�ΪA�a�b�𽮤U���D�A�@��
�۷�y�����ˤl�C
LONG
	);
	set("outdoors", "land");	
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"road2",
  "east" : __DIR__"road17",
  "north" : __DIR__"defense",
]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
