// �i�v�L�����x(�ƻs�~)
inherit ITEM;

void create()
{
	set_name("�ڤ۶g�Z(�ƻs)",({"dream magazine","magazine","dream"}) );
	set("long",@LONG
�ڤ۶g�Z�ڤ۶g�Z			�ڤ۶g�Z		��
�ڤ۶g�Z	�ڤ۶g�Z	�ڤ۶g�Z	�ڤ۶g�Z
�ڤ۶g�Z	�ڤ۶g�Z	�ڤ۶g�Z	�ڤ۶g�Z
�ڤ۶g�Z	�ڤ۶g�Z	�ڤ۶g�Z
�ڤ۶g�Z	�ڤ۶g�Z		�ڤ۶g�Z
�ڤ۶g�Z	�ڤ۶g�Z			�ڤ۶g�Z
�ڤ۶g�Z	�ڤ۶g�Z	�ڤ۶g�Z	�ڤ۶g�Z
�ڤ۶g�Z	�ڤ۶g�Z	�ڤ۶g�Z	�ڤ۶g�Z
�ڤ۶g�Z�ڤ۶g�Z			�ڤ۶g�Z
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
