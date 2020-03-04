// Room: /u/t/tmr/area/smith.c

inherit ROOM;

void create()
{
        set("short", "���K�Q");
        set("long", @LONG
�o�̬O�@�����K�Q�l�M��W���F�\�h�K�����b���~��u��M�Q�l����
�@�ӿN�ۺ������V�����l�M�o�A�b��W���v�l�@�̤@�̪��M�����٦��@��
�H�����j�K�z�M�Q�l���X�f�N�b�n��C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
 		 "south" : __DIR__"street3.c",
         "east" : "/open/world1/wilfred/newbie/eq_fixroom",
	]));

        set("objects", ([
                __DIR__"npc/smith" : 1,
        ]));
	set("light",1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
