#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "保安", ({ "bo officer","bo","officer" }) );
        set("level",30);
        set_skill("dodge",55);
        set_skill("parry",70);
        set_skill("sword",68);
        set("long" ,"N.Y.T.一星級上將。\n");
        set("age",45);
        set("title",HIY"N.Y.T.上將"NOR);
        set("chat_chance", 8);
        set("chat_msg", ({
                         "保安大聲喊著:閒雜人等請勿見出。\n",
        }) );
        setup();
        carry_object("/u/b/basic/wp/sword1")->wield();
        
}

