// �ѥ�
inherit ITEM;

void create()
{
	set_name("�s���i������",({"book12345"}) );
	set("long","�@���ѭC�C\n");
	set_weight(300);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("material","paper");
		set("unit","��");
	}
	set("bookauthor","luky");	// �ѥ��@��
	set("bookkind",({ "all","food","�s��","����","�i��","����" }));	// �ѥ�����
	set("bookno",12345);	// �ѥ����X
	setup();
	set("value",1);
}

int is_book()
{
	return 1;
}
