// Room: /open/world1/acme/bonze/b15.c

inherit ROOM;

void create()
{
	set("short", "�٫߰|");
	set("long", @LONG
�o�̬O���ǧ٪����H�b�������`��A�b���L�����a��A�o��Ū�
�������A���e�u���@�i�p���Τ@�Ӥj��Z�A���W��ۤ@�Ӥj�쳽
�A���G�O���ǧٹ��H�ϥΪ��C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"b14",
]));
set("objects",([
   __DIR__"npc/b_bonze" : 1,
]) );
        set("light",1);

	setup();
	replace_program(ROOM);
}
