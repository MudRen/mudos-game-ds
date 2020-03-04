
inherit ROOM;

void create()
{
        set("short", "凌雲峰頂-平台北角");
        set("long", @LONG
你正站在凌雲峰頂上北角的一處平台中，在你前方不遠處供奉著一尊
「伏魔羅漢石像」，在往前數步就是峰頂的崖邊，地上積雪日深，稍一踩
不穩，就會連滾帶爬的摔下山去。遠方的日光經由雪地而反射在你眼睛上
，使得你的雙眼有點難過的睜不開來。
LONG
        );
        set("current_light", 1);

        set("no_clean_up", 0);
        set("outdoors", "snow");
        set("exits", ([ /* sizeof() == 1 */
         "south":__DIR__"summit1.c"
]));

        setup();
        replace_program(ROOM);
}

