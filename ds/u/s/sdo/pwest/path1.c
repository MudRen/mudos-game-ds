inherit ROOM;

void create()
{
	set("short", "�p�|");
	set("long", @LONG
�o�̬O�@���j���줤���p�|�A���M���O�p�|�A���O�]���p�|�W�O
�ͪ�����A���A���I�d���M���s���O���O���b���T�����W�C�b������
�F��i�H�ݨ��@�j����L�C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 2);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"path2",
	]));

	setup();
	replace_program(ROOM);
}
