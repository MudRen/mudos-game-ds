//updated
inherit ITEM;
void create()
{
        set_name("�ʪ���J����", ({ "ticket" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�i");
                set("long",
                        "�@�i�J�����A�W�Y���ʪ��骺�ХܡC\n"
                        "�W���g�F�@�Ǧr�G�u�s�i�}��,�K�O�J���I�I�v\n"
                        "�ݨӧA�O�����l���F�F��...... \n");
                set("value", 50);
                  set("no_sac",1);
        }
}