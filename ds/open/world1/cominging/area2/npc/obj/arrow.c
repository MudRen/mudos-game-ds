// arrow �b
inherit ITEM;

void create()
{

	set_name("��b",({"wood arrow","arrow"}));
	set_weight(250);
        if( clonep() )
        	set_default_object(__FILE__);
        else
        {
        	set("value", 0);
        	set("unit", "��");
        	set("long","���Y�s���}�b, �}�b���M�O��s��, ���O�y�U���b�W�٬O���H�N�����y�C\n");
        }
	set("arrow/damage", 10);         //���ˤO
	setup();
}