// Room: /d/xiangyang/southjie2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�n�j��");
	set("long", @LONG
�o�̬O�������̪��c�ئa�q�A���M�[�g�Ԥ��A���b���t��
�H���O�äU�A�������Ѧʩm�L�۫D�`�w�wíí���ͬ��C����O
���������̤j���@�a����C�F��O�@�y��h���ӻաA���ۡ��s��
����î�A���B�W�a���@���СA�W�ѡ��V���ӡ��T�r�C�@�}�}
�s�׭�������ӨӡC
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : __DIR__"nixianglou",
		"west"  : __DIR__"duchang",
		"south" : __DIR__"southjie3",
		"north" : __DIR__"southjie1",
	]));
	set("objects", ([
	//	"/d/city/npc/liumang" : 1,
	]));
	set("coor/x", -500);
	set("coor/y", -530);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}