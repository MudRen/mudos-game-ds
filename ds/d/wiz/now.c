inherit ROOM;

void create()
{
        set("short", "現代小組會議室");
        set("long", @LONG
現代小組巫師們討論的地方.........
LONG
        );
        set("light",1);
        set("exits", ([
        "up"     :       __DIR__"hall1",
        ]));
        call_other("/d/wiz/now_b","???");
        setup();
}
