// Room: /d/death/gateway.c

inherit ROOM;

void create()
{
	set("short", "�Z������");
	set("long", @LONG
�A�{�b�Ө�@�y�¦⫰�Ӥ��e�M���ӤW��ۤT�Ӥj�r�R�Z�����C��
�n�����B���@�y���M���W���v�l�l�M���O�oť����b�I�n���M���_���i
���ӥu���@���º������M�u���ֳ\�t���⪺�����Y���Y�{�a�{�{�ۡC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : "/d/death/road1",
		"south" : "/d/death/gate",
	]));
	set("objects", ([
		__DIR__"npc/bgargoyle": 1
	]) );

	setup();
}

int valid_leave(object me, string dir)
{
	if( wizardp(me) || !userp(me) ) return 1;

	if (dir == "south") {
		return notify_fail("�@�ӪŬ}���n���b�A�����T�_....\n"+
			       "�S���^�Y���F!\n");
	}
	else return 1;
}


