#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "伍霸剛", ({ "ba gun wu","ba","gun","wu", "__GUARD__" }) );
        set("level",20);
           set("combat_exp",2000);
        set("evil",90);
 set("long" ,"他是幽冥地窖傳說中《幽冥四妖》之一的【獸王】。\n");
        set("age",40);
        set("title",CYN"【獸王】"NOR);
        set("gender","男性");
             set_skill("sword",40);
        set_skill("dodge",40);
           set_skill("parry",40);
        setup();
        carry_object(__DIR__"wp/dog.c")->wield();
     carry_object(__DIR__"eq/gloves.c")->wear();
}
void init()
{
       ::init();
        add_action("do_guard", "go");
}

int do_guard(string arg)
{

        if( (arg!= "eastdown") || !this_player()->visible(this_object()) ) return 0;
        write( name() + "將你攔了下來。\n");
        command("hehe");
           say("伍霸剛說道："HIB"小子可別亂闖啊！！\n"NOR);
        return 1;
}
