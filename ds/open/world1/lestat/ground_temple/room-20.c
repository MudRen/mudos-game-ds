inherit ROOM;

void create()
{
        set( "short", "地底神殿遺跡") ;
        set( "long", @LONG
越向遺跡內部進入，越覺得奇怪，四周的建築風格與入口處的古
樸完全不同，乳白色的牆壁上刻著許多奇怪的花紋，似是一種文字，
除此之外還散發著青綠色的螢光，提供了照明。
LONG
);
        set("exits", ([ /* sizeof() == 3 */
                  "west" : __DIR__"room-19",
                  "northeast" : __DIR__"room-26",
                  "southeast" : __DIR__"room-16",
        ]));
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall","神殿內部的磁場遮蔽了所有的傳送力量。");
        setup();
}

