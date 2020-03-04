#include <ansi.h>
inherit NPC;
void create()
{
 set_name("市井無賴",({"vagabond",}));
 set("long",@LONG
一個處處可見的市井無賴, 但他獐頭鼠目的樣子讓你看了尤
其討厭.
LONG
    );
 set("attitude", "peaceful");
 set("age",41);
 set("gender","男性");
 set("level",20);
 set("chat_chance",10);

set("chat_msg", ({"市井無賴壓低聲音道:哪天把林老頭的 "+HIY+"寶貝"+NOR+" 給摸來!!. \n",
	           	  "市井無賴發現你在看他, 惡狠狠的朝你瞪了一眼.. \n",
}));
 set("chat_chance_combat",200);
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
 carry_object(__DIR__"eq/longsword")->wield();
}
void init()
{
       add_action("typepush","push");
}
     int typepush(string arg)
{
        object me;
        me=this_player();
        if(arg != "牆壁") return 0;
        message_vision("工人閃身遮在$N面前!!\n\n",me);
        message_vision("工人很勉強的笑著說: 小兄弟, 咱們要做工呢...!\n\n",me);
        return 1;
}




