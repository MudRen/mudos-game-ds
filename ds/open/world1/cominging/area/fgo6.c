inherit ROOM;

void create()
{
	set("short", "�˪L�X�f����");
	set("long", @LONG
�o�̲ש󦳤@�ǨǨ벴�������g�F�i�ӡA��ӴN�n��F�X�f�A�ߤ�
���ѱo��U�F�ǳ\�A�n��O�����t���˪L�����A�ӥ_��h�O���e������
��V�e�i�h�A�A�{�b���|�Pı�p�����ѩ��a�t�F�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"fgo5.c",
  "northwest" : __DIR__"fgo7.c",
]));
	set("objects",([
  __DIR__"npc/obj/wtree.c" :random(4),
]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
