// Room: /open/world1/tmr/north_bar/town27.c

inherit ROOM;

void create()
{
	set("short", "�_�Z���ЪZ����");
	set("long", @LONG
�Ө�o�̡A�A�o�{��W���۳\�h�Z���A�M�B�j�B�C��������
�A���䪺���K�l���{�ۿK�������K�A����ӾǮ{���b���̺V�۶�
�N�������K�A�m�m�N�N���Q���n�ġC
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"town26",
]));
	set("current_light", 1);
        
        set("objects", ([
                "/open/world1/wilfred/newbie/eq_master.c" : 1,
        ]) );
        


	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
