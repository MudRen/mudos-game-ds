// letter.c

inherit ITEM;

void create()
{
        set_name("�H", ({"long letter", "letter", "letter", "_GUMU_LONG_LETTER_"}));
        set_weight(100);
        set("value",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","�o�O�@�ʷ��L���p�s�k���ѫH�C\n");
                set("material", "paper");
        }
}
