inherit ITEM;
inherit F_PILL;

void create()
{
        set_name("�s��", ({ "vegetable" }) );
    set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@�ʱq�s�W�ĤU���s��, �ݰ_�ӴN�ܦn�Y�C\n");
                set("unit", "��");
                set("value", 20);
                set("heal_hp",10);      //�i�H�O"heal_hp"�άO"heal_mp",
                set("heal_body",10);    //"heal_head" ,"heal_body"
                set("eat_msg","$N��s��]�F�U�h....�C");
                set("eff_msg","�A�o�{�u�O�����W��....�C");
        }
        setup();
}
