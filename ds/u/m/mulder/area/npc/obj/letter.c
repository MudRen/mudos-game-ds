inherit ITEM;
void create()
{
        set_name("��H", ({ "letter" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�o�O�@�ʬV���A�媺�H�C\n");
                set("unit", "��");
                set("value",100);
}
        
              setup();
}

