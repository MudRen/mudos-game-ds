// Room: /future/area/digging_road1.c

inherit ROOM;

void create()
{
	set("short", "�q�ϹD��");
	set("long", @LONG
�A�����b�q�ϸ̪��@���D���A���䦳���W�Ҥw�����ª��s�]�A�q�o�N
�iť��D�`���m���H�n�A�ݱo�X�Ӱs�]�̫D�`�����x�A���F��h�i�ݨ�@
���ᬰ�j�����u�t�A����a�����K�[�u�t�C���_���h�i��F���q�ϡC
LONG
	);
	set("world", "future");
	set("exits", ([ /* sizeof() == 3 */
	  "north" : __DIR__"digging_road4",
	  "west" : __DIR__"hotel",
	  "east" : __DIR__"digging_road2",
	]));
	set("outdoors","desert");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
