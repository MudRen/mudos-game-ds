// Room: /open/world1/tmr/bagi/ghat4.c

inherit ROOM;

void create()
{
        set("short", "���a");
        set("long", @LONG
�A���b�@���B�ѳ��a�����A�ѩ�a�B�󰪤s�W�A�צ~�U���A�|�P�u��
�Ʈ���C���Q�f�A����n�観���e�f�A���F�_��L�h�A�����󲱡C�����a
���G�樣�@���j��C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
          "northeast" : __DIR__"ghat6",
          "southwest" : __DIR__"ghat3",
        ]));
        set("outdoors","snow");
        set("world", "past");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
