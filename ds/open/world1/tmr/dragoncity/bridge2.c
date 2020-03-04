// Room: /open/world1/tmr/dragoncity/bridge2.c

inherit ROOM;

void create()
{
	set("short", "�Y�s��-�@���j��");
	set("long", @LONG
�A�����b�Y�s�����@���j���A�o�O�@�������ʨӤءA�e���Q�ت�
�j���A�����F�@���e�P�Y�s�����f�����C�C�馳���ְ����B�ӤH�B
�ȫȨӦ^����A��o�D�`���x�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"bridge1",
  "north" : __DIR__"bridge3",
]));
	set("current_light", 2);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
