inherit ITEM;
void create()
{
        set_name("���Z�O�P", ({ "plate" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@�ӥΨӿ�O�������O�P�A�W�Y��۩��g�K���ϡC\n");
                set("unit", "��");
        }
     setup();
}
