inherit ITEM;

void create()
{
	set_name("�ӳ�",({"phytolacca acinosa roxb","roxb"}) );
	set_weight(80);
	set("long",@long
�ӳ����ӳ���h�~�ͯ󥻡A�L��A�ڪΫp�A�׽�A���@�ΡA�~�֧e�H
����A�C����e���ε�����C�F���ĥήڡA��V�ī��A���W�A�ʴH�A��
�r�C��v�m���B�Q���A���~
long
);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","��");
		set("value",60);
	}
	setup();
}