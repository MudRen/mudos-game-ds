// �ѥ�
inherit ITEM;

void create()
{
	set_name("�ѪŪ����@��",({"book11111"}) );
	set("long","�o�O�@���ѡC�ѦW���u�ѪŪ����@�ݡv\n");
	set_weight(300);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("material","paper");
		set("unit","��");
	}
	set("bookauthor","shengsan");	// �ѥ��@��
	set("bookkind",({ "all","���","����" }));	// �ѥ�����
	set("bookno",11111);	// �ѥ����X
	setup();
	set("value",1);
}

int is_book()
{
	return 1;
}
