
inherit ROOM;

void create()
{
	set("short", "�F�����Y");
	set("long", @LONG
�A�ݨ����⪺����W���X��������A�q����ݥX�h�i�H�ݨ�~����
����C��M���b�A����l�D��F�}�}�������C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "west" : __DIR__"room11",
	    "north": __DIR__"room13",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
