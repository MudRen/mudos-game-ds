inherit ITEM;

void create()
{
	set_name("�K�u��",({"adiantum flabellulatum linn","linn"}) );
	set_weight(80);
	set("long",@long
�K�u���K�u����h�~�ʹӪ��A����20��50���̡C�ͩ�s���ΪL�U��
�l���a�C�ĥΥ���A���~�i�Ĭ~�b���q�ΰ��ƥΡC����H�W�A�ʷL�D�C�M
���Q�l�A׶����~�C
long
);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","��");
		set("value",50);
	}
	setup();
}