inherit NPC;
void create()
{
        set_name("�׸����H",({ "guard road's man", "man" }) );
        set("long","�@�Ӿ׸����H�C\n");
        set("race","�H��");
        set("title","���Z�H");
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
        write( name() + "�צ�F�A�q�檺���C\n");
        command("wahaha");
        say("�׸����H���D�G�������q.....:P\n");
        return 1;
}

