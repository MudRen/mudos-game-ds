#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "通天徹", ({ "tian che tung","tung","che","tian", "__GUARD__" }) );
        set("level",30);
           set("combat_exp",3000);
       set("evil",90);
 set("long" ,"他是幽冥地窖傳說中《幽冥四妖》之一的【人王】。\n");
        set("age",50);
        set("title",CYN"【人王】"NOR);
       set("gender","男性");
         set_skill("axe",60);
        set_skill("dodge",60);
               set_skill("parry",60);
        set("Merits/wit",1);
        setup();
     carry_object(__DIR__"wp/axe.c")->wield();
       carry_object(__DIR__"eq/waist.c")->wear();
}
void init()
{
      ::init();
        add_action("do_guard", "go");
}
int do_guard(string arg)
{

        if( (arg!= "west") || !this_player()->visible(this_object()) ) return 0;
        write( name() + "將你攔了下來。\n");
        command("hehe");
        say("通天徹說道：" HIB "小子可別亂闖啊!!\n" NOR);
        return 1;
}
