inherit NPC;
#include <ansi.h>
void create()
{
           set_name("揍敵客殺手",({"to di killer","killer"}));
set("long","上面掛著一怪牌子寫著『本公司從揍敵客家族企業所購之殺手！』\n");
        set("race","human");
set("age",60);
              set("level",35);
set("chat_chance",10);
        set("chat_msg",({
                                       (:command,"reload clip":)}));
                set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (:command("shoot"):),
                (:command("reload clip"):), 
 }) ); 
	setup();
carry_object(__DIR__"obj/light-clip.c");
carry_object(__DIR__"obj/light-clip.c");
carry_object(__DIR__"obj/light-gun.c")->wield();  
carry_object(__DIR__"obj/g_plate.c");
}

void init()
{
       ::init();
        add_action("do_guard", "go");
}
int do_guard(string arg)
{
        if( (arg!= "up") || !this_player()->visible(this_object()) ) return 0;
        write( name() + "將你攔了下來。\n");
      command("wahaha");
           say("揍敵客殺手說道："HIY"想走！？先問問我的槍吧！\n"NOR);
        return 1;
} 
void die()
{
message_vision("$N死前說：ㄚ∼你真厲害，跟傳說的樓主能一較高下了！",this_object()); 
            ::die();
}
