// Room: /open/world1/cominging/purple_sun/4fs.c

inherit ROOM;

void create()
{
	set("short", "�����s��-�[���x");
	set("long", @LONG
�o�̬O�����s�����@�B�[���x�A���M�Ů��I�}���A���`�O�|��
�@�ǹC�Ȩ즹�C���C�ר�b�Uţ�ѱI���]�ߡA���Y�R��i�ݨ��c�P�I
�I�A�i���O��v���p�ޡA�������A�A����A�L�A������ġC
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"4f1",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
