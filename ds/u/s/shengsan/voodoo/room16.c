
inherit ROOM;

void create()
{
	set("short", "�谼���Y");
	set("long", @LONG
�A�ݨ����⪺����W���X��������A�q����ݥX�h�i�H�ݨ�~����
����C�u�ۨ��Y����ǨC�j�@�q�Z�������X�֪��֮��\��ۡC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room10",
	    "west" : __DIR__"room17",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
