// File: /d/duli_port/duli_herb.c
// Updated by tmr (Sat Mar  9 06:48:57 2002)

inherit ROOM;

void create()
{
	  set("short", "�į�M�橱");
	  set("long", @LONG
�o�̬O�@���ᬰ�������į󩱡A�Τl�����C���K���񺡤F�Ī��A�H�K
���ʳ��|���F��A�������d�l�W����P�]���n�X�ӬO�}�ۡA���G�O���D
�H����ѰO���_�_�F�C
LONG
	  );
	  set("exits", ([ /* 1 element(s) */
	"west" : __DIR__"map_18_16",
]));
        set("objects",([
        __DIR__"npc/seller":1,
        ]));


	setup();
	  replace_program(ROOM);
}
