#include "path.h"
inherit ROOM;

void create()
{
        set("short", "石階");
        set("long", @LONG
疲憊，無限的疲憊，使你這個身經百戰的超級戰將，也不得不好
好休息一番；你左晃晃，右晃晃，找個乾淨的地方，屁股坐下，抬頭
仰望天空，哇！真是太美了！星空、極為美麗的星空！從這裡放眼望
去，宇宙中的各種星座盡收眼底，有如絲綢般的銀河、閃耀且迷人的
星星，將你一路上所帶來的辛苦及不快，一掃而去，你真有點捨不得
起身離去。
LONG
        );

        set("exits", ([
 "east" : HOLY+"h21",
 "westup" : HOLY+"h19",
        ]) );
        set("light",1);
        setup();
}
