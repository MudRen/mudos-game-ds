// Room: /u/s/sevil/1f/16.c

inherit ROOM;

void create()
{
	set("short", "�e�s�����D");
	set("long", @LONG
�o�̬O�e�s�����D�A��Ǫ��ӳ����A�ݪ��ؤ��v���A�����D
�ө����䨫�~��H�b�p���_��O�@�����W�����Q�A�M��@�Ǻ�o
�������A����O�@���ۦW���Ƨ��~���A�M��@�ǰ�~���Ƨ��~�A
�n��O�ʳf���q���j���C

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"17.c",
  "north" : __DIR__"21.c",
  "south" : __DIR__"11.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
