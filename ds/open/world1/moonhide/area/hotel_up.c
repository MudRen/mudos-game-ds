// Room: /open/world1/moonhide/area/hotel_up.c

inherit ROOM;

void create()
{
	set("short", "�H�B�ȴ̤G��");
	set("long", @LONG
�o�̬O�H�B�ȴ̪�2�ӡA���X�i��l�����F�ȤH�A���b�ܰs
�Y�סA���ɥ�ͳ̪񪺦����D�A�n�����x�C
LONG
	);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"hotel",
]));
	set("no_clean_up", 0);
    set("objects", ([ /* sizeof() == 2 */
  "/open/world1/tmr/advthief/thief_adv_master" : 1,
]));


	setup();
	replace_program(ROOM);
}
