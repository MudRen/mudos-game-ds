inherit ITEM;
void create()
{
        set_name("�h��", ({ "silk shawl","shawl" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�o�O�@����a���������S�A�W�Y¸�ۤ@���p�m�A�B�b�Ǽg�F�Ʀ�r�C\n");
                set("unit", "��");
           set("value",100);
        }
     setup();
}
