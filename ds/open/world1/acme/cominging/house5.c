inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�o�̬O��F�x���x��A�b�o�̧A�i�H���F�x�ӽЧ�W�γo�@�Ǧ�
�����F�譱���F��A��F�x����@���pï�l�A�W���g�ۤ@��W�r�A��
�۵��A���G�b���q����C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"path8",
]));
	set("objects",([
  __DIR__"npc/censuser.c" :1,
]));
        set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
