#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "���i�R���p��", ({ "alickyuen" }) );
        set("level",30);
           set("combat_exp",3000);
       set("evil",90);
 set("long" ,"�L�O�խߦa���ǻ����m�խߥ|���n���@���i�H���j�C\n");
        set("age",50);
       set("gender","�k��");
         set_skill("axe",60);
        set_skill("dodge",60);
               set_skill("parry",60);
        set("Merits/wit",1);
        setup();
}
void init()
{
      ::init();
        add_action("do_guard", "go");
}
int do_guard(string arg)
{

        if( (arg!= "west") || !this_player()->visible(this_object()) ) return 0;
        write( name() + "�N�A�d�F�U�ӡC\n");
        command("hehe");
        say("�q�ѹ����D�G" HIB "�p�l�i�O������!!\n" NOR);
        return 1;
}
