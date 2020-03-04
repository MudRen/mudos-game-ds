// Room: /u/a/aring/tomb/11.c

inherit ROOM;

void create()
{
	set("short", "�j�Ӷ�мX��");
	set("long", @LONG
�A�����b�@�y�X�Ӫ��W�Y�A�o�̪����p�u�O�رi�A�X�Ӵä�Q���X
�r�S�åB�}�a�o�u�ѸH���A��B�O���e�����A��b�O�G���Ը@�C
LONG
	);
	set("light", "0");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"12.c",
  "west" : __DIR__"10.c",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
