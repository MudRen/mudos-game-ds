inherit ITEM;
inherit F_STUDY;

void create()
{
    set_name("�������Ū��", "medium education book", "book");
    set_weight(1000);
    if( !clonep() ) {
        set("unit", "��");
        set("value", 200);
        set("long",@long
�o�O�@���ݩ󤤵��Ш|�{�ת���������Ӭ�Ū�����y�A���F�ǲߨ䤤
�ݤH�B�ƪ��D�z�A�]�]�A�F�󰪤@�����Ш|���ѡC
long
);
        set("required/skill", ([
            "literate" : 30,
        ]));
        set("content", ([
            "literate" : 50
        ]));
    }
    setup();
}

