#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "觴炯", ({ "sun jiong","sun","jiong", "__GUARD__" }) );
      set("level",50);
          set("combat_exp",5000);
 set("long" ,
     "他是幽冥地窖傳說中《幽冥四妖》之一的【冥王】，\n"
     "他的臉色蒼白，完全看不出喜怒哀樂。\n",
     );
        set("age",70);
        set("title",CYN"【冥王】"NOR);
        set("gender","男性");
       set("evil",90);
           set_skill("unarmed",100);
           set_skill("dodge",100);
           set_skill("parry",100);
        set("Merits/wit",2);
        set("int",30);
        setup();
		carry_object(__DIR__"wp/ghostpike")->wield();
		carry_object(__DIR__"eq/ghostmask")->wear();
		carry_object(__DIR__"eq/ghostcloak")->wear();
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
        say("觴炯說道：" HIB "小子可別亂闖啊!!\n" NOR);
        return 1;
}
