// Room: /u/s/sonicct/area/shop7.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�o�̪����p�M�J�f�t���h�E�P�A���ݨӱ��p�}�l�|���ﵽ��
���L�A�̥D�n�O�p�c�̪��۫ߡC��M�@�s�p�c�V�A�i�}�L�����~
���A�R�A�A���{�k�פ~�k���F�A�u�T�V�C���n�ONaboo�����s���C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"road17",
  "south" : __DIR__"road18",
  ]));		 set("objects",([
  __DIR__"npc/antiquer":1,
 ]));
	set("no_kill",1);
	set("outdoors","land");
	set("room_type","shop");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
