inherit ITEM;

void create()
{
    set_name("�q�Ѧʬ����", ({"encyclopaedia book", "book"}));
    set_weight(1000);
	set("long",@long
�o�O�@���p�F�d�����j���Y�ѡA�ԲӰO���o�ӥ@�ɤW���򥻪��ѡA��
�M�����㦳���������ѡA�~�৹���F�Ѧ��Ѫ����e�C
long
	);
		if ( clonep() )
  			 set_default_object(__FILE__);
  		else {
	        set("unit", "��");
	        set("value", 100);	
	    }
    setup();
}

