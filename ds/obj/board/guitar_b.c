#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name("曼妙的吉他之樂 - "HIG"Guitar"NOR, ({ "guitar board", "board" }));
        set("location", "/open/world1/cominging/guitar.c");
        set("board_id", "guitar_b");
        set("long", @long

吉他音樂節奏的曼妙
吉他的可彈奏性、吉他的每一根弦
每一個音，是不是，都能感動你呢？

版主 ewt, cominging

灌版上限: 40 篇

long    );
        setup();
        set("capacity", 40);
        set("master",({ "cominging", "ewt" }));
}
