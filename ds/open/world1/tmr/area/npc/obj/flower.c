inherit ITEM;

void create()
{
        set_name("�]������",({"night_money flower","flower"}) );
        set_weight(200);
        set("long",
"�@������⪺��c�A�a���E���G����ä�A�e���Τ��G�A�F�F�b���A���t\n"
"���i�I�Ǫ��ҼˡA�o�S���a�X�����ߡA��O�_��@���C\n"
        );
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("value",200);
        }
        setup();
}


