inherit ROOM;

void create()
{
        set( "short", "地底神殿遺跡") ;
        set( "long", @LONG
迎面而來的撲鼻臭味，混雜著灰塵和腐敗的味道，看來這個遺跡
已經很久沒有人進來過了，大概都是被剛剛的守護石雕像擋在外面了
吧，不知道這古怪的地方還有什麼玄機。
LONG
);
        set("exits", ([ /* sizeof() == 4 */
                  "south" : __DIR__"room-02",
                  "north" : __DIR__"room-05",
                  "northeast" : __DIR__"room-06",
                  "northwest" : __DIR__"room-04",
        ]));
        set("light",0);
        set("no_recall","神殿內部的磁場遮蔽了所有的傳送力量。");
        set("no_clean_up", 0);
        setup();
}
