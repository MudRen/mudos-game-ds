inherit ITEM;

void create()
{
        set_name("���_�U", ({ "treasure bag","bag" }) );
        set("long",@LONG
�@�ӯ��_���U�l�A�ݰ_�Ӥp�p���A�o��˫ܦh�F��C

LONG
);
        set_weight(1200);
        set_max_capacity(40);
        set_max_encumbrance(25000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�f");
                set("volume",6);
                set("value",500);
        }
        setup();
}

