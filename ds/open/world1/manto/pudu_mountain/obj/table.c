
inherit  ITEM;
void  create()
{
        set_name("�ۮ�",({"table"}));
        set_weight(200000);
set("long","�ۮध�W�A�a�����۹D�D�����A�a����`�L���P�A�o�ѬO������A�L�@���餣���C\n");
        if(clonep()) set_default_object(__FILE__);
        else
        {
                set("unit",  "�i");
                set("material",  "stone");
                set("value",  2000);
                set("no_get",  1);
                set("amount",30);
        }
        setup();
}

