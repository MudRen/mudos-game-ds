// Room50.c

inherit ROOM;

void create()
{
        set("short","【正雲堂】");
        set("long", @LONG
你一到這裡就被地上奇怪的東西絆倒，抬頭一看原來是
各種練習輕功的器具，右方有個書架上面擺滿了各門各派的
輕功武學正當你看的專注的時候，身旁卻出現了千萬條黑影
包圍著你，當你正覺得震驚時他卻現身告訴你：【你的輕功
還不到家，不過經過我的鍛鍊會讓你更厲害喔!!青衣人很得
意地 口圭 口合 口合 口合 ∼∼∼地笑了起來 :O】
LONG
        );
        set("exits", ([
                "east": __DIR__"room25",
        ]));
        set("objects",([
                "/open/world1/npc/goldman3" : 1,
		__DIR__"item/goldman1" : 1,
        ]));
        set("light",1);
set("no_goto",1);
        setup();
}
