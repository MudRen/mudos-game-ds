inherit ITEM;
void create()
{
        set_name("�q��",({ "mineral" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","�@���q�ۡA�ݰ_�����Z�ȿ����C\n");
                set("unit","��");
                set("value",100);
        }
        setup();
}