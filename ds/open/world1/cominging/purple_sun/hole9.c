// �����s���ݤs�}��

inherit ROOM;

void create()
{
	set("short", "�s�}��");
	set("long", @LONG
�o�̬O�s�W���@�Ӥs�}���A�s�}���s�j�A�٦��\�h�����~�A�_�Ǫ�
�O�A�o�Ӥs�}�����Ӥp�s���@�ˡA���Ҧ��ˡA�}�~���j�����ɪ��h�i��
�A�I�I���T�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hole8.c",
  "south" : __DIR__"hole6.c",
]));
	set("objects", ([
  __DIR__"npc/big_bear" : 2,
]));
	set("world", "past");
	set("no_clean_up", 0);
	set("light",1);

	setup();
	replace_program(ROOM);
}
