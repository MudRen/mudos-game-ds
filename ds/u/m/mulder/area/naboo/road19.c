// Room: /u/s/sonicct/area/road19.c

inherit ROOM;

void create()
{
	set("short", "Naboo���t��");
	set("long", @LONG
���L�@�Ӽ��x���s����A�A��ı�o�̩M��~���s�����n�j�����O
�b�o�̪��H���h�A���O�C�ӤH�������c�����ˤl�A�n���n���F�A�@��
�A�A�߷Q�n�ɧ����}�o�̡C���_���i�H��^�s���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road8",
 "southwest" : __DIR__"road20",
   ]));
		 set("objects",([
  __DIR__"npc/bru":1,
 ]));
	set("outdoors","road");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
