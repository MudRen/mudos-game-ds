#include <ansi.h>

inherit NPC;

void create()
{
        set_name( HIC "�u���@��" NOR , ({ "guard" }) );
        set("con", 19);
        set("age",30);
        set("str", 20);
        set_skill("sword", 60);
        set_skill("parry", 60);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set("long",
                "�@�Ӧu�@�Ъ����@�áA�ݰ_�ӤT�Q�X��\n"
                "�����٦סA�ݨӪZ���]���۷�{�סA���H\n"
                "�ݤF�����b������..�C\n");
        set("chat_chance", 5);
        set("chat_msg", ({
                "�u���@�æۨ��ۻy�a���D�G" HIG "�O�@�_�ݬO�ڪ����ͪ��d���A�ڤ@�w�|���n����!!\n" NOR,
                "�u���@�ù�ۤѤj�n���D�G" HIG "�R�B�Q�A�Ĩ�w�|���t�ҰU�A�O�@�_�ݥͥͥ@�@!!\n" NOR,
        }));
        setup();
        carry_object(__DIR__"obj/sword.c")->wield();
}
void init()
{
        add_action("do_guard", "go");
	call_out("incheck",3,this_player());
	
}
void incheck(object me)
{
	if(me->query("id")!="tmr") //�O�H�i�J
	{
	 say("�u���@�û��D�G" HIG "�_�j�H�b�W�A�p�����A�d���d���d�d��.....\n" NOR);
  	command("bow");
	
 	}else
    	  {
		say("�u���@�û��D�G" HIG "���}���}�A���n�b�o�r�d.....\n" NOR);
		command("angry");
	  }	
}

int do_guard(string arg)
{

       if( (arg!= "south") || !this_player()->visible(this_object()) ) return 0;
        write( name() + "�N�A�d�F�U�ӡC\n");
        command("hehe");
        say("�u���@�û��D�G" HIB "�p�l�i�O������!!\n" NOR);
        return 1;
}
