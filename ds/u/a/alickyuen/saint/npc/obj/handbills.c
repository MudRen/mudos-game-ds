//updated
inherit ITEM;
void create()
{
        set_name("�ǳ�", ({ "handbills" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�i");
                set("long",
                        "�@�i�Ŷǳ�i�A�W�Y���@�Ӽлx�C\n"
                        "�W���g�F�@�Ǧr�G\n"
                        "�y�U��H�h�A�����s�i�}���A�Ҧ��J�|�@�ߤE��A�S���S���C\n"
                        "�۱m�J�|�Υܡz\n");

                set("value", 0);
                  set("no_sac",1);
        }
}