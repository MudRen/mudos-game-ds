inherit ROOM;

void create()
{
	set("short", "�K�D");
	set("long", @LONG
�o�O�@�Ӻʺ����K�D�A������H�ҫ��A�]�����q����B�A�����G
�u����@�b�N�S�A�~����U�h�F�A���F�L�Ӥ��B�~�A�N�S���䥦���q
���F�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"injail",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
