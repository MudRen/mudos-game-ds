
inherit  ITEM;
void  create()
{
        set_name("�۹�",({  "stool"  }));
        set_weight(20000);
    set("long","�o�O�i�j�z�ۻs�����l�C\n");
        if(clonep()) set_default_object(__FILE__);
        else
        {
                set("unit",  "�i");
                set("material","stone");
                set("value",  2000);
                set("no_get",  1);
                set("amount",30);
        }
        setup();
}
