inherit ROOM;

void create()
{
	set("short", "�s�Ǵ˪L");
	set("long", @LONG
�o�̬O�˪L�����@���A�b�P�򦳵ۤ@�������p�D�A�O�P��H�a�ҹ}
�i���A�����D�����]���]��˪L���Ӱg���A�o�̤j�������O�@�Ǧ˪L
�P�_����G���j�ۦP�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"psin2.c",
  "northwest" : __DIR__"psin4.c",
//      "west" : "open/world1/moonhide/area/room1", // �¥j��
      "west" : "/open/world1/tmr/gumu/shulin1",// �s�j�� Tmr 2006/10/23
]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
