// Room: /u/m/mulder/area/shop2.c

inherit ROOM;

void create()
{
	set("short", "�s���o�� - ��D");
	set("long", @LONG
�A�}�l�@�B�@�B�V�e��A�ӧA���߱��]�}�l�ܱo��i�A�]��
�o�O�\�h�H�����u�ɪű���v�Ҧb�a�D�ڻ����ܦh�L�����H���i
�ӱq���]�����F�A��ĵ��]���H�i�ӧ�M���ܪ��H�A���X�^��
���H���ѰO�F�o�ͤ���ơA�Q�������D
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road13",
  "south" : __DIR__"road6",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
