inherit ITEM;
void create()
{
        set_name("������u", ({ "engine arm","arm" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����������γ~��������u�C\n");
                set("unit", "��");
        }
        setup();
}
