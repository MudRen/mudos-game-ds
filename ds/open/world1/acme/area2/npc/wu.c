#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "���Q��", ({ "ba gun wu","ba","gun","wu", "__GUARD__" }) );
        set("level",20);
           set("combat_exp",2000);
        set("evil",90);
 set("long" ,"�L�O�խߦa���ǻ����m�խߥ|���n���@���i�~���j�C\n");
        set("age",40);
        set("title",CYN"�i�~���j"NOR);
        set("gender","�k��");
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
        write( name() + "�N�A�d�F�U�ӡC\n");
        command("hehe");
           say("���Q�軡�D�G"HIB"�p�l�i�O�����ڡI�I\n"NOR);
        return 1;
}
