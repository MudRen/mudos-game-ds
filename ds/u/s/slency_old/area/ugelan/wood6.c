// Room: /u/s/slency/area/ugelan/wood6.c

inherit ROOM;

void create()
{
	set("short", "�˪L�`�B");
	set("long", @LONG
�o�̬O�˪L�����o�@�����@���s���A����¶�۳o�Ӽs�����@�Ӷ�
�ΡA�s���W���@�ǧL�������b�a�W�A�A�}�lı�o�o�̦��Ǥ��j��l�F�A
�����a�A�i�H�Pı���L�̦��@�ǲ������`���ۧA
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wood7",
  "east" : __DIR__"wood5",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");
	setup();
	replace_program(ROOM);
}
