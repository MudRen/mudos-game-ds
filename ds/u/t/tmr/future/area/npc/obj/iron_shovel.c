inherit ITEM;

void create()
{
        set_name("�K��",({"iron shovel","shovel"}) );
        set("long",@long
�o�O�@����K���y�Ӧ�����l�A�M���Ψ�½���d�g�C
long
);
        set_weight(1000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("value",100);
                set("material","iron");
                set("volume",1);
                set("unit","��");
        }
        setup();
}
