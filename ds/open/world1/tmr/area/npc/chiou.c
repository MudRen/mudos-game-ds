#include <ansi.h>

inherit NPC;

void create()
{
        set_name("���", ({ "chiou-shian","chiou","shian" }) );
        set("nickname", "����");
        set("gender", "�k��" );
	set("long",
"�@�Ӧ~�O�C�Q���ѭ�A�ͥ��Ŧn���تG�A�Y���V�o�ز���A�N�O�B\n"
"�۬��_�A�]�S�������w�ߡCť���L�D�u�Ʊ��s���v�Ʋ��D�����ˡA�u\n"
"�O���F�ت�A��L�Ƴ���J�F�C\n"
 	);	
        set("score", 15000);
        set("con", 19);
        set("str", 21);
        set("int", 20);
        set("age",63);
        set("level",15);
        set_skill("parry", 60);
        set_skill("unarmed", 60);

        set("chat_chance", 2);
        set("chat_msg", ({
		"������n�u�D�G�¤Ѵ�`���s�ѡA���ۺ��q�Y�Ľ�........\n"
		"������n�u�D�G�p�p�T�Ϊ�U�ءA�D�H�����v.......\n\n"
		"������n�۹D�G����餼�����A�馨��W�ʪ��A...........\n"
		"������n�۹D�G��}�C��ݤ����A���R�ݶ餣�֯v...........\n\n"
        }));

        set("inquiry", ([
         "��": "������..�Ѥҥͥ��̷R�N�O�ت�B���B����B�D��A�̫�H�a�k�K�馷�I\n",
        ]) );

        set("chat_chance_combat", 50 );        
	set("chat_msg_combat", ({
                "����s�D�R���H���T���H���T\n",
                (: command, "surrender" :),
         }) );
  
	setup();
          carry_object(__DIR__"wp/wolf-fist");
            carry_object(__DIR__"obj/wine");
          add_money("silver",3);
}

int accept_object(object who, object ob)
{
	object wine;
        if( ob->query("name") != "�]������" )	return 0;
	command("wa");		
	command("say �����o�ئѤҨS���ݹL���_��I�I�I");
	command("tsk");		
	command("say �u�O���ѤҤj�}���ɡA�o�U�ʪ��C�N�e�A�H����·N�F�C");
	wine=new(__DIR__"obj/wine");
	wine->move(who);
	destruct(ob);
	return 1;		
}
