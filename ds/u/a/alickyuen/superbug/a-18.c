// Room: /u/s/superbug/train/a-18.c

inherit ROOM;

void create()
{
	set("short", "�Z������PUB");
	set("long", @LONG
�o�O�@���R�������ݼ֪��ޢ�СA�C�ѵL�ɵL��o�̳������F�@�s��
�g�����~���H�A�b�o�̴M�D�۵u�Ȫ��r�֡A�o�̤]�O��ӳh���ϳ̼��x��
�a��A�p�G�A�Q�n��֨�o�̴N��F�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"a-2.c",
]));
set("item_desc", ([
"�s�d" : "�@�ө񺡰s���s�d�A�ݨ�]�Q���C\n"
]));
set("objects", ([
__DIR__"npc/pub.c" : 1,
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
