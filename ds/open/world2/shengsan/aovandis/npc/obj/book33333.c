// �ѥ�
inherit ITEM;

void create()
{
	set_name("�ڴ��g�ܬӥ������R�۩p",({"book33333"}) );
	set("long","�@���ѭC�C\n");
	set_weight(300);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("material","paper");
		set("unit","��");
	}
	set("bookauthor","shengsan");	// �ѥ��@��
	set("bookkind", ({ "all","���","����" }));	// �ѥ�����
	set("bookno",33333);	// �ѥ����X
	setup();
	set("value",1);
}

int is_book()
{
	return 1;
}
