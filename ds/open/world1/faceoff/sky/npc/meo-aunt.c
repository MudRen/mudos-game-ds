#include <ansi.h>
inherit NPC;
void create()
{
 set_name("苗大嬸",({"meo aunt","meo","aunt"}));
 set("long",@LONG
苗大嬸在苗家村已經生活四十多年了，見識過很多奇怪
的事，為人又樂善好施，一手針繡功夫堪稱一絕。
LONG
    );
 set("attitude", "peaceful");
 set("age", 45 );
 set("evil",-10);
 set("gender","女性");
 set("level", 1);
 set("ten_mob",1);
 setup();
}

