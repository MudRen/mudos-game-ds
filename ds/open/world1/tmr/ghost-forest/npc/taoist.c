inherit NPC;

void create()
{
	set_name("�L�W�D�H",({"taoist"}) );
	set("long",@LONG
�@�Ө��@�D�h����Ҽ˪��H�A���o�ۤ@�ѿ@�@���s���A�ݥL�K���i��
�A���۪��D�A�ɬO�o�������A�L�̤a�۰۵ۤ����W���p�աA�@���K���O��
�s�׹D�H�C
LONG
);
	set("age",40);
	set("race","�H��");
	set("level",15);
        set("attitude", "peaceful");
        set("gender", "�k��" );
	set("chat_chance",10);
	set("chat_msg",({
	"�D�H�ĹD�G����Y���ʪ��C�u�D�s�����~�A���O���s���N���K���H�F....\n",
	(:command("lick"):),
	"�D�H�F�n��̦a���D�G�s...�s....���٭n�h�ֳܤW�L�T�ѤT�]...\n",
	}) );

	set_skill("parry",40);
	set_skill("dodge",40);
	set_skill("unarmed",40);

	setup();
	carry_object(__DIR__"obj/seal");
	carry_object(__DIR__"eq/shoe")->wear();
}

int accept_object(object who,object ob)
{
        object seal;
        seal=new(__DIR__"obj/seal");

        if(ob->name()!="�ʪ��C")
	{
		command("say �x�I�A���ڳo�Ӱ�ԣ�H");	
        	return 0;
	}
        else {
		command("say �o�i���O����Y���u�ʪ��C�v��...");
		command("lick");
		command("say �i�u�O���§A�F�A�o�i�ũG�N�e�A�a�C");
		seal->move(who);
		destruct(ob);
	        return 1;
        }

}

