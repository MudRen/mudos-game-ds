#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�V��", ({ "wu tan","tan", "__GUARD__" }) );
        set("level",40);
           set("combat_exp",4000);
 set("long" ,
     "�L�O�խߦa���ǻ����m�խߥ|���n���@���i�����j�A\n"
     "�L������ܽݥءA�Q���i�ȡC\n",
     );
        set("age",60);
        set("evil",90);
        set("title",CYN"�i�����j"NOR);
       set("gender","�k��");
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
        write( name() + "�N�A�d�F�U�ӡC\n");
        command("hehe");
        say("�V�ѻ��D�G" HIB "�p�l�i�O������!!\n" NOR);
        return 1;
}

