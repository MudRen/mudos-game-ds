inherit ITEM;
void create()
{
        set_name("���m��",({ "five-color-stone","stone" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","�o�O�@���֦������C�⪺���Y�C\n");
                set("unit","��");
                set("value",0);
        }
        setup();
}
