//by lestia

inherit "/u/l/lestia/workroom2.c";
#include <ansi.h>
void create()
{
        set("short", HIW""BLK"邪闇"HIW"之間"NOR);
        set("long",
"\n你站在一片虛無的大地之中，灰暗的天緩緩的流動著，\n"
"你眼觀四周，發現這裡除了沉寂之外還是沉寂，你沉默\n"
"不語，慢慢的將心中的雜念去除，只留下邪惡的念頭，\n"
"等待著最後之日的降臨。\n\n"
);
   set("light", 1);
        set("no_clean_up", 0);
 set("valid_startroom", 1); 
 set("exits", ([ 
"wiz":"/d/wiz/hall1",
"area":"/u/l/lestia/area/map_7_3.c",
"up":"/u/l/lestia/work/post.c",
"luky":"/u/l/luky/workroom.c",
 ])); 
        setup();
call_other("/obj/board/lestia_b.c","??????");
}

