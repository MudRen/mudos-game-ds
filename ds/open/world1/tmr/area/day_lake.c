// Room: /u/t/tmr/area/day_lake.c

inherit ROOM;

void create()
{
	set("short", "�¤Ѵ�");
	set("long", @LONG
�¤Ѵ�A�S�W���Ὼ�A�����a�������W���_���C��b�Q�X�~�e�u�O��
���⥭�`���j��A��ӨӤF�@�ӦW�s������ѭ�A�󩤮ǰ�g�@���A�s��
��h�A�u��q���ܻT�A�򤤺ؤ��⽬��A���}����A�����A�����r�A����
ŧ�H�A�|�ɴ��P�A�������ɡA�H�Y�����n�W�j���A����]�b��ǫؤF�Ӥ�
�Ωw�~�U�ӡC							
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"round1",
//   "north" : __DIR__"day_lake2",
  "southeast" : __DIR__"lake-road1",
  "west" : __DIR__"square",
]));
set("objects",([
	__DIR__"npc/traveler.c" : 2,
]) );

	set("outdoors","land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
