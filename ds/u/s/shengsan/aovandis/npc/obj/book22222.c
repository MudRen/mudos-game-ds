// �ѥ�
inherit ITEM;

void create()
{
	set_name("�ʷR�e����",({"book22222"}) );
	set("long","�@���ѭC�C\n");
	set_weight(300);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("value",250);
		set("unit","��");
	}
	set("bookauthor","shengsan");	// �ѥ��@��
	set("bookkind",({ "all","sex","�ʷR","��","����" }));	// �ѥ�����
	set("bookno",22222);	// �ѥ����X
	setup();
}
