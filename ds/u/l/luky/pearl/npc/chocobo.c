#include <ansi.h>
inherit NPC;
void create()
{
set_name(HIY"陸行鳥"NOR, ({ "chocobo" }), );
set("age",5);
set("level",10);
set("long","\n一隻H級的普通陸行鳥。強而有力的雙腳能夠毫不費力的穿越任何森林和草原。\n");
set("ridable",1);
set("ride_type","Ground");
set("chat_chance", 15);
set("chat_msg", ({
HIY"陸行鳥"NOR"["HIW"咕..咕.."NOR"]的叫了一聲。\n",
HIY"陸行鳥"NOR"靜靜用嘴巴整理著"HIY"羽毛"NOR"。\n",
HIY"陸行鳥"NOR"大大的眼睛正好奇的看著你．．．\n",
}));
setup();
}


