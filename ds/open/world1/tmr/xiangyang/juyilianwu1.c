// Room: /open/world1/tmr/xiangyang/juyilianwu1.c

inherit ROOM;

void create()
{
	set("short", "�m�Z��");
	set("long", @LONG
�o�̬O�E�q�]���Ψӽm�\���a��C���X�ӤH���b�M�߭P�P
�a�m�Z�A���X�Ӥ���L���A�b���۩�ۡC���k�F�ʡA�S�p���
�����@��A�A���T�ݪ�F���A�O���H�h���b�a�W���Z�ΤW�W�m
���O�C
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"juyiyuan",
]));
	set("coor", ([ /* sizeof() == 3 */
  "y" : -501,
  "x" : -529,
  "z" : 0,
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
