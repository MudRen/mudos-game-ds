// Modify with AreaMaker1.0
// Room53.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�A�����b��L�̡C�A�o�{���񦳭Ӽo�󪺹q�u��A�W���w�g�G��
�F�C�a�A�ݨӤw�g�Q��m�F�@�q�ɶ��F�C
LONG
	);
	set("exits", ([
		"north": __DIR__"room43",
		"east": __DIR__"room54",
		"south": __DIR__"room63",
		"west": __DIR__"room52",
	]));
	set("item_desc",([
        "pole":"�@��o�󪺹q�u��(pole)�A�W�������F�C�a�C\n",
        "�q�u��":"�@��o�󪺹q�u��(pole)�A�W�������F�C�a�C\n",
         ]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

