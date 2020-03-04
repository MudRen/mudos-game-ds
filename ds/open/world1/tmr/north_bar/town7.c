// Room: /open/world1/tmr/north_bar/town7.c

inherit ROOM;

void create()
{
	set("short", "�_�Z���Фj���B");
	set("long", @LONG
���e�o�f�ƤQ�~���j���O�o�ǧ����ͬ����̥D�n���ѵ��ӷ�
�A�b�X�Q�~�e�N�Q�o�̷�a���~�������X�ӡA���̭��@�ݡA���O
�M�����b�������A�ܰ_�����Ӭ۷��f�C���_����V�O�@�y�۾�
�A�۾��U�������������۸��A���_�����|�q�줰��a��C
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"town6",
  "north" : __DIR__"town8",
  "east" : __DIR__"town15",
  "west" : __DIR__"town14",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("current_light", 2);
    set("objects", ([
        "/open/world1/obj/well" : 1,
        __DIR__"npc/traveller" : 1,
    ]) );


	setup();
	replace_program(ROOM);
}
