//arrow.c by luky
inherit ITEM;

void create()
{

set_name("��b",({"wood arrow","arrow"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long","���Y�s���}�b, �}�b���M�O��s��, ���O�y�U���b�W�٬O���H�N�����y�C\n");
        }
set("value", 20);
set_weight(250);
set("arrow/damage",22);		//���ˤO
setup();
}

