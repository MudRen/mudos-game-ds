// Room: /open/world1/tmr/dragoncity/caodi8.c

inherit ROOM;

void create()
{
	set("short", "���S���J-��a");
	set("long", @LONG
�o��O���S���J�s���~���j��a�A���_�i�H�樣�֫ӭx
�P��H�K��ڲצ~���Ԫ��D�n�Ԧa�ж��S���J�s���A���M�o
��S���b�I�Ԥ��A���|�g��^�o�O�R�����ݵ±�����C
���_�A�`�N��O�@�ӭx���n�Ϫ���a�C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : "/open/world1/tmr/crush_bone/map_23_4.c",
  "southwest" : __DIR__"caodi7e",
]));
	set("current_light", 4);
        set("objects", ([
                __DIR__"npc/orc_sentry" : 1, 
        ]) );
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
