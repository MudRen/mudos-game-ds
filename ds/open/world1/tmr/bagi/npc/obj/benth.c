inherit ITEM;

void create()
{
	set_name("�ѤH��",({"millettia nitida benth","benth"}) );
	set_weight(100);
	set("long",@long
�ѤH�ڦh�ͩ�s�����L�αK�L���A���ĥ��ò��C�|�u�i�ġA���H�`��
�Ĭ��n�C����̭W�A�ʷšA�i�ɦ���A�q�g�����C�������k�������A
���K���צ�u�X��A
long
);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","��");
		set("value",80);
	}
	setup(); 
}