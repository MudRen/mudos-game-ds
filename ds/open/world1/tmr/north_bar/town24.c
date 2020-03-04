// Room: /open/world1/tmr/north_bar/town24.c

inherit ROOM;

void create()
{
	set("short", "�_�Z���Ч����a");
	set("long", @LONG
�o�̬O�����a�A�j�U�G�m���j��j���A���䪺���W��
�۲կ���A���P�ۤ@�����A�������P�x�|���᭻���ĦX�b��
�𤤡A�~�Y���ɧj�i�ӷL�L���A���H�Pı�D�`���κZ�C
LONG
	);
	set("light", 1);
        set("valid_startroom", 1);
	set("objects", ([
	__DIR__"npc/mayor" : 1,  ]));
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"town21",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
