inherit ITEM;
void create()
{
        set_name("�ݯ}���i�ܵP", ({ "sign" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "�@�ӥΤ�O�s�����i�ܵP�A������b�o���h�[�F�A���g���j�B���A�w��o\n"
                      
                        "�ݯ}�����C�W���٨̵}��ݨ�@�Ǧr�G�u��....�L�A��..�Ū�A�p�J����\n"
                         
                        "....���A��Y..���E..�A..�O..�R�A��....�O�I�I�v\n");
         set("no_get",1);
        set("no_sac",1);
        }
     setup();
}
