// Room: /open/world1/tmr/bagi/ghat9.c

inherit ROOM;

void create()
{
	set("short", "�N����e");
	set("long", @LONG
�A���b�N���������A�]���B���L����󬰬�X�A�ҥH�۵M�Φ��F
�@�B�b�q���a��C�b���B�A�i�H�ݨ��ߤ������B�h�x�_�`�Ŧ⪺���A�b
�A�J���[��U�A�A����@�W������Ѵ򩳪��F�򭱡A�Ӧ��W�W�����@���A
����������γ~�C���W�u�O�ѩ�Q�B�h�ҳ�¶�ۡA�ҥH�b���B�ɬݤ�����
�W�C
LONG
	);
	set("world", "past");
	set("outdoors", "snow");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ghat8",
  "east" : __DIR__"ghat7",
]));
	set("no_clean_up", 0);
    set("objects",([
     __DIR__"npc/cmoon2":1,
    ]) );

	setup();
	replace_program(ROOM);
}
