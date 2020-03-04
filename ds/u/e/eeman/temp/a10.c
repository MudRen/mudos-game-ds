#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short",HIC"������"NOR);
        set("long", "�j�Ѫ��󴺡A�Ӥj���ۿj�A�o���������j�@���ڬw����D�R����
�j�N�s�M���ҼˡC��ƪ����}���F�Z�����K���A�a�U�E�ۥ���ᰵ
���a��A�b�𩳤U���۴X�ﱡ�Q�b�ͱ��A�]���a�H�@�_�ӽ��媺�A�@
�T���R���Ϯ���{�b�A�����e�C�_�����ۥ@�ɵۦW���Z�K�F�[�}���Z
���ΡC
");
        set("exits",([
        "east":__DIR__"a06",
//      "north":__DIR__"a11",
        ]));
        set("outdoor",1);
        set("objects",([
        __DIR__"npc/thief1":1,
        ]));
        set("light",1);
        setup();
}

void init()
{
        call_out("war_check",30);
}

void war_check()
{
        object ob;
        ob=this_object();
        remove_call_out("war_check"); //luky
        if(ob->query("war"))
        {
        ob->set("war",0);
        shout("\n\n\n"
        +HIW"               ���b���~���s��ݨ��檺�H��\n\n"NOR
        +HIR"               �o�{�e�h�⭷�����l�Q�H���ͦb��W\n\n"NOR
        +HIW"               �s�魺����㪺�U�O��~����\n\n"NOR);
        new(__DIR__"npc/thief.c")->move(__DIR__"a06");
        new(__DIR__"npc/thief.c")->move(__DIR__"a06");
        ob->set("WarStart",1);
        call_out("war_report",30);
	}
	else call_out("war_check",30);
}

void war_report()
{
        object obj,ob,where;
        remove_call_out("war_report"); //luky
        if( this_object()->query("time") > 1 )	// >1 ��30���ˤl.....
	{					//�p�G�n��[�N�ˤj���Ʀr
		this_object()->set("time",0);
                this_object()->set("WarStart",0);

		for(int i=0;i<5;i++)	//�o�̷̨Ӧ�war�|�ۥX�h��mob�өw
		{			//���X��mob�X�{,i�N�p��h�ְ�mob
		        ob=find_living("lanka thief");
			if(ob)
				destruct(ob);
		}

                shout("\n\n"
                +HIM"               ���d�����s��]���F\n\n"NOR);
		return;
	}

        if(this_object()->query("WarStart"))
        {
        	obj=find_living("lanka thief");
        	where=environment(obj);
        	if(!where)
                {
                	shout("\n\n"
                	+HIM"               ���d�����s��Q�j�a�P�ߨ�O���F\n\n"NOR);
                	this_object()->set("WarStart",0);
                }
                else
                {
                	this_object()->add("time",1);
                	call_out("war_report",30);
                }
        }
}

