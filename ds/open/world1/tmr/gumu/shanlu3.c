// shanlu3.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
這條山路盤著終南山主峰而上，山路貼著石璧鑿出，只容許一人得
過，形勢極為險峻。往遠處望去。群山環繞，列於腳下，百里美景盡收
眼底，頓時令人豪氣陡昇，想要長嘯一聲。往東下和南上各是一條山路。
LONG    );
        set("outdoors", "forest");
        set("exits", ([
                "southup"  : __DIR__"shanlu2",
                "eastdown" : __DIR__"shanlu4",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

