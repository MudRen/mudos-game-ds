inherit ROOM;

void create()
{
	set("short", "�˪L��");
	set("long", @LONG
�A�Ө�F�o���٤���w�R���a��A�a�W�����ӴX���p�s�ޡA�򱵤]
�l�ӤF�X�������W���ʪ��A���䪺��F�W���\�h�����Ʀb�ԾĪ��u�@�A
�ӤѮ�p���������A���H���T�تA��@�O�A�{�b�A�]���Ƿd���M�F�n��
�_�A�]�H�K�è��@�q�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"fgo6.c",
  "east" : __DIR__"fgo4.c",
]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	set("objects",([
  __DIR__"npc/obj/wtree.c" :random(4),
]));
	setup();
	replace_program(ROOM);
}
