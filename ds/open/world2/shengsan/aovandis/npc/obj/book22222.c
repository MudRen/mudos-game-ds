// �ѥ�
inherit ITEM;

void create()
{
	set_name("�ʷR�e����",({"book22222"}) );
	set("long","�@������ѥZ�C�C\n");
	set_weight(300);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("material","paper");
		set("unit","��");
	}
	set("bookauthor","shengsan");	// �ѥ��@��
	set("bookkind",({ "all","sex","�ʷR","��","����" }));	// �ѥ�����
	set("bookno",22222);	// �ѥ����X
	setup();
	set("value",1);
}

int is_book()
{
	return 1;
}
