// Room: /u/a/alickyuen/area/dr32.c

inherit ROOM;

void create()
{
	set("short", "ST�CHospital�IWorkroom");
	set("long", @LONG
�o���N�O�|���ǤF�A�o�̪��G�m�O�A�e�ҥ�������������A�ݤW�h��
���O�@�ǶQ���f�~�A�N���D�o�Ӱ|�����a���׫p�F�K�K�L�ۧA�i�Ӥ���A
�N�@���@����ۧA�A�Aı�o�ۤv�n�����B��ު������K�K
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"dr29",
]));
set("objects", ([
__DIR__"npc/leader.c" : 1,
]));
	set("world", "future");
set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
