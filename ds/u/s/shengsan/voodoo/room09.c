inherit ROOM;

void create()
{
	set("short", "�C�۶�");
	set("long", @LONG
�A�����b�ѫC�۩Ҭ�X�Ӧ����۶����W,���@�y�������P��N�b�A��
�e��A�A�i�H�M���a�ݨ�y�Ŭr�Сz�T�Ӥj�r���b��W�A�঳�p������
���A�������Y�O���󵥪����H�b�D���аȡC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "up"   : __DIR__"room10",
	    "down" : __DIR__"room08",
            ]));

	set("no_clean_up", 0);
	set("outdoors",1);

	setup();
	replace_program(ROOM);
}
