inherit ITEM;
void create()
{
        set_name("�]���]", ({ "pearl" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�o�O�@�����Ŧ⪺�p�]�l�A�b�ߤW���ɫJ�|�o�X�{���C\n");
                set("unit", "��");
                set("value",100);
        }
        setup();
}

void init()
{
        if(!this_object()->query_light()) this_object()->start_light(1);
}
//copy from Acme Pearl
