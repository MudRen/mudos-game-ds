// Room: /u/a/alickyuen/area/dr2.c

inherit ROOM;

void create()
{
	set("short", "ST�CHospital�IDoor");
	set("long", @LONG
�o�̴N�O��|���j���f�A�@�Ǩ����˪��H���ѳo�̺�檺�e�i�h�A��
���@�ǤH�a�ۥͪG�x���H�i�h����ۤv���ˤ͡A�H�ӤH���A�i��N�O�]��
�u���@���j����|�A�Ҧ����H���i�ӳo�̨���A�i���o����|�����i�M��
�f�H���H�ߡC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"dr1",
  "in" : __DIR__"dr3",
]));
	set("world", "future");
set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
