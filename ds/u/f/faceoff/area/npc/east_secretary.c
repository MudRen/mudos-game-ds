#include <ansi.h>
inherit NPC;
void create()
{
 set_name("東副師",({"secretary"}));
 set("long",@LONG
他是辛嚭的個人副師, 不過實際上管理的事物跟辛嚭也差不多了.
LONG
     );
 set("attitude","peaceful"); 
 set("age",24);
 set("gender","男性");
 set("level",8);
 setup();
 carry_object(__DIR__"eq/sea_cloth")->wear();
 carry_object(__DIR__"eq/gold_fur_boots")->wear();
}
