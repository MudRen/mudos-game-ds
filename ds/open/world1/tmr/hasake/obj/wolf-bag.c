inherit ITEM;
void create()
{
        set_name("�T�ֳU", ({ "wolf bag","bag" }) );
        set("long", @LONG
�o�O�@�f�T�ֳU�A�O���ħJ�����ϥξ���ǯT�ְ����A�b�̭�
��ż��������A�Ʀܥi�H��W�n�X�ѡA�]���|���a�C
LONG
);
        set_weight(800);
        set_max_capacity(40);
        set_max_encumbrance(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�f");
                set("volume",5);
                set("value", 1000);
        }
        setup(); 
}


