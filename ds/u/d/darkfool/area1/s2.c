// Room: /u/d/darkfool/area1/s2.c

inherit ROOM;

void create()
{
	set("short", "�n��v�ϵ�D");
	set("long", @LONG
�A��b��v�Ϥ����`�J�F�@�Ǫ��a��A���k��Ǫ��t���Ϋ�����
�@�����O�j�P�p���A�èS������ȱo�S�O�`�N���C��������D�O�V�n
�����L�h�C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"s1",
  "south" : __DIR__"s3",
]));

	setup();
	replace_program(ROOM);
}
