#include "/u/l/lary/area/holy/path.h"
inherit ROOM;

void create()
{
        set("short", "聖域入口");
        set("long", @LONG
遠古的傳說，神秘力量的所在；相傳，古老的聖域中，隱居了一
群擁有強大力量的神秘人物，以往，曾有無數的勇士前來探險，卻都
一去不回，而現在，在你眼前，就是那傳說中聖域的大門，看著那遠
方完全被神秘所籠罩的聖域， 你真不知該不該舉步向前...
LONG
        );

        set("exits", ([
 "west" : HOLY+"h2",
        ]) );
        set("light",1);
        setup();
}
