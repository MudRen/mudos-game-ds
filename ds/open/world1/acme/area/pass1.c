// Room: /u/a/acme/area/pass1.c

inherit ROOM;

void create()
{
	set("short", "�s��");
	set("long", @LONG
�A�����b�@���������s���A�|�P�ɬO�s��A���q�ﶳ�A���_����i��
���r���A�r��������h�˦��@���i���R�����������s�A�ä��ɪ��ǨӼR�q
�n�C���n�i�q���ѫ��A�_��i�ܤѦ��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"pool",
  "south" : __DIR__"pass",
]));
	set("no_clean_up", 0);
    set("outdoors","land");

	setup();
	replace_program(ROOM);
}
