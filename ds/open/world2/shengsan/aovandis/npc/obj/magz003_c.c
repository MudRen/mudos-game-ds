// �i�v�L�����x(�ƻs�~)
inherit ITEM;

void create()
{
	set_name("�R���C��S�ХZ��(�ƻs)",({"love magzine","magzine","love"}) );
	set("long",@LONG

  ���i�����i��  ���i�����i��  ���i�����i��  ���i�����i��  ���i�����i��
  �i�i�i�i�i�i  �i�i�i�i�i�i  �i�i�i�i�i�i  �i�i�i�i�i�i  �i�i�i�i�i�i
  ���i�i�i�i��  ���i�i�i�i��  ���i�i�i�i��  ���i�i�i�i��  ���i�i�i�i��
    ���i�i��      ���i�i��      ���i�i��      ���i�i��      ���i�i��  
      ����          ����          ����          ����          ����    

	���⪺������ �Ŧ⪺��ù�� ���ڭ̱��i�R�����x���z1�ѩ�2��
	��o�ʫH�e��8�ӤH�H�W�A�A�߷R���H�|�Ӭ��A!
	�e��12�ӤH�H�W�A�A�߷R���H�|�k�A!
	�e��16�ӤH�H�W�A�A�߷R�|�R�W�A!
	�e��100�ӤH�H�W�A�A�߷R���H�|�|�ܧA�k(�k)�B��
LONG
	);
	set_weight(300);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("value",1);
		set("unit","��");
	}

	setup();
}

int can_copy()
{
	return 1;
}

int is_magzine()
{
	return 1;
}

int is_copy()
{
	return 1;
}
