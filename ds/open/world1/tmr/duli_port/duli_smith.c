// File: /d/duli_port/duli_smith.c
// Updated by tmr (Thu Feb 28 03:30:14 2002)

inherit ROOM;

void create()
{
	  set("short", "������-�Z���M�橱");
	  set("long", @LONG
�o��O�@����y���ЫΡA�����Ʃ�ۤ@�若�K�γѪ��o�K�A�Τl����
��ۤ@�Ӥj���l�A���Y���������N�ۤQ�������A�@�Ѫ��ꪺ���𪽼��V�A
�ӨӡC
LONG
	  );
	  set("exits", ([ /* 1 element(s) */
	"west" : __DIR__"map_2_16",
]));
	  set("objects", ([ /* 1 element(s) */
	__DIR__"npc/yakasi" : 1,
]));

	setup();
	  replace_program(ROOM);
}
