inherit ROOM;

void create()
{
	set("short", "���Y");
	set("long", @LONG
�o�̬O�@���ܰ��b�����Y�A���Y�W���\�h���ܲL������A�ä����
����A���Y�����쩳�N�O�e�������D�n���Y�A�A�ݨ�_�䦳�@�����Ъ�
�A���G���誺�Фl�٭n�n�h�F�C

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"flurry48.c",
  "southdown" : __DIR__"flurry44.c",
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}
