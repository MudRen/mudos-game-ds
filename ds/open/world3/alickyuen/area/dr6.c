// Room: /u/a/alickyuen/area/dr6.c

inherit ROOM;

void create()
{
	set("short", "ST�CHospital�ICorridor");
	set("long", @LONG
�u�۳o�����Y�V�e���A�N��i�h����ͶE�v�C�b�o�̡A�A�w�g�oı��
�@�}�@�P���Ĩ��A�i��O�]������N�O�ĩЪ����Y�a�A�٦n�O�鶴��S��
�`���C�a�W���Ͽj�M��D�`�A�קK�F�f�H�����L�f�r�P�V�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"dr7",
  "south" : __DIR__"dr5",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
