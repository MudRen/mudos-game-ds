// Room: /u/street2.c

inherit ROOM;

void create()
{
	set("short", "��D");
	set("long", @LONG
�@���s�j����D�A�L�����H�s�j���O�����l�̩άO�I�a���l�A���k����
���ɶǨӦ~���h�Q���H���n�A�Ӭݤ��U�D����Ǫ��Цt�ӻաA�����ۡu�ɬ�
�|�v�B�u�ƭ��|�v�������۵P�A���D....�C���F�O���D���A����h�O�Ӽ��x
�������C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"street1",
		"east" : __DIR__"street3",
]));
	set("outdoors","land");

set("light",1);
	setup();
	replace_program(ROOM);
}
