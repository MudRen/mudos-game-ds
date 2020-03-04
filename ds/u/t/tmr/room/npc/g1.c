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
        set("chat_chance", 10);
        set("chat_msg", ({
                "�u���@�æۨ��ۻy�a���D�G" HIB "�O�@�_�ݬO�ڪ����ͪ��d���A�ڤ@�w�|���n�L��\n" NOR,
                "�u���@�ù�ۤѤj�n���D�G" HIB "�R�B�Q�A�Ĩ�w�|���t�ҰU�A�O�@�_�ݪ�..�C\n" NOR
        }));
        setup();
        carry_object(__DIR__"obj/sword.c")->wield();
}
void init()
{
        add_action("do_guard", "go");
}

int do_guard(string arg)
{
	
       if( (arg!= "south") || !this_player()->visible(this_object()) ) return 0;	
        write( name() + "�N�A�d�F�U�ӡC\n");
        command("hehe");
	say("�u���@�û��D�G" HIB "�p�l�i�O������!!\n" NOR);
	return 1;
}

