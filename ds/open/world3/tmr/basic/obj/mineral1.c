inherit ITEM;

void create()
{
        set_name("���K�q",({ "red iron mineral","mineral" }) );
        set("long",@long
�@�p������X�Ӫ����K�q�A�ٰ����ۨ�L�L�Ϊ��q���A�ݨӥ��g����A
�]�O�S����γB�C
long
);
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","��");
                set("value",100);
        }
        setup();
}

