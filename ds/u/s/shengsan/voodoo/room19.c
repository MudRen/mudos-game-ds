
inherit ROOM;

void create()
{
	set("short", "�谼���Y");
	set("long", @LONG
�A�ݨ����⪺����W���@�T���e�A�W���e���O�@���j�����r�D����
�@�θ��ʪ����y�A�A�U�ݷU�O�ݤ����C�u�ۨ��Y����ǨC�j�@�q�Z��
�����X�֪��֮��\��ۡC�b�A�����䦳�@�Ӵ[�СC
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	    "west"  : __DIR__"room28",
            "south" : __DIR__"room18",
	    "north" : __DIR__"room20",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
