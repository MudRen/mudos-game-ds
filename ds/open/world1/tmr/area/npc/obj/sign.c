// sign.c  AM 02:40 1999/2/20

inherit ITEM;

void create()
{
        set_name("�}�H���i�ܵP", ({ "sign" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "�@�ӥΤ�O�s�����i�ܵP�A������b�o���h�[�F�A���g���j�B���A�w\n"
                        "�ݯ}�����C�W���٨̵}��ݨ�@�Ǧr�G�u��....�L�A��..�Ū�A�p�J��\n"
                        "....���A��Y..���E..�A..�O..�R�A��....�O�I�I�v\n");
                set("value", 1);
                set("no_get",1);
                  set("no_sac",1);
        }
}
