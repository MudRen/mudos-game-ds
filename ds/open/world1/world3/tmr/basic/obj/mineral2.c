inherit ITEM;

void create()
{
        set_name("���q",({ "gold mineral","mineral" }) );
        set("long",@long
�@�p������X�Ӫ����q�A�ٰ����ۨ�L�L�Ϊ��q���A�ݨӥ��g����A
�]�O�S����γB�C���q�O�{���q�����A����ᰪ���q���A�u�O�s�q�w�g��
�h�F�C
long
);
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","��");
                  set("value",200);
		set("material","gold");
		set("volume",1);
        }
        setup();
}

