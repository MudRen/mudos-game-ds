inherit ITEM;

void create()
{
        set_name("�~���G�U", ({ "stomach bag","bag" }) );
        set("long",@LONG
�o�O�q�~���������Ӫ��G�U�A���Y�ʫD�`���n�A�i�H�񤣤֪F��C
LONG
);
        set_weight(1200);
        set_max_capacity(100);
          set_max_encumbrance(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�f");
                set("volume",6);
                set("value",2500);
        }
        setup();
}

