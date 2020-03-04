// Room: /open/world1/tmr/frost/hill1.c

inherit ROOM;

void create()
{
	set("short", "�ʾ]�s-�s�y�p�|");
	set("long", @LONG
�ʾ]�s�a�������A���٭ʾ]�o�|�u�p�K�A�צ~�����@������C�o����
�b�b�s�y���D���A������i�H�q�����V�ⶳ�p���̹D�A���F�����B�O�@�y
�y�է������D�[�A���F�_�誺�L�D�i�����@�B�[���x�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"observatory",
  "west" : __DIR__"footway3",
  "east" : __DIR__"temple",
]));
	set("current_light", 2);
	set("no_clean_up", 0);
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
