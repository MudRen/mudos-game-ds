
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���R���ᦷ�b�o�Ӫ������ꪺ���ۡA�S�����R���p���γ�Ũ�A�A
ı�o�ܯS�O�C�q�o���_���O�q���оª����Y�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
            "west" : __DIR__"room32",
	    "south": __DIR__"room31",
	    "north": __DIR__"room34",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
