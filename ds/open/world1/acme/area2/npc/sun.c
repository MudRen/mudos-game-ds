#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�Ҭ�", ({ "sun jiong","sun","jiong", "__GUARD__" }) );
      set("level",50);
          set("combat_exp",5000);
 set("long" ,
     "�L�O�խߦa���ǻ����m�խߥ|���n���@���i�ߤ��j�A\n"
     "�L���y��a�աA�����ݤ��X�߫�s�֡C\n",
     );
        set("age",70);
        set("title",CYN"�i�ߤ��j"NOR);
        set("gender","�k��");
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
        write( name() + "�N�A�d�F�U�ӡC\n");
        command("hehe");
        say("�Ҭ����D�G" HIB "�p�l�i�O������!!\n" NOR);
        return 1;
}
