
inherit NPC;

void create()
{
	set_name("���",({ "ringman","man" }) );
	set("long",
	"�@�Ӭ�ۯ}����}�c���H�A�����ڤڪ`���۸J���u�ʪ���l�A�ݨӤE\n"
	"���O�Ӧn�䦨�ʪ��å�C\n"
	);

	set("race","�H��");
	set("gender","�k��");
	set("chat_chance",3);

	set("chat_msg",({
	"��ȳ��ۻy�a���D�G�u�A���̫�@��N�n�A�@�w�n�n�⤧�e�骺��Ĺ�^�Ӥ~��C�v\n",
	(:command("sigh"):),
	"��ȹ�۸J���|�b�u�ʪ���l�A�����a�۹D�G�u�Q�K�ա��v\n",
	}) );
	set("age",30);
	set("level",4);
        set("attitude", "heroism");  

	setup();
        add_money("coin",200);
}
