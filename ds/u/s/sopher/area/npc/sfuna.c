#include <ansi.h>
inherit NPC;
void create()
{
     set_name(HIY"絲"HIR"芙"HIW"娜"NOR , ({ "sfuna" }) );
        set("race", "人類");
        set("gender","女性");
        set("age", 18);
        set("long","玲瓏有致的身材，美麗的臉蛋，不禁令人引起遐思
你不禁想親他一下(kiss)。\n");
        set("con", 10);
        set("str", 10);
        set("dex", 10);
        set("level",10);
        set_skill("sword", 10);
        set_skill("parry", 50); 
        set_skill("unarmed", 10);
        set_skill("dodge", 50);
        set("chat_chance", 5 );
        set("chat_msg",({"絲芙娜說道：請問來到我的花園有什麼事嗎？!\n",
           (:command("smile"):),
        }) );
       setup();
}
void init()
{
add_action("do_kiss","kiss");
}

int do_kiss(string arg)
{
 if(arg=="sfuna")
 {
 message_vision("絲芙娜對$N害羞的笑了笑。\n",this_player());
 return 1;
 }
return 0;
}     
