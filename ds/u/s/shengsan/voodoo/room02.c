inherit ROOM;

void create()
{
	set("short", "�A�L�۶�");
	set("long", @LONG
�F�F���˸��n�q�A���䩻�h�A���R������b�˪L�����s�A���O
���ި��Ǧ����򴺦�A�A�����٬O�b�O�H���a�L�W�A�٬O�p���I�n�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "up"   : __DIR__"room03",
	    "down" : __DIR__"room01",
            ]));

	set("no_clean_up", 0);
	set("outdoors",1);
	setup();
	replace_program(ROOM);
}
