inherit ITEM;
void create()
{
        set_name("���A�U", ({ "travel bag","bag" }) );
        set("long", 
"���A�U�A�U�W��q�A�X�ΨӦb���~�[�A�ɡA�ΨӸ˱a���h��\n"
"�������A�񤧤@�몺�p���U�A��O�n�Φh�F�C\n"
);
          set_weight(1000);
        set_max_capacity(32);
        set_max_encumbrance(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�f");
                set("volume",5);
                set("value",500);
        }
        setup(); 
}

