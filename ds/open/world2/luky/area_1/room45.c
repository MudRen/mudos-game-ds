// Modify with AreaMaker1.0
// Room45.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�A����o�̤��Tı�o���I�֤F�A�����n���ӥ��Y�i�H���A��
�@�U�C�_�䪺�j��Ǫ��F�@������A�����٦��Ǽo�󪺶������A�u��
�����N���K�Q�ө��i�H�R�Ƕ��ƨӸѸѴ��C
LONG
	);
	set("exits", ([
		"east": __DIR__"room46",
		"south": __DIR__"room55",
		"west": __DIR__"room44",
	]));
 	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/bird1" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

