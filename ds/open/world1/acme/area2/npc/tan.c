#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "侮天", ({ "wu tan","tan", "__GUARD__" }) );
        set("level",40);
           set("combat_exp",4000);
 set("long" ,
     "他是幽冥地窖傳說中《幽冥四妖》之一的【鬼王】，\n"
     "他長的橫眉豎目，十分可怕。\n",
     );
        set("age",60);
        set("evil",90);
        set("title",CYN"【鬼王】"NOR);
       set("gender","男性");
//         set_skill("darksword",70);
           set_skill("sword",80);
          set_skill("dodge",80);
           set_skill("parry",80);
              set_skill("block",60);
        setup();
        carry_object(__DIR__"wp/sword2.c")->wield();
           carry_object(__DIR__"eq/shield.c")->wear();
}
void init()
{
     ::init();
        add_action("do_guard", "go");
}

int do_guard(string arg)
{

        if( (arg!= "south") || !this_player()->visible(this_object()) ) return 0;
        write( name() + "將你攔了下來。\n");
        command("hehe");
        say("侮天說道：" HIB "小子可別亂闖啊!!\n" NOR);
        return 1;
}

