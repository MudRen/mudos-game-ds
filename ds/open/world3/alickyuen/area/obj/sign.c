//updated
inherit ITEM;

void create()
{
        set_name("�q�l�i�ܵP", ({ "sign" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "�@�ӧi�ܵP�A�W�Y���ʪ��骺�ХܡC\n"
                        "�W���g�F�@�Ǧr�G�u�s�i�}��,�K�O�J���I�I�v\n");
                set("value", 1);
                set("no_get",1);
                  set("no_sac",1);
        }
}