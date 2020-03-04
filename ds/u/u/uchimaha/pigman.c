inherit NPC;
void create()
{
        set_name("擋路的人",({ "guard road's man", "man" }) );
        set("long","一個擋路的人。\n");
        set("race","人類");
        set("title","平凡人");
        set("age",25);
        set("level",7);
        set("attitude","friendly");
        set_skill("dodge",5);
        set_skill("unarmed",5);
        set_skill("parry",5);
        set("no_kill",1);
   setup();         
}
void init()
{
       ::init();
        add_action("do_guard", "go");
}
int do_guard(string arg)
{

        if( (arg!= "enter") || !this_player()->visible(this_object()) ) return 0;
        write( name() + "擋住了你通行的路。\n");
        command("wahaha");
        say("擋路的人說道：此路不通.....:P\n");
        return 1;
}

