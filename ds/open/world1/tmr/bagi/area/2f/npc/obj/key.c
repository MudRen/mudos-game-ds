inherit ITEM;
void create()
{
        set_name("�۰�",({"rock key","key"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","�o�O�@��Υ��Y�J�����_�͡A�����i�H�}�Ҥ���C\n");
                set("door","bagi_key");
                set("value", 1);
                set("no_sell",1);
                set("usage","�}�ҬY�@����");
        }
        setup();
}

