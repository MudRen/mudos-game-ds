// Room: /u/s/sonicct/area/shop3.c

inherit ROOM;

void create()
{
	set("short", "���㩱");
	set("long", @LONG
�o�O�@��²�䪺���㩱�A���O�Ȧ�H�h�g�`�X�J���a��C��
���������U���U�˪�����A�ѤH�Ȧۤv�ʶR�A�٥H�Q���X�z����
����X�C
LONG
	);
	set("light",1);
	set("no_skill",1);
	set("no_clean_up", 0);
	set("room_type","sell");        
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"road4",
  "south" : __DIR__"road10",
  ]));
	set("no_clean_up",0);

	setup();
	replace_program(ROOM);
}
