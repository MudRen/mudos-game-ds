// Room: /u/t/tmr/area/ms1.c

inherit ROOM;

void create()
{
        set("short", "�ж��p��");
        set("long", @LONG
�A�����b�@�����ж����p���A�ѩ󥿭ȼ��خɴ��A�Ҧ����A�Ҧ��w
�������S�a�b�и̴����A�@���S�@����o�o�����]�b�L�������y�A�R���L
�����;��C�q�ж��p�����F���i�q��s�����F���f�C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
                "west" : __DIR__"ms2",
                "east" : __DIR__"mstart.c",
        "south" : "/open/world1/wilfred/marry/marry_house",
        ]));
        set("no_clean_up", 0);

        set("objects",([
                __DIR__"npc/farmer.c" : 2,
        ]) );
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}

