// Room: /open/world1/tmr/bagi/house.c

inherit ROOM;
void open_star2() {
    "/adm/daemons/event/bagistar.c"->trigger_event();
}

void open_star() {
    call_out("open_star2", 60+random(30));
}
void create()
{
        set("short", "�˫Τ�");
        set("long", @LONG
�A���b�@���A�˺Ѻ�a�۪c�����˫Τ��A�Τ����@��@�ȵ��a��ҤD
��˽s���A�㶡�Τl���B�b���s���a�����A�A�o��ı�o�H�N�C�ˮ�W���P
�ۤ@���M���������C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
          "east" : __DIR__"ghat2",
        ]));
        set("objects",([
        __DIR__"npc/advmaster":1,
        ]) );
        set("light",1);        
        set("valid_startroom",1);
        set("world", "past");
        set("no_clean_up", 0);

        setup();
}

