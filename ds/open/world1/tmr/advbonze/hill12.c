// Room: /open/world1/tmr/advbonze/hill12.c

inherit ROOM;

void create()
{
	set("short", "�ⶳ�p�b�s�y-�p���a");
	set("long", @LONG
�A���B�b�ⶳ�p�b�s�y���@���p�Ŧa���A�o�����a����ب��e
�Ӥw�A�j���u�i�e�ǥ|���ӤH�b���𮧡A�Ŧa����F�X���j���Y�A
�ݥ��Y�W������a�A�ݼˤl���G�֦��H�ӳo�C�b�Ŧa���_����V�A
���M�O�u�W�ѱ�v���D���C
LONG
	);
	set("current_light", 3);
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hill13.c",
  "southwest" : __DIR__"hill11",
]));

	setup();
	replace_program(ROOM);
}
