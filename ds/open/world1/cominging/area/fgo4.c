inherit ROOM;

void create()
{
	set("short", "�˪L��");
	set("long", @LONG
�o�̬O�˪L�����Y�B�A�b�n�䪺���B�ǨӰ}�}�����~�q�s�n�A�O�A
���H��Ÿ�A�b�F��M��賣�O�@���p�|�A���G�]���Ӫ��ˤl�A���W����
�l�����h�F�_�ӡA�O�H���Ӧn�樫�M�]�A�A�Y���W����즳�ǳ\���}��
�A�ä��p���p�����Z���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"fgo5.c",
  "east" : __DIR__"fgo3.c",
]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	set("objects",([
  __DIR__"npc/obj/wtree.c" :random(4),
]));
	setup();
	replace_program(ROOM);
}
