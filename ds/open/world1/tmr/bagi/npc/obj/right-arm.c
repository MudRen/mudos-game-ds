#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("不知名的右臂",({"unknown right-arm","arm","DOLL_RIGHT_ARM"}));
        set_weight(100);
        set("unit","隻");
        set("long",@LONG
這是一隻打造的十分精巧的假手臂，不管是肘關節、手指關節等，連
皺褶細紋等，也是非常逼近真人手臂的狀態，真可是非常高深的塑模功夫。
LONG
                );
        setup();
}


