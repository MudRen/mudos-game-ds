inherit ITEM;
inherit F_STUDY;

void create()
{
    set_name("�������q�v", "haha book", "book");
    set_weight(1000);
    if( !clonep() ) {
        set("unit", "��");
        set("value", 5000);
        set("long",@long
�O�B�Τ娥��g�������ǡA�O��Ÿ�������u����v�Ҽ��ۡA�O���۫�
�����Ʀʦ~���������v�A�O�@�����������ǡA�����ݦ��۷������y
��y�ڤ~��Ū�o�q�C
long
);
        set("required/skill", ([
            "literate" : 110,
        ]));
        set("content", ([
            "literate" : 130
        ]));
    }
    setup();
}

